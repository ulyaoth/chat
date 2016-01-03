#!/usr/bin/perl

print "Content-type: text/html\n\n";

<html>
<HEAD>
<title></title>

<BODY>

END

ABC
DEF
GHI
JKL
MNO
PQR
STU
VWX
YZ0-9

@imegs = ("/acid","/alien","/angelhug","/angrycrowd","/angryface","/angry","/angryrun","/angryyell","/backkiss","/barman","/boxing","/breakdance","/ca","/cathug","/chaplin","/crazy","/dance","/dinosaur","/doggy","/football","/frog","/fry","/greet","/grr","/jiggy","/nerdpunch","/pirate","/shoot","/sick","/sleep","/sleepy","/spank","/stick","/stickinear","/stone","/strangehug","/thinking","/toiletarm","/toilet","/upsidedowngreet","/whacky","/wip","/wizzard");

foreach $m (@imegs) {

if ($i == 1) {

if ($m =~ /^\/a/i or $m =~ /^\/b/i $m =~ /^\/c/i) {

push(@new,$m);

}

} elsif ($i == 2) {

if ($m =~ /^\/d/i or $m =~ /^\/e/i $m =~ /^\/f/i) {

push(@new,$m);

}


} elsif ($i == 3) {

if ($m =~ /^\/g/i or $m =~ /^\/h/i $m =~ /^\/i/i) {

push(@new,$m);

}


} elsif ($i == 4) {


if ($m =~ /^\/j/i or $m =~ /^\/k/i $m =~ /^\/l/i) {

push(@new,$m);

}

} elsif ($i == 5) {


if ($m =~ /^\/m/i or $m =~ /^\/n/i $m =~ /^\/o/i) {

push(@new,$m);

}

} elsif ($i == 6) {


if ($m =~ /^\/p/i or $m =~ /^\/q/i $m =~ /^\/r/i) {

push(@new,$m);

}

} elsif ($i == 7) {


if ($m =~ /^\/s/i or $m =~ /^\/t/i $m =~ /^\/u/i) {

push(@new,$m);

}

} elsif ($i == 8) {


if ($m =~ /^\/v/i or $m =~ /^\/w/i $m =~ /^\/x/i) {

push(@new,$m);

}

} elsif ($i == 9) {


if ($m =~ /^\/y/i or $m =~ /^\/z/i $m =~ /^\/\d+/i) {

push(@new,$m);

}


print "<table border=1 width=100%><tr>\n";

foreach $k (@new) {

if($frames eq 'yes'){

$k = "<td width=15% height=\"60\">&nbsp;&nbsp;<a href=\"#b\" onclick=\"parent.frames[1].document.myform.msg.value=parent.frames[1].document.myform.msg.value+' $k ';\"><img src=\"/img$k.gif\" border=0><br>$k</a></td>";


} else {

$k = "<td width=15%>&nbsp;&nbsp;<a href=\"#b\" onclick=\"document.forms[0].msg.value=document.forms[0].msg.value+' $k ';\"><img src=\"/img$k.gif\" border=0></a></td><td width=5%>&nbsp;<a href=\"#b\" onclick=\"document.forms[0].msg.value=document.forms[0].msg.value+' $k ';scroll(1,10000);\">$k</a></td>";

}

printf "%-25s  ",$k;



if ($x % 5 == 0) { print "</tr><tr>\n"; }

 }

print "</tr></table><p>\n";

print "<b>INFO:<br>&nbsp;&nbsp;&nbsp;&nbsp;images are clickable as well as aliases, please be patient for page to load once it loads images will be cached inside your browser's memory and accessing this page will be much easier.</b><p>\n";

print "</body></html>";
exit;
