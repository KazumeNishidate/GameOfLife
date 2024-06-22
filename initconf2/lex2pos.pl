#!/usr/bin/perl
#
# evaluate the nearest neighbors
#
my $cnt=0;
my $xscale = 100;
my $yscale = 100;
$file=$ARGV[0];
open(FL1, $file) || die "I can't open QE input file. \n";
open(POS, "> position.txt") || die "Error:$!";
while(<FL1>) {
    
   $_=~s/=/ /;
   @lines = split(/\^|\s+/, ' '.$_);
   $num=length($lines[1]);
   my @lifes=split(//,$lines[1]);
   for($i=0;$i<$num;$i++){
       if($lifes[$i] eq ".") {print " 0";}
       if($lifes[$i] eq "O") {print " 1";}
   }
   for($i=$num;$i<$xscale;$i++){
       print " 0";
   }
   print "\n";
   $cnt++;
}

for($j=$cnt;$j<$yscale;$j++){
    for($i=0;$i<$xscale;$i++){
	print " 0";
    }
    print "\n";
}

