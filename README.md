# What can you do to help?<br>
1. I am looking to integrate Mojolicious with this chat but keep all the same functionalities.<br>
2. I also look to move to use a proper database such as MySQL, and if possible more choose.<br>
3. Memcache certain things perhaps chat rooms?.<br>
4. css for the login, register lostpassword pages etc..<br>
<br>
It is important all functions the chat currently has would stay the same or are improved.<br>
<br>
<br>
The new file that should be worked on is "chat.pl", the "chat.cgi" is still there in order to use the chat fully but it should be eventually removed.

# How to install.<br>
<br>
RHEL Based:<br>
Please be aware this installation is a temporarily solution till the legacy is gone eventually you should have enough for with nginx.<br>
<br>
<br>
1. Install the Ulyaoth repository:<br>
https://www.ulyaoth.net/resources/ulyaoth-repository.6/<br>
<br>
2. Install the following packages: (change dnf to yum if required)<br>
dnf install ulyaoth-nginx ulyaoth-hiawatha mariadb mariadb-server perl perl-CPAN perl-CGI perl-DB_File perl-YAML-Tiny perl-Compress-Raw-Zlib perl-IO-Zlib perl-Digest-MD5 wget zip<br>
<br>
3. Open a Perl CPAN shell and install Monolicious<br>
 perl -MCPAN -e shell<br>
 install Mojolicious<br>
<br>
4. Git clone the chat repository<br>
https://github.com/ulyaoth/chat.git<br>
<br>
5. Move the folder to correct location.<br>
Move the ulyaoth folder inside the "etc" folder to /etc on your server.<br>
Move the ulyaoth folder inside the "opt" folder to /opt on your server.<br>
Move the ulyaoth folder inside the "srv" folder to /srv on your server.<br>
Move the file ülyaoth-chat.service to the /usr/lib/systemd/system/ folder on your server.<br>
<br>
6. Permissions.<br>
This kind of depends on your setup I use the following. (you must create users)<br>
chown -R hiawatha:ulyaoth /etc/ulyaoth<br>
chown -R hiawatha:ulyaoth /opt/ulyaoth<br>
chown -R hiawatha:ulyaoth /srv/ulyaoth<br>
<br>
chmod 0755 all ".pl" files.<br>
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
7. Hiawatha<br>
/etc/hiawatha/sites-available/chat.ulyaoth.net.conf:<br>
```
VirtualHost {
  Hostname = chat.ulyaoth.net
  WebsiteRoot = /srv/ulyaoth/public
  AccessLogfile = /var/log/hiawatha/ulyaoth-access.log
  ErrorLogfile = /var/log/hiawatha/ulyaoth-error.log
  StartFile = bin.cgi
  ExecuteCGI = yes
}
```
<br>
hiawatha.conf:<br>
enable: CGIhandler = /usr/bin/perl:cgi<br>
(run on port 8080)
<br>
8. Nginx<br>
ulyaoth-chat.conf:
```
upstream ulyaothbackend {
  server 127.0.0.1:3000;
}

upstream hiawathabackend {
  server 127.0.0.1:8080;
}

server {
  listen 80 default_server;
  server_name  chat.ulyaoth.net;
  return 301 https://$host$request_uri;
}

server {
  listen       443 ssl default_server;
  server_name  chat.ulyaoth.net;

  root         /srv/ulyaoth/public;
  index        index.html;

  access_log  /var/log/nginx/ulyaothchat-access.log main;
  error_log   /var/log/nginx/ulyaothchat-error.log;


if ($http_user_agent ~ "Windows 95|Windows 98|biz360.com|xpymep|TurnitinBot|sindice|Purebot|libwww-perl")  {
  return 403;
  break;
}

  ssl_certificate             /etc/nginx/ssl/test.pem;
  ssl_certificate_key         /etc/nginx/ssl/test.key;
  ssl_dhparam                 /etc/nginx/ssl/dhparams.pem;
  ssl_session_cache           builtin:1000  shared:SSL:2m;
  ssl_session_timeout         5m;
  ssl_protocols               TLSv1 TLSv1.1 TLSv1.2;
  ssl_prefer_server_ciphers   on;

  ssl_ciphers  ECDHE-RSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-SHA384:DHE-RSA-AES256-GCM-SHA384:DHE-RSA-AES256-GCM-SHA384:DHE-RSA-AES256-SHA256:ECDHE-RSA-AES256-SHA:DHE-RSA-AES256-SHA:DHE-RSA-CAMELLIA256-SHA:ECDHE-RSA-AES256-SHA:DHE-RSA-AES256-SHA:DHE-RSA-AES256-SHA:DHE-RSA-CAMELLIA256-SHA:ECDH-RSA-AES256-SHA:CAMELLIA256-SHA:AES256-SHA;

  ssl_stapling on;
  ssl_stapling_verify on;
  resolver 8.8.8.8 8.8.4.4 valid=300s;
  resolver_timeout 5s;
  ssl_trusted_certificate /etc/nginx/ssl/test.ca;

  add_header Strict-Transport-Security "max-age=31536000; includeSubdomains;";
  add_header Public-Key-Pins "pin-sha256=\"zco8Bhue8GQPxzzGd9unFQteH9JAk4VUxsofgGUkb7k=\"; max-age=172800;";

location ~ \.(cgi) {
  proxy_pass http://hiawathabackend;
  proxy_set_header X-Real-IP $remote_addr;
  proxy_set_header X-forwarded-for $proxy_add_x_forwarded_for;
  proxy_set_header Host $http_host;
}

location / {
  proxy_pass http://ulyaothbackend;
  proxy_set_header X-Real-IP $remote_addr;
  proxy_set_header X-forwarded-for $proxy_add_x_forwarded_for;
  proxy_set_header Host $http_host;
}

}
```
<br>
9. Start & Enable service<br>
Start:<br>
systemctl start nginx.service<br>
systemctl start hiawatha.service<br>
systemctl start ulyaoth-chat.service<br>
<br>
Enable:<br>
systemctl enable nginx.service<br>
systemctl enable hiawatha.service<br>
systemctl enable ulyaoth-chat.service<br>
<br>
Administrator login:<br>
Username: admin<br>
Password: admin<br>
<br>