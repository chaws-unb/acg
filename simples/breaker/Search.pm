package Search;
use strict;
use warnings;

my $dict_file = "wordlist_ptbr.txt";

sub new {
  my ($class) = @_;
  my $self = {};
  bless $self, $class;
  return $self;
}

sub search_in_dictionary {
  my ($self, $expression) = @_;
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
