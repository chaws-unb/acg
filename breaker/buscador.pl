use strict;
use warnings;

use Search;

my $dict = Search->new;

my @words = $dict->search_in_dictionary($ARGV[0]);
my $tam = @words;
print "$tam\n";
foreach my $word(@words) {
  print "$word";
}
