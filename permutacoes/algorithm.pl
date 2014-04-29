use strict;
use warnings;

use Algorithm::Permute;


#my $cripto = "CzWbFbzFHzjHLnh9XD9zHznlPVzd9h9zjbVnDPbX9hzdhbBVHW9jzDbWzdhbLh9W9jzHzFhPpHhjzfnHzl9VpHwzX9bzPXPDPHWzDbhhHl9WHXlHzbnzfnHzdbFHWzPWdHFPhzfnHzbz4PXFbrjzjHR9zPXPDP9FbzDbhhHl9WHXlHz2HznWzdhbBVHW9zX9bzjHzhHdHlPhzfn9XFbzbzDbWdnl9FbhzJbhzPXPDP9FbzXbzWbFbzFHzjHLnh9XD9zpbDHzdbFHh9zHVPWPX9hz9jzDbXJPLnh9DbHjzd9Fh9bzHzbjzFhPpHhjzFHzFPjdbjPlPpbzB9jPDbjzDbWbz9jzdbjjPpHPjzD9nj9jz2HznWzdhbLh9W9zFPjdbjPlPpbzbnzFhPpHhzPXjl9V9FbzhHDHXlHWHXlHzPWdHFPhz9zHvHDnD9bzDbhhHl9zFbz4PXFbrjzpbDHzdbFHh9zPXPDP9hzbzDbWdnl9FbhzXbzWbFbzFHzjHLnh9XD9zHzHWzjHLnPF9zhHWbpHhzbzdhbLh9W9zfnHzHjl9zD9nj9XFbzbzdhbBVHW9z7n9VfnHhznjn9hPbzPXFHdHXFHXlHzFbzlPdbzFHznjbzFbzDbWdnl9FbhzdbFHzjHhznWz9VpbzW9h9pPVNbjbzd9h9zbjzsqsmkqzW9VPDPbjbjzFHjHXpbVpHFbhHjzFHzdh9L9jzpPhln9PjzdhPXDPd9VWHXlHzdbhfnHzD9F9zHfnPd9WHXlbzPXJHDl9FbzlHWz9zD9d9DPF9FHzFHzPXJHDl9hznW9zfn9XlPF9FHz9BjnhF9zFHzbnlhbjzDbWdnl9FbhHjzjHWzbzDbXNHDPWHXlbzFbzdhbdhPHl9hPbz0bDHzj9BP9zfnHzdbFHzdHL9hzznWzpPhnjzjbWHXlHzdbhz9DHjj9hzjPlHjzPXJHDl9Fbjze9jl9zfnHzjn9zW9fnPX9zX9bzHjlHR9zdhblHLPF9zFHpPF9WHXlHzbnzfnHzpbDHzHjlHR9znlPVPw9XFbzjbJlr9hHjzFHj9ln9VPw9FbjzcbPj9zjHhP9j";
my $cripto = "CzWbFbzFHzjHLnh9XD9zHznlPVzd9h9zjbVnDPbX9hzdhbBVHW9jzDbWzdhbLh9W9jzHzFhPpHhjzfnHzl9VpHwzX9bzPXPDPHWzDbhhHl9WHXlHzbnzfnHzdbFHWzPWdHFPhzfnHzbz4PXFbrjzjHR9zPXPDP9FbzDbhhHl9WHXlHz2HznWzdhbBVHW9zX9bzjHzhHdHlPhzfn9XFbzbzDbWdnl9FbhzJbhzPXPDP9FbzXbzWbFbzFHzjHLnh9XD9zpbDHzdbFHh9zHVPWPX9hz9jzDbXJPLnh9DbHjzd9Fh9bzHzbjzFhPpHhjzFHzFPjdbjPlPpbzB9jPDbjzDbWbz9jzdbjjPpHPjzD9nj9jz2HznWzdhbLh9W9zFPjdbjPlPpbzbnzFhPpHhzPXjl9V9FbzhHDHXlHWHXlHzPWdHFPhz9zHvHDnD9bzDbhhHl9zFbz4PXFbrjzpbDHzdbFHh9zPXPDP9hzbzDbWdnl9FbhzXbzWbFbzFHzjHLnh9XD9zHzHWzjHLnPF9zhHWbpHhzbzdhbLh9W9zfnHzHjl9zD9nj9XFbzbzdhbBVHW9z7n9VfnHhznjn9hPbzPXFHdHXFHXlHzFbzlPdbzFHznjbzFbzDbWdnl9FbhzdbFHzjHhznWz9VpbzW9h9pPVNbjbzd9h9zbjzsqsmkqzW9VPDPbjbjzFHjHXpbVpHFbhHjzFHzdh9L9jzpPhln9PjzdhPXDPd9VWHXlHzdbhfnHzD9F9zHfnPd9WHXlbzPXJHDl9FbzlHWz9zD9d9DPF9FHzFHzPXJHDl9hznW9zfn9XlPF9FHz9BjnhF9zFHzbnlhbjzDbWdnl9FbhHjzjHWzbzDbXNHDPWHXlbzFbzdhbdhPHl9hPbz0bDHzj9BP9zfnHzdbFHzdHL9hzznWzpPhnjzjbWHXlHzdbhz9DHjj9hzjPlHjzPXJHDl9Fbjze9jl9zfnHzjn9zW9fnPX9zX9bzHjlHR9zdhblHLPF9zFHpPF9WHXlHzbnzfnHzpbDHzHjlHR9znlPVPw9XFbzjbJlr9hHjzFHj9ln9VPw9FbjzcbPj9zjHhP9";


my $cripto_size = length($cripto);
my @array = split //, $cripto;
my @result = transposition(8,@array);
my $tam_result = @result;

print "Tamanho do array: ".$tam_result."\n";

my $file = "permutado1.txt";

unless(open FILE, '>'.$file) {
  die $!;
}

while(@result) {
  my @tmp = splice @result, 0, $cripto_size;
  print FILE join("",@tmp);
  print FILE "\n";
}
close FILE;

sub transposition {
  my ($transp_size,@raw_content) = @_;

  my @array = create_array($transp_size);
  my $p_iterator = Algorithm::Permute->new(\@array);
  my @permuted = ();
  my $max = 0;
#  for(my $i=0;$i<20160;$i++){
#    my $tmp_it = $p_iterator->next;
#  }
  while (my @perm = $p_iterator->next) {
    if ($max==20160) {  #10080
      last;
    }
    my @content = @raw_content;

    while(@content) {
      my @block = splice @content, 0, $transp_size;
      my @new_block = ();

      for(my $i=0 ; $i<$transp_size ; $i++) {
        push (@new_block, $block[$perm[$i]]);
        
      }

      push(@permuted,@new_block);
    }
    $max++;
  }

  print "\n";
  return @permuted;

}

sub create_array {
  my ($tam) = @_;
  my @values = ();
  for(my $i=0; $i<$tam ; $i++) {
    push(@values,$i);
  }
  return @values;
}
