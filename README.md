# How to install.<br>
<br>
RHEL Based:<br>
1. Install the Ulyaoth repository:<br>
https://www.ulyaoth.net/resources/ulyaoth-repository.6/<br>
<br>
2. Install the following packages: (change dnf to yum if required)<br>
dnf install ulyaoth-hiawatha perl perl-CGI perl-DB_File perl-YAML-Tiny wget zip<br>
<br>
3. Git clone the chat repository<br>
https://github.com/ulyaoth/chat.git<br>
<br>
4. Move the folder to correct location.<br>
Move the ulyaoth folder inside the "etc" folder to /etc on your server.<br>
Move the ulyaoth folder inside the "opt" folder to /opt on your server.<br>
Move the ulyaoth folder inside the "srv" folder to /srv on your server.<br>
<br>
5. Permissions.<br>
This kind of depends on your setup I use the following. (you must create users)<br>
chown -R hiawatha:ulyaoth /etc/ulyaoth<br>
chown -R hiawatha:ulyaoth /opt/ulyaoth<br>
chown -R hiawatha:ulyaoth /srv/ulyaoth<br>
<br>
chmod 0755 all ".cgi" files.<br>
chmod 0755 all ".db" files.<br>
chmod 0644 all other files.<br>
chmod 0755 all folders.<br>
<br>
for selinux:<br>
All ".cgi" file: chcon -R -t httpd_sys_script_exec_t<br>
chcon -R -t httpd_sys_content_t /opt/ulyaoth<br>
chcon -R -t httpd_sys_rw_content_t /srv/ulyaoth/public/banlogs<br>
chcon -R -t httpd_sys_rw_content_t /srv/ulyaoth/public/upload<br>
<br>
6. Hiawatha<br>
/etc/hiawatha/sites-available/chat.ulyaoth.net.conf:<br>
```
VirtualHost {
  Hostname = chat.ulyaoth.net
  WebsiteRoot = /srv/ulyaoth/public
  AccessLogfile = /var/log/hiawatha/ulyaoth-access.log
  ErrorLogfile = /var/log/hiawatha/ulyaoth-error.log
  StartFile = chat.cgi
  ExecuteCGI = yes
  RequireTLS = yes,31104000
  RandomHeader = 512
}
```
<br>
(remove the RequireTLS if you not use SSL)<br>
<br>
hiawatha.conf:<br>
enable: CGIhandler = /usr/bin/perl:cgi<br>
<br>
Administrator login:<br>
Username: admin<br>
Password: admin<br>
<br>