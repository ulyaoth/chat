#!/usr/bin/perl  
 
$root = '/opt/ulyaoth';

$firstroom = "Ulyaoth";  


 

@my_rooms = ("Repository","Tutorials");


$sendmail = "/usr/lib/sendmail";



@rooms = sort(@my_rooms);  

@rooms = ("Ulyaoth",@rooms);  

$entrytitle = "Ulyaoth Chat - please login";  

$title = "Ulyaoth Chat";

$webmaster = "webmaster\@ulyaoth.net";

$version = ".:: Ulyaoth Chat 1.0 ::.";  

$location = 'chat.cgi';

$msg_time = "200";  

$kicktime = "600";  

$bantime = "7200"; 

 ############## RANKS ####################  

$max_ops_rank = "100";  

$comm_rank = "120";  

$max_comm_rank = "170";  

$staff_rank = "180";  

$max_staff_rank = "190";  

$admin_rank = "200";  

########################################  

$idle = "700";  

$lines = "50"; 

$onload = "onLoad=\"window.status='$version';\"";  

@cmds = ("/im","/delacc","/clean","/expired","/rooms","/sban","/ncolor","/nfont","/font","/mute","/stats","/ips","/chk","/voting","/intro","/email2","/email","/ublock","/friends","/friends2","/auto","/vote","/box","//smiles","//brb","//bye","//chat","//cry","//fight","//flower","//fond","//hate","//heart","//hug","//kiss","//later","//leaving","//love","//luck","//mabrook","//mad","//miss","//salam","//shake","//sheeshah","//shy","//sleepy","//sorry","//surprise","//thank","//wave","//welcome","//wsalam","//yell","/warn","/colorbox","/send","/send2","/time","/account2","/account","/uann","/opsann","/sms","/sms2","/icq2","/icq","/grant","//al","//mk","//sp","//su","//st","/callcomm","/mops","/musers","/opsmail","/ip","/reop","/restore","/wait","/roomann","/suspend","/suspendlist","/commlist","/editacc","/record","/lev","/opslist","/acc","//it","//bl","//un","/add","/deoplist","/deop","/images","/vabuse","/report","/dir","/bbclear","/commbbclear","/vcomm","/comm","/abuse","/img","/link","/rose","//b","//r","//g","//y","//w","//bo","/igmail","/mkick","/editann","/ann","/delmail","/mail","/logs","/noproxy","/rose5","/clearbuffer","/clear","/read","/post","/ig","/lock","/unlock","/d","/comment","/quit","/msg","/join","/ops","/bottom","/frames","/whoall","/whois","/who","/color","/pic","/wid","/len","/pref","/bg","/text","/speed","/msg","m","/m","/ban","/unban","/kick","/id","/unban","/changerooms","/menu","/forward","/fl","/list","/summon","/null","/dosummonstuff","//fade","//fade3","/help","/nick","/reboot","/away","/sb");  

$time = time();  


@months = ('January','February','March','April','May','June','July','August','September','October','November','December');  @days = ('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday');  

($sec,$min,$hour,$day,$month,$year,$day2) = (localtime(time))[0,1,2,3,4,5,6];  


if ($sec < 10) { $sec = "0$sec"; }  

if ($min < 10) { $min = "0$min"; }  


if ($hour < 10) { $hour = "0$hour"; }  


if ($day < 10) { $day = "0$day"; }  


$year += "1900";  $weekday = $days[$day2];              

$amonth = $months[$month];   

$fulltime = "$weekday, $amonth $day, $year, $hour:$min:$sec";   

$emonth = $month + 1; 

$time_file = "$year.$day.$emonth";    


$banlogs = "/opt/ulyaoth/public/banlogs/$time_file";   


#images

@imegs = ("/acid","/alien","/angelhug","/angrycrowd","/angryface","/angry","/angryrun","/angryyell","/backkiss","/barman","/boxing","/breakdance","/ca","/cathug","/chaplin","/crazy","/dance","/dinosaur","/doggy","/football","/frog","/fry","/greet","/grr","/jiggy","/nerdpunch","/pirate","/shoot","/sick","/sleep","/sleepy","/spank","/stick","/stickinear","/stone","/strangehug","/thinking","/toiletarm","/toilet","/upsidedowngreet","/whacky","/wip","/wizzard");

## words filtered in private messages and private rooms and public rooms

@nonowords = ("bravo",",opschat","falconchat","friendsway","arabfun","halachat","arabtalk","emaratzone","relaychat","socko","arabiastar","arabiarose","arabia-star","arabia-rose","arabia_rose","arabia_star","abudhabi2000","uaetalk","chatsyria","htc1","hypermart","hawkchat","uaetears", '\d+\.\d+\.\d+\.\d+',"heartchat","alamak","a1amak");



##words filtered in public rooms






@badwords = ("DM","Du Ma","Du Me","Con Cac","Lon Bu","Bu Lon","Bu Cac","Mut Cac","Lon Thui","Lon To","Cac To","Cac Bu","Dit Me","Do Cho De","Di Me","du ma","du me","bravo","opschat","falconchat","friendsway","arabfun","halachat","arabtalk","emaratzone","relaychat","socko","arabiastar","arabiarose","arabia-star","arabia-rose","arabia_rose","arabia_star","abudhabi2000","uaetalk","chatsyria","htc1","hypermart","heartchat","hawkchat","f+_*u+_*k|f+_*u+_*c|p+_*h+_*u+_*c|f+_*u+_*c+_*k|c+_*u+_*n+_*t|w+_*h+_*o+_*r+_*e|s+_*[li1]+_*u+_*t|b+_*[li1]+_*t+_*c+_*h|b+_*a+_*s+_*t+_*a+_*r+_*d|a+_*s+_*s+_*h+_*o+_*[li1]+_*e|c+_*u+_*m|f+_*a+_*g|f+_*a+_*g+_*g+_*o+_*t|n+_*[li1]+_*g+_*g+_*e+_*r");



return true;
