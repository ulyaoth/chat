#!/usr/bin/perl


opendir(ALLACTION,"$root/online/action/");

@mesaction = readdir(ALLACTION);

closedir(ALLACTION);


foreach $i(@mesaction){

 open(MESPRIV,">>$root/online/pm/$i.txt");

print MESPRIV $msg_action;

close(MESPRIV);

}

return true;