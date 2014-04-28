use strict;
use warnings;

use Data::Dumper;

use Search;
use SearchPattern;

my $dict = Search->new;
my $dict_pattern = SearchPattern->new;

my $pos_file = "pos.txt";

open (my $possibilities_file, '<', $pos_file) or die $!;

my @possibilities = ();

while(<$possibilities_file>){
  push(@possibilities, $_);
}

close($possibilities_file);

my $tree = $dict_pattern->search_pattern(@possibilities);

print "Resultados:\n";
#foreach my $expression (keys $tree)
#{
#  print "$expression\n";
#  my @occur = $tree->{$expression};
#  print join(" ",@occur);
#  print "\n";
#}


print Dumper($tree);
