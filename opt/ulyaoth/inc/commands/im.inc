#!/usr/bin/perl

print "Content-type: text/html\n\n";

print <<END;

<html>
<title>Chat Images</title>
<head>
<style type="text/css">

body {
	background-color: #E5E5E5;
	scrollbar-face-color: #DEE3E7;
	scrollbar-highlight-color: #FFFFFF;
	scrollbar-shadow-color: #DEE3E7;
	scrollbar-3dlight-color: #D1D7DC;
	scrollbar-arrow-color:  #006699;
	scrollbar-track-color: #EFEFEF;
	scrollbar-darkshadow-color: #98AAB1;
}

/* General font families for common tags */

font,th,td,p { font-family: Verdana, Arial, Helvetica, sans-serif }

a:link,a:active,a:visited { color : #006699; }

a:hover		{ text-decoration: underline; color : #DD6900; }
</style>

<script language="javascript" type="text/javascript">
<!--
function emoticon(text) {
	text = ' ' + text + ' ';
	if (opener.document.forms[0].msg.createTextRange && opener.document.forms[0].msg.caretPos) {
		var caretPos = opener.document.forms[0].msg.caretPos;
		caretPos.text = caretPos.text.charAt(caretPos.text.length - 1) == ' ' ? text + ' ' : text;
		opener.document.forms[0].msg.focus();
	} else {
	opener.document.forms[0].msg.value  += text;
	opener.document.forms[0].msg.focus();
	}
}


</script>
</head>
<body>

END

@imegs = ("/acid","/alien","/angelhug","/angrycrowd","/angryface","/angry","/angryrun","/angryyell","/backkiss","/barman","/boxing","/breakdance","/ca","/cathug","/chaplin","/crazy","/dance","/dinosaur","/doggy","/football","/frog","/fry","/greet","/grr","/jiggy","/nerdpunch","/pirate","/shoot","/sick","/sleep","/sleepy","/spank","/stick","/stickinear","/stone","/strangehug","/thinking","/toiletarm","/toilet","/upsidedowngreet","/whacky","/wip","/wizzard");

@msg = split(/\s+/,$DATA{'msg'});

$i = $msg[1];

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

$k = "<td width=20% height=\"60\" align=\"center\">&nbsp;&nbsp;<a href=\"javascript:emoticon(' $k ')\"><img src=\"/img$k.gif\" border=0><br>$k</a></td>";

} else {

$k = "<td width=20% height=\"60\" align=\"center\">&nbsp;&nbsp;<a href=\"javascript:emoticon(' $k ')\"><img src=\"/img$k.gif\" border=0><br>$k</a></td>";

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
print "<a href=\"chat.cgi?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=\/im+$x\">$two[$x]</a> | ";

}
$x++;
}

print "</body></html>";
exit;
