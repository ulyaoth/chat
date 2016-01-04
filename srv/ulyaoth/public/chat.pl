#!/usr/bin/env perl
use Mojolicious::Lite;

get '/' => sub {
  my $c = shift;
  $c->render(template => 'login', css => 'login.css');
};

get '/login' => sub {
  my $c = shift;
  $c->render(template => 'login');
};

get '/register' => sub {
  my $c = shift;
  $c->render(template => 'login');
};

get '/lostpassword' => sub {
  my $c = shift;
  $c->render(template => 'login');
};

app->start;
__DATA__

@@ login.html.ep
% layout 'default';
% title '$title';
<h3>Password currently not required for non registered users.</h3>
<div class="container">
	<section id="content">
		<form action="chat.cgi" method="post">
			<h1>Chat Login</h1>
			<div>
				<input type="text" placeholder="Username" required="" id="username" name="n" />
			</div>
			<div>
				<input type="password" placeholder="Password" required="" id="password" name="pass" />
			</div>
			<div>
				<input type="submit" value="Enter Chat" />
				<a href="<%= url_for 'lostpassword' %>">Lost your password?</a>
				<a href="<%= url_for 'register' %>">Register</a>
			</div>
		</form>	
	</section>
</div>

@@ layouts/default.html.ep
<!DOCTYPE html>
<html>
  <head>
    <title><%= title %></title>
    <link rel="stylesheet" type="text/css" href="css/<%= $css %>" />
  </head>
  <body><%= content %></body>
</html>