#!/usr/bin/perl

@words = split(/\s+/,$DATA{'msg'});

open(RO,">>$root/online/rooms/$room.txt");

flock(RO,2);

print RO "<!--servermsg--> *** Signout <B>$DATA{'n'}</B><font size=\"1\" color=\"$iback\">i</font> ($ip).";

 
if ($level >= 1 && @words[1] ne "" && @words[1] ne " "){


open(BANLOG,">>$banlogs");

print BANLOG "*** Signout $DATA{'n'} ($ip).(";


print RO "(";

$it = 0;

foreach $word (@words){

$word =~ s/\/quit//g;

print BANLOG "$word ";
print RO "$word ";

}

print RO ").<br>\n";

print BANLOG "). Time: $fulltime\n";

close(BANLOG);
        close(RO);

}else{

print RO "<br>\n";

close(RO);

}



content_type();

require "$root/inc/print_header.inc";

require "$root/inc/print_room.inc";

print "<hr>\n\n";


member_login();


$kill_user = $DATA{'n'};


kill_user();

undef $kill_user;

exit;