#!/usr/bin/perl

print "Content-type: text/html\n\n";

#require "$root/inc/print_header.inc";

if($frames eq "yes") {

print <<END;
<html>
<HEAD>
<title></title>

<SCRIPT LANGUAGE="JavaScript"><!-- hide

function m(n) {

parent.frames[1].document.myform.msg.value='m '+n+' ';

}
// --></SCRIPT></HEAD>
<BODY onload="top.frames[0].scroll(1,10000);">


END

} else {
print <<END;
<html>
<HEAD>
<title></title>
<SCRIPT LANGUAGE="JavaScript"><!-- hide

function m(n) {

document.forms[0].msg.value='m '+n+' ';

}


// --></SCRIPT></HEAD>

<BODY onload="document.forms[0].msg.focus();">

<FORM METHOD="POST" NAME="msg" ACTION="bin.cgi#b">
END

}

@imegs = ("/acid","/alien","/angelhug","/angrycrowd","/angryface","/angry","/angryrun","/angryyell","/backkiss","/barman","/boxing","/breakdance","/ca","/cathug","/chaplin","/crazy","/dance","/dinosaur","/doggy","/football","/frog","/fry","/greet","/grr","/jiggy","/nerdpunch","/pirate","/shoot","/sick","/sleep","/sleepy","/spank","/stick","/stickinear","/stone","/strangehug","/thinking","/toiletarm","/toilet","/upsidedowngreet","/whacky","/wip","/wizzard");

@msg = split(/\s+/,$DATA{'msg'});

$i = $msg[1];

if (!$i) { $i = 1; }

if ($i == 1) {

$one = "\/a|^\/b|^\/c";

} elsif ($i == 2) {

$one = "\/d|^\/e|^\/f";

$two = "D-E-F";

} elsif ($i == 3) {

$one = "\/g|^\/h|^\/i";

} elsif ($i == 4) {

$one = "\/j|^\/k|^\/l";

} elsif ($i == 5) {

$one = "\/m|^\/n|^\/o";

} elsif ($i == 6) {

$one = "\/p|^\/q|^\/r";

} elsif ($i == 7) {

$one = "\/s|^\/t|^\/u";

} elsif ($i == 8) {

$one = "\/v|^\/w|^\/x";

} elsif ($i == 9) {

$one = "\/y|^\/z|^\/0|^\/1|^\/2|^\/3|^\/4|^\/5|^\/6|^\/7|^\/8|^\/9";

} else {

print "<b>invalid page number, printing all images.</b>";

}


$two[1] = "A-B-C";
$two[2] = "D-E-F";
$two[3] = "G-H-I";
$two[4] = "J-K-L";
$two[5] = "M-N-O";
$two[6] = "P-Q-R";
$two[7] = "S-T-U";
$two[8] = "V-W-X";
$two[9] = "Y-Z-0-9";


foreach $m (@imegs) {

#if ($m =~ /^$one/i or $m =~ /^$two/i or $m =~ /^$three/i) {

if ($m =~ /^$one/i) {


push(@new,$m);

  }
}

$x = 0;
print "<table border=1 width=100%><tr>\n";

foreach $k (sort @new) {

if($frames eq 'yes'){

$k = "<td width=20% height=\"60\" align=\"center\">&nbsp;&nbsp;<a href=\"#b\" onclick=\"parent.frames[1].document.myform.msg.value=parent.frames[1].document.myform.msg.value+' $k ';\"><img src=\"/img$k.gif\" border=0><br>$k</a></td>";

} else {

$k = "<td width=20% height=\"60\" align=\"center\">&nbsp;&nbsp;<a href=\"#b\" onclick=\"document.forms[0].msg.value=document.forms[0].msg.value+' $k ';\"><img src=\"/img$k.gif\" border=0><br>$k</a></td>";

#$k = "<td width=15%>&nbsp;&nbsp;<a href=\"#b\" onclick=\"document.forms[0].msg.value=document.forms[0].msg.value+' $k ';\"><img src=\"/img$k.gif\" border=0></a></td><td width=5%>&nbsp;<a href=\"#b\" onclick=\"document.forms[0].msg.value=document.forms[0].msg.value+' $k ';scroll(1,10000);\">$k</a></td>";

}

printf "%-25s  ",$k;

$x++;

if ($x % 5 == 0) { print "</tr><tr>\n"; }


 }

print "</tr></table><p>\n";

$x = 1;

while ($x <= 9) {

if ($x eq $i) {
print $two[$x] . " | ";
} else {
print "<a href=\"bin.cgi?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=\/images+$x\">$two[$x]</a> | ";

}
$x++;
}

print "<p><b>INFO:<br>&nbsp;&nbsp;&nbsp;&nbsp;images are clickable as well as aliases, please be patient for page to load once it loads images will be cached inside your browser's memory and accessing this page will be much easier.</b><p>\n";

require "$root/inc/check_pm.inc";
require "$root/inc/print_footer.inc";
exit;
