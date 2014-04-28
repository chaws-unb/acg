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
  my ($self, @target) = @_;
  my $pattern1 ='(?=[\w]{5}([\w\s])..\1)';  #seguranca 

  my $tree;
  foreach my $content(@target) {      #Para cada frase
    my @values = ();
    while($content =~ m/$pattern1/g) {
        push(@values,$1);
    }

    my @values2 = ();
    if(@values) {
      my $regex2 = '.([\w\s]).{4}[-].\1.';
      foreach my $letter (@values) {
        my $pattern2 = $regex2;
        $pattern2 =~ s/-/$letter/g;
        if($content =~ m/$pattern2/) {
          push(@values2,$1);
        }

        $tree->{$content}->{'a'} = \@values;
        $tree->{$content}->{'o'} = \@values2;
      }
    }

  }
  return $tree;
}

1;
