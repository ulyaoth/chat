#!/usr/bin/env perl

# Specify the additional Perl modules in order to run the chat.
use Mojolicious::Lite;
use YAML::Tiny;

# Open the configuration file and put everything in $yaml.
my $configuration = YAML::Tiny->read( '/etc/ulyaoth/config.yaml' );

# All required variables from the config file.
my $mytitle = $configuration->[0]->{variables}->{title};

get '/' => sub {
  my $c = shift;
  $c->render(template => 'login', title => $mytitle);
};

get '/login' => sub {
  my $c = shift;
  $c->render(template => 'login', title => "$mytitle - Login");
};

get '/register' => sub {
  my $c = shift;
  $c->render(template => 'register', title => "$mytitle - Register");
};

get '/lostpassword' => sub {
  my $c = shift;
  $c->render(template => 'lostpassword', title => "$mytitle - Lost Password");
};

get '/contact' => sub {
  my $c = shift;
  $c->render(template => 'contact', title => "$mytitle - Contact");
};


app->start;
__DATA__

# Template section below here.
@@ login.html.ep
% layout 'default';
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

@@ register.html.ep
% layout 'default';
<div class="container">
	<section id="content">
		<form action="chat.pl" method="post">
			<h1>Register</h1>
			<div>
				<input type="text" placeholder="Username" required="" id="username" name="n" />
			</div>
			<div>
				<input type="password" placeholder="Password" required="" id="password" name="pass" />
			</div>
			<div>
				<input type="text" placeholder="First Name" required="" id="firstname" name="firstname" />
			</div>
			<div>
				<input type="text" placeholder="Last Name" required="" id="lastname" name="lastname" />
			</div>
			<div>
				<input type="email" placeholder="Email" required="" id="email" name="email" />
			</div>
			<div>
				<input type="date" placeholder="birthdate" required="" id="birthdate" name="birthdate" />
			</div>
			<div>
				<input type="text" placeholder="Secret Question" required="" id="secretquestion" name="secretquestion" />
			</div>
			<div>
				<input type="text" placeholder="Secret Answer" required="" id="secretanswer" name="secretanswer" />
			</div>					
			<div>
				<input type="submit" value="Register" />
				<a href="<%= url_for 'lostpassword' %>">Lost your password?</a>
				<a href="<%= url_for 'login' %>">Already registered?</a>
			</div>
		</form>	
	</section>
</div>

@@ lostpassword.html.ep
% layout 'default';
<div class="container">
	<section id="content">
		<form action="chat.pl" method="post">
			<h1>Lost Password</h1>
			<div>
				<input type="text" placeholder="First Name" required="" id="firstname" name="firstname" />
			</div>
			<div>
				<input type="text" placeholder="Last Name" required="" id="lastname" name="lastname" />
			</div>
			<div>
				<input type="email" placeholder="Email" required="" id="email" name="email" />
			</div>
			<div>
				<input type="text" placeholder="Secret Question" required="" id="secretquestion" name="secretquestion" />
			</div>
			<div>
				<input type="text" placeholder="Secret Answer" required="" id="secretanswer" name="secretanswer" />
			</div>
			<div>
				<input type="date" placeholder="birthdate" required="" id="birthdate" name="birthdate" />
			</div>				
			<div>
				<input type="submit" value="Request Now" />
				<a href="<%= url_for 'contact' %>">Forgot Secret Q&A?</a>
				<a href="<%= url_for 'login' %>">Back to Login.</a>
			</div>
		</form>	
	</section>
</div>

@@ layouts/default.html.ep
<!DOCTYPE html>
<html>
  <head>
    <title><%= title %></title>
  </head>
  <body>
    <%= content %>
  </body>
</html>