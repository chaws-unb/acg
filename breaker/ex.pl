use strict;
use warnings;

my $defined_pattern = '....([\w\s])..\1';

my $frase = "tudo e questao de seguranca meu carotudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meutudo e questao de seguranca meu                             ";

while($frase =~ m/[\w]{5}([\w\s])..\1/g) {
  print "[$1]\n";
}
