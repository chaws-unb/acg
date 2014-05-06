package SearchPattern;
use strict;
use warnings;

sub new {
  my ($class) = @_;
  my $self = {};
  bless $self, $class;
  return $self;
}

sub search_pattern {
  my ($self, $pattern, $chars) = @_;
  my $regex = "^".$expression."\$";

  open(my $dict, '<', $dict_file) or die $!;

  my @list = ();

  while(<$dict>) {
    if($_ =~ m/$regex/) {
      push(@list,$_);
    }
  }

  return @list;
}

1;
