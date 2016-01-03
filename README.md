# How to install.

RHEL Based:
1. Install the Ulyaoth repository:
https://www.ulyaoth.net/resources/ulyaoth-repository.6/

2. Install the following packages: (change dnf to yum if required)
dnf install ulyaoth-hiawatha perl perl-CGI perl-DB_File perl-YAML-Tiny wget zip

3. Git clone the chat repository
https://github.com/ulyaoth/chat.git

4. Move the folder to correct location.
Move the ulyaoth folder inside the "etc" folder to /etc on your server.
Move the ulyaoth folder inside the "opt" folder to /opt on your server.
Move the ulyaoth folder inside the "srv" folder to /srv on your server.

5. Permissions.
This kind of depends on your setup I use the following. (you must create users)
chown -R hiawatha:ulyaoth /etc/ulyaoth
chown -R hiawatha:ulyaoth /opt/ulyaoth
chown -R hiawatha:ulyaoth /srv/ulyaoth

chmod 0755 all ".cgi" files.
chmod 0755 all ".db" files.
chmod 0644 all other files.
chmod 0755 all folders.

for selinux:
All ".cgi" file: chcon -R -t httpd_sys_script_exec_t
chcon -R -t httpd_sys_content_t /opt/ulyaoth
chcon -R -t httpd_sys_rw_content_t /srv/ulyaoth/public/banlogs
chcon -R -t httpd_sys_rw_content_t /srv/ulyaoth/public/upload

6. Hiawatha
/etc/hiawatha/sites-available/chat.ulyaoth.net.conf:
VirtualHost {
  Hostname = chat.ulyaoth.net
  WebsiteRoot = /srv/ulyaoth/public
  AccessLogfile = /var/log/hiawatha/ulyaoth-access.log
  ErrorLogfile = /var/log/hiawatha/ulyaoth-error.log
  StartFile = bin.cgi
  ExecuteCGI = yes
  RequireTLS = yes,31104000
  RandomHeader = 512
}

(remove the RequireTLS if you not use SSL)

hiawatha.conf:
enable: CGIhandler = /usr/bin/perl:cgi
