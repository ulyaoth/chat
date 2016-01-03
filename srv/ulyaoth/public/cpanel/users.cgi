#!/usr/bin/perl

print "Content-type: text/html\n\n";

print "<pre>\n\n";

opendir(USERDIR,"/opt/ulyaoth/online/users/");

$c = 0;

foreach $user (sort(grep !/^\./, readdir USERDIR)) {

$user =~ s/.db//;

dbmopen(%USER,"/opt/ulyaoth/online/users/$user",0777);

$nik = $USER{'nick'};

$nik =~ s/>(.*)<\/A>//ig;      

printf "        <b>%-15s</b> %-17s %-20s %-10s\n",$1, $USER{'ip'},$USER{'room'},$USER{'mode'}; 
       

dbmclose(%USER);

$c++;
}
 print "\n</pre>\n\n";
print "there are total of <b>$c</b> users online.<p>\n";
