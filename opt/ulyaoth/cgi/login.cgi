#!/usr/bin/perl

require "$root/cgi/idle.cgi";

if($DATA{'n'} eq "" or length($DATA{'n'}) > 15 or $DATA{'n'} =~ /\./){

$loginerror = "";

member_login();

exit;

}


if($DATA{'id'}){


$loginerror = "*** IP relogin ($ENV{'REMOTE_ADDR'}). Please wait...";

$r = 1;

member_login();

exit;
}




opendir(RD, "$root/ops/ops/");

@files = readdir (RD);

      closedir(RD);

    foreach $entry (sort @files) {


        if ($entry ne '.' && $entry ne '..') {

                $entry =~ s/.db//;

               
if($DATA{'n'} =~ /$entry/i && $DATA{'n'} ne $entry && length($DATA{'n'}) == length($entry) && !-e "$root/ops/ops/$DATA{'n'}.db"){

$loginerror = "*** Sorry the nickname ! <b>$DATA{'n'}</b> or the password is not correct, please retype your nick and password and try to login again!";

member_login();

exit;


} 

}
}


#####################


opendir(RAD, "$root/online/users/");

@f = readdir (RAD);

closedir(RAD);

    foreach $en (sort @f) {


        if ($en ne '.' && $en ne '..') {

                $en =~ s/.db//;

               
if (($DATA{'n'} =~ /^$en$/i) && (!-e "$root/ops/ops/$DATA{'n'}")) {

$loginerror = "*** Sorry, nickname <b>$DATA{'n'}</b> is already in use, please choose another.";

member_login();

exit;


} 

}
}



#if (-e "$root/online/users/$DATA{'n'}.db" && !-e "$root/ops/ops/$DATA{'n'}.db") {

#$loginerror = "$nam = $tmp , $DATA{'n'} = $name  *** Sorry, nickname <b>$DATA{'n'}</b> is already in use, please choose another.";

#member_login();
#exit;
#}

#if(-e "$root/online/users/$DATA{'n'}.db" && !-e "$root/ops/ops/$DATA{'n'}.db"){
#$loginerror = "*** Sorry, nickname <b>$DATA{'n'}</b> is already in use, please choose another.";
#member_login();
#exit;
#}


if(!-e "$root/ops/ops/$DATA{'n'}.db"){

require "$root/inc/loginuser.inc";

}elsif(-e "$root/ops/ops/$DATA{'n'}.db"){

require "$root/inc/loginops.inc";

}


if($DATA{'frames'} eq 'yes'){

$frames = "yes";

print "<HTML>\n";

print "<HEAD><title>$title</TITLE></HEAD>\n";

print "<FRAMESET ROWS=\"*,90\">\n";

print "<FRAME SRC=\"$location?n=$DATA{'n'}&room=$DATA{'room'}&id=$id#b\" name=\"display\" MARGINWIDTH=\"0\" MARGINHEIGHT=\"0\" FRAMEBORDER=\"NO\">\n";

print "<FRAME SRC=\"$location?n=$DATA{'n'}&room=$DATA{'room'}&id=$id&msg=/bottom\" name=\"message\" SCROLLING=\"no\" BORDERCOLOR=\"0000FF\" MARGINWIDTH=\"0\" MARGINHEIGHT=\"0\">\n";

print "</FRAMESET>\n\n</BODY>\n</HTML>\n";      

exit;


}else{


$room = $DATA{'room'};

$frames = "";

require "$root/inc/print_ann.inc";

exit;

}
