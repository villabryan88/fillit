#!/usr/bin/perl
use warnings;
use strict;
die "program number(1-26)" unless (scalar(@ARGV) == 1);
my ($pieces) = @ARGV;
my $k = 0;
while ($pieces){
for (my $i = 0; $i < 4; $i++) {
for (my $j = 0; $j < 4; $j++) {
if (int(rand(4) * 2) < 6 && $k < 4) {
print "#";
$k++;
}
else {
print ".";
}
}
print "\n";
}
if ($pieces > 1){
print "\n";
}
$pieces--;
$k = 0;
}
