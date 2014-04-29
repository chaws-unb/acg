package SearchPattern;
use strict;
use warnings;


sub new {
  my ($class) = @_;
  my $self = {};
  bless $self, $class;
  return $self;
}

sub uniq {
  return keys %{{ map { $_ => 1 } @_ }};
};
sub search_pattern {
  my ($self, @target) = @_;
  my $pattern1 = '(?=([\w\s])([\w\s])([\w\s])([\w\s])([\w\s])([\w\s])([\w\s])([\w\s])\6)';  #seguranca 

  my $tree;
  foreach my $content(@target) {      #Para cada frase
    my $letters;
    while($content =~ m/$pattern1/g) {
      my $s = $1;
      my $e = $2;
      my $g = $3;
      my $u = $4;
      my $r = $5;
      my $a = $6;
      my $n = $7;
      my $c = $8;

      my $seguranca = "$s"."$e"."$g"."$u"."$r"."$a"."$n"."$c"."$a";
      my $seguranc = "$s"."$e"."$g"."$u"."$r"."$a"."$n"."$c";
      my $uniq_seguranc = join("",uniq(split //,$seguranc));
      if (length($uniq_seguranc)!=length($seguranc)) {
        next;
      }

      my $aux = $content;

      while ($aux =~ m/[$c]([\w\s])([\w\s])([\w\s])[$u]([\w\s])[$a]([\w\s])\1[$r]/g) {
        my $o = $1;
        my $m = $2;
        my $p = $3;
        my $t = $4;
        my $d = $5;


        my $computador = "$c"."$o"."$m"."$p"."$u"."$t"."$a"."$d"."$o"."$r";
        my $computadr = "$c"."$o"."$m"."$p"."$u"."$t"."$a"."$d"."$r";
        my $uniq_computadr = join("",uniq(split //,$computadr));
        if (length($uniq_computadr)!=length($computadr)) {
          next;
        }
        $content =~ m/$computador/g;
        if($-[0]>0) {
        }
        if($-[0]<length($content)) {
        }
        $tree->{$content}->{$seguranca}->{$computador}->{'s'} = $s;
        $tree->{$content}->{$seguranca}->{$computador}->{'e'} = $e;
        $tree->{$content}->{$seguranca}->{$computador}->{'g'} = $g;
        $tree->{$content}->{$seguranca}->{$computador}->{'u'} = $u;
        $tree->{$content}->{$seguranca}->{$computador}->{'r'} = $r;
        $tree->{$content}->{$seguranca}->{$computador}->{'a'} = $a;
        $tree->{$content}->{$seguranca}->{$computador}->{'n'} = $n;
        $tree->{$content}->{$seguranca}->{$computador}->{'c'} = $c;
        $tree->{$content}->{$seguranca}->{$computador}->{'o'} = $o;
        $tree->{$content}->{$seguranca}->{$computador}->{'m'} = $m;
        $tree->{$content}->{$seguranca}->{$computador}->{'p'} = $p;
        $tree->{$content}->{$seguranca}->{$computador}->{'t'} = $t;
        $tree->{$content}->{$seguranca}->{$computador}->{'d'} = $d;
      }
    }

    if(defined $letters) {
    }


  }
  return $tree;
}

1;
