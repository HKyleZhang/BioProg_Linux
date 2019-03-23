/******************************COPYRIGHT NOTICE*******************************/
/*  (c) Centro de Regulacio Genomica                                                        */
/*  and                                                                                     */
/*  Cedric Notredame                                                                        */
/*  11 Dec 2018 - 09:27.                                                                    */
/*All rights reserved.                                                                      */
/*This file is part of T-COFFEE.                                                            */
/*                                                                                          */
/*    T-COFFEE is free software; you can redistribute it and/or modify                      */
/*    it under the terms of the GNU General Public License as published by                  */
/*    the Free Software Foundation; either version 2 of the License, or                     */
/*    (at your option) any later version.                                                   */
/*                                                                                          */
/*    T-COFFEE is distributed in the hope that it will be useful,                           */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of                        */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                         */
/*    GNU General Public License for more details.                                          */
/*                                                                                          */
/*    You should have received a copy of the GNU General Public License                     */
/*    along with Foobar; if not, write to the Free Software                                 */
/*    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA             */
/*...............................................                                           */
/*  If you need some more information                                                       */
/*  cedric.notredame@gmail.com                                                             */
/*...............................................                                           */
/******************************COPYRIGHT NOTICE*******************************/
char *PerlScriptName[]={"rec_sum.pl","count.pl","p\
rocess_list.pl","make_license.pl","CCsed.script","\
msa2bootstrap.pl","t_coffee_dpa","t_coffee_dpa2","\
tc_generic_method.pl","rnapdb2protpdb.pl","generic\
_method.tc_method","clustalw_method.tc_method","ex\
tract_from_pdb","install.pl","clean_cache.pl","nat\
ure_protocol.pl","mocca","dalilite.pl","wublast.pl\
","blastpgp.pl","ncbiblast_lwp.pl","wublast_lwp.pl\
","RNAplfold2tclib.pl","fasta_seq2RNAplfold_templa\
tefile.pl","fasta_seq2hmmtop_fasta.pl","fasta_seq2\
consan_aln.pl","clustalw_aln2fasta_aln.pl","seq2na\
me_seq.pl","seq2intersection.pl","msf_aln2fasta_al\
n.pl","msa.pl","upp.pl","clustalo.pl","dca.pl","bl\
ast_aln2fasta_aln.pl","blast_xml2fasta_aln.pl","fa\
sta_aln2fasta_aln_unique_name.pl","newick2name_lis\
t.pl","excel2fasta.pl","nameseq2fasta.pl","any_fil\
e2unix_file.pl","EndList"};char *PerlScriptFile[]=\
{"use File::Copy;\nuse Env qw(HOST);\nuse Env qw(H\
OME);\nuse Env qw(USER);\n$x_field=0;\n$y_field=1;\
\n$y_field_set=1;\n$nyf=1;\n\n$interval=0;\n$file=\
\"stdin\";\n\n$print_avg=1;\n$print_sd=0;\n$print_\
sum=0;\n$print_n=0;\nforeach $value ( @ARGV)\n    \
{\n	if ($value ne $ARGV[$np]) \n	    {\n	    ;\n	 \
   }\n	elsif($value eq \"-s\")\n	     {\n	       $\
step=$ARGV[++$np];\n	       $np++;\n	     }\n	elsi\
f($value eq \"-print_all\")\n	    {\n	    $print_s\
d=$print_avg=$print_n=$print_sum=1;\n	    $np++;\n\
	    }\n	elsif($value eq \"-print_sum\")\n	    {\n\
	    $print_sum=1;\n	    $print_avg=0;\n	    $np++\
;\n	    }\n	elsif($value eq \"-print_n\")\n	    {\\
n	    $print_n=1;\n	    $print_avg=0;\n	    $np++;\
\n	    }\n	elsif($value eq \"-print_avg\")\n	    {\
\n	    $print_avg=1;\n	    $print_avg=0;\n	    $np\
++;\n	    }\n	elsif($value eq \"-sd\")\n	    {\n	 \
   $print_sd=1;\n	    $print_avg=0;\n	    $np++;\n\
	    }\n	elsif($value eq \"-h\")\n	    {\n	    $he\
ader=1;\n	    $np++;\n	    }\n	elsif ($value eq \"\
-i\")\n	    {\n	    $interval= $ARGV[++$np];\n	   \
 $np++;\n    	    }\n	elsif ($value eq \"-r2\")\n	\
    {\n	      $r2=1;\n	      \n	      $np  = $ARGV\
[++$np];\n	      $nsim= $ARGV[++$np];\n	      $np+\
+;\n    	    }\n	elsif ($value eq \"-r\")\n	    {\\
n	    $min= $ARGV[++$np];\n	    $max= $ARGV[++$np]\
;\n	    $np++;\n    	    }\n	\n	elsif ($value eq \\
"-x\")\n	    {\n	    $x_field= $ARGV[++$np]-1;\n	 \
   $np++;\n    	    }\n	elsif ($value eq \"-y\")\n\
	    {\n	    $nyf=0;  \n	    while ($ARGV[$np+1] &\
& !($ARGV[$np+1]=~/\\-/))\n	      {\n		$y_field[$n\
yf++]=$ARGV[++$np]-1;\n		$y_field_set=1;\n	      }\
\n\n	    $np++;\n    	    }\n	elsif ($value eq \"-\
file\")\n	    {\n	    $file= $ARGV[++$np];\n	    $\
file_set=1;\n	    $np++;\n    	    }       \n	elsi\
f ( $value eq \"h\" ||  $value eq \"-h\" || $value\
 eq \"-H\" || $value eq \"-help\" || $value eq \"h\
elp\")\n	  {\n	    print STDOUT \"data_analyse: An\
alyse and discretization of data\\n\";\n	    print\
 STDOUT \"       -file:    <file containing the da\
ta to analyze>,.<def=STDIN>\\n\";\n	    print STDO\
UT \"       -x: <field containing the X>,.........\
......<Def=0>\\n\";\n	    print STDOUT \"       -y\
: <field containing the Y>,...............<Def=1>\\
\n\";\n	    print STDOUT \"       -i:<Interval siz\
e on the X>,...............<Def=0>\\n\";\n	    pri\
nt STDOUT \"       -i:<0:only one interval>\\n\";\\
n	    print STDOUT \"       -r:<Range of the X>\\n\
\";\n	    print STDOUT \"       -s:<Step on the  X\
, 0 means non sliding bins>\\n\";\n	    print STDO\
UT \"       -sd: print standard deviation on the Y\
\";\n	    print STDOUT \"       -h  : print column\
 header \\n\";\n	    exit (0);\n	  }\n	elsif ($val\
ue=~/-/)\n	  {\n	    print \"$value is not a valid\
 FLAG[FATAL]\\n\";\n	    exit (0);\n	   } \n	elsif\
 ($list eq \"\") \n	    {\n	    $file=$ARGV[$np];\\
n	    $np++;\n	    }\n	\n	\n      }\n\n\n\n\n\nif \
($file eq \"stdin\")\n	{\n	$remove_file=1;\n	$file\
=\"tmp$$\";\n	open (F, \">$file\");\n	while (<STDI\
N>)\n		{\n		print F $_;\n		}\n	close (F);\n	 \n	;}\
\n\n\n\nif ($interval && $step)\n  {\n    my $nl;\\
n    open(F,$file);\n    while (<F>)\n      {\n	$l\
ine=$_;\n	\n	if (!/\\S/){next;}\n	@list=($line=~/(\
\\S+)/g);\n	$val{$nl}{x}=$list[$x_field];\n	$val{$\
nl}{y}=$list[$y_field[0]];\n	$nl++\n      }\n    c\
lose (F);\n    \n    for (my $a=$min; $a<($max+$in\
terval); $a+=$step)\n      {\n	my ($avgx, $avgy, $\
cn);\n	\n	my $rmin=$a-$interval;\n	my $rmax=$a;\n	\
$cn=0;\n	for (my $b=0; $b<$nl; $b++)\n	  {\n	    m\
y $x=$val{$b}{x};\n	    my $y=$val{$b}{y};\n	    i\
f ($x<=$rmax && $x>=$rmin)\n	      {\n		$avgx+=$x;\
\n		$avgy+=$y;\n		$cn++;\n		$tcn++;\n		$val{$b}{us\
ed}=1;\n	      }\n	  }\n	if ($cn)\n	  {\n	    $avg\
x/=$cn;\n	    $avgy/=$cn;\n	  }\n	printf \"%.3f %.\
3f %.3f\\n\", $avgx, $avgy, $avgx-$avgy;\n      }\\
n    for (my $a=0; $a<$nl; $a++)\n      {\n	if ( !\
$val{$a}{used})\n	  {\n	    print \"---$val{$a}{x}\
; $val{$a}{y}\\n\";\n	  }\n      }\n  }\nelse\n  {\
\n    if ($interval && $max)\n      {\n	$interval_\
size=($max-$min)/$interval;\n      }\n    elsif ($\
interval)\n      {\n	open(F,$file);  \n	my $set_ma\
x=0;\n	my $set_min=0;\n	while (<F>)\n	  {\n	    my\
 $v=$_;\n	    chomp($v);\n	    print \"--$v--\";\n\
	    \n	    if ($v<$min ||!$set_min){$set_min=1;$m\
in=$v;}\n	    if ($v>$max ||!$set_max){$set_max=1;\
$max=$v;}\n	  }\n	close (F);\n	print \"$min $max u\
uuu\";\n	$interval_size=($max-$min)/$interval;\n  \
    }\n    open(F,$file);  \n    while (<F>)\n    \
  {\n	$line=$_;\n	if (!/\\S/){next;}\n	@list=($lin\
e=~/(\\S+)/g);\n	\n	if ($interval==0){$bin=0;}\n	e\
lse{$bin=int (($list[$x_field]-$min)/($interval_si\
ze));}\n	\n	\n	if ($bin && $bin==$interval){$bin--\
;}\n	for ( $a=0; $a<$nyf; $a++)\n	  {\n	    $sum{$\
a}{$bin}+=$list[$y_field[$a]];\n	    $sum2{$a}{$bi\
n}+=$list[$y_field[$a]]*$list[$y_field[$a]];\n	   \
 $n{$a}{$bin}++;\n	  }\n      }\n    \n    if (!$i\
nterval){$interval=1;}\n    for ( $a=0; $a<$interv\
al; $a++)\n      {\n	printf ( \"%4d %4d \", $inter\
val_size*$a, $interval_size*($a+1));\n	for ( $b=0;\
 $b<$nyf; $b++)	\n	  {\n	    $i=$interval*$a;\n	  \
  if ( $n{$b}{$a}==0)\n	      {\n		$avg=0;\n		$sd=\
0;\n	      }\n	    else\n	      {\n		$avg=$sum{$b}\
{$a}/$n{$b}{$a};\n		$sd=sqrt($sum2{$b}{$a}*$n{$b}{\
$a}-$sum{$b}{$a}*$sum{$b}{$a})/($n{$b}{$a}*$n{$b}{\
$a});\n	      }\n	    if ($print_n) {printf \"%15.\
4f \", $n{$b}{$a};}\n	    if ($print_sum){printf \\
"%15.4f \", $sum{$b}{$a};}\n	    if ($print_avg){p\
rintf \"%15.4f \", $avg}\n	    if ($print_sd) {pri\
ntf \"%15.4f \", $sd;}\n	  }\n	printf (\"\\n\");\n\
      }\n  }\n\nif ( $remove_file){unlink $file;}\\
n","use File::Copy;\nuse Env qw(HOST);\nuse Env qw\
(HOME);\nuse Env qw(USER);\n\nforeach $v (@ARGV){$\
cl.=$v;}\n\n\nif ( $cl=~/-k(\\d+)/){$k=$1;}\nelse \
{$k=1;}\nif ( $cl=~/-w(\\d+)/){$w=$1;}\nelse {$w=-\
1;}\nif ( $cl=~/-p(\\d+)/){$p=$1;}\nelse {$p=-1;}\\
n\nwhile (<STDIN>)\n  {\n    @l=($_=~/(\\S+)/g);\n\
    $v=$l[$k-1];\n    if ( !$h{$v}){@ll=($v, @ll);\
}\n    \n    if ( $w==-1)\n      {$h{$v}++;}\n    \
else\n      {$h{$v}+=$l[$w-1];}\n\n    if ($p!=-1)\
{$print{$v}=$l[$p-1];}\n\n  }\nforeach $v (@ll)\n \
 {\n    print \"$v $print{$v} $h{$v}\\n\";\n  }\n"\
,"\nuse Env qw(HOST);\nuse Env qw(HOME);\nuse Env \
qw(USER);\n$random_tag=int (rand 10000)+1;\n$uniqu\
e_prefix=\"$$.$HOST.$random_tag\";\n$queue=\"disti\
llery.and.mid\";\n$monitor=0;\n$stderr_file=\"/dev\
/null\";\n$stdio_file=\"/dev/null\";\n$log_file=\"\
/dev/null\";\n$pause_time=0;\n$max_sub_jobs=60;\n$\
min_sub_jobs=30;\n$output_all=0;\n$var='\\$';\n\nf\
oreach $value ( @ARGV)\n    {\n	if ($value ne $ARG\
V[$np]) \n	    {\n	    ;\n	    }\n	elsif ($value e\
q \"-max_sub_jobs\")\n	    {\n	    $max_sub_jobs= \
$ARGV[++$np];\n	    $np++;\n    	    }	\n	elsif ($\
value eq \"-min_sub_jobs\" )\n	    {\n	    $min_su\
b_jobs= $ARGV[++$np];\n	    $np++;\n    	    }\n	e\
lsif ($value eq \"-para\")\n	    {\n	    $para=1;\\
n	    $monitor=1;\n	    $np++;\n    	    }\n	elsif\
 ($value eq \"-monitor\") \n	    {\n	    $monitor=\
1;\n	    $np++;\n	    }\n	elsif ($value eq \"-no_m\
onitor\") \n	    {\n	    $monitor=0;\n	    $np++;\\
n	    }\n	elsif ($value eq \"-queue\")\n	    {\n	 \
   $queue=$ARGV[++$np];\n	    $np++;\n	    }	\n	el\
sif ($value eq \"-stderr_file\")\n	    {\n	    $st\
derr_file=$ARGV[++$np];\n	    $np++;\n	    }\n	els\
if ($value eq \"-stdio_file\")\n	    {\n	    $stdi\
o_file=$ARGV[++$np];\n	    $np++;\n	    }\n	elsif \
($value eq \"-output_all\")\n	    {\n	    $output_\
all=1;\n	    $np++;\n	    }\n	elsif ($value eq \"-\
pause\") \n	    {\n	    $pause_time=$ARGV[++$np];\\
n	    $np++;\n	    }\n	elsif ($value eq \"-log\")\\
n	      {\n	       $log=1;\n	       \n	       if (\
$ARGV[$np+1]=~/\\-\\S+/) \n	          {\n		  $log_\
file=\"stderr\";\n	          }\n	       else \n	  \
        {\n		  $log_file=$ARGV[++$np]; \n		  ++$np\
;\n		 \n	          }\n	      }\n	elsif ( $value eq\
 \"-com\")\n	    {\n		\n		if (!$ARGV[$np+1]=~/^\\'\
/) { $com=$ARGV[++$np];}\n		else {$com=$ARGV[++$np\
];}\n\n	     $np++;\n	    }\n	elsif ( $value eq \"\
-check\")\n	  {\n	    \n	    if (!$ARGV[$np+1]=~/^\
\\'/) { $check=$ARGV[++$np];}\n	    else {$check=$\
ARGV[++$np];}\n	    $np++;\n	  }\n	elsif ($com eq \
\"\") \n	    {\n	    $com_set=1;\n	    $com=$ARGV[\
$np];\n	    \n	    $np++;\n	    }\n	elsif ($list e\
q \"\") \n	    {\n	    $list_set=1;\n	    $list=$A\
RGV[$np];\n	    $np++;\n	    }\n	elsif ( $var_set \
eq \"\")\n	    {\n	    $var_set=1;\n	    $var=$ARG\
V[$np];\n	    $np++;\n	    }\n	}\n\n\n\n\nif ( $co\
m eq \"\"){print \"You Need to Provide a Command [\
FATAL]\\n\";\n	      die;\n	     }\n\n\n\nif ($lis\
t_set==0) \n    {\n    $x= int (rand 100000)+1;\n \
   $tmp_file_name=\"tmp_file_$x\";\n    open ( TMP\
, \">$tmp_file_name\");\n    while (<STDIN>)\n    \
  {\n	print TMP $_;\n      }\n    close (TMP);\n  \
  open (F, $tmp_file_name);\n    }\nelse \n    {\n\
    open (F, $list);\n    }\n\nif ($para==0) \n   \
 {\n\n     @tc_list= <F>;\n     close (F); \n     \
\n     foreach $val(@tc_list) \n	    {\n	      \n	\
      \n	      \n	      $loc_com=$com;\n	      if \
($check){$loc_check=$check;}\n	      \n	      @i_v\
al=($val=~/([^\\s]+)/g);\n	      \n	      if ( $#i\
_val==0)\n		{\n		  if ($check){$loc_check=~s/$var/\
$i_val[0]/g;}\n		  $loc_com=~s/$var/$i_val[0]/g;\n\
		}\n	      else\n		{\n		  for ($n=1; $n<=$#i_val+\
1;$n++ )\n		    {\n		      \n		      $sub=\"$var$n\
\";\n		      \n		      $loc_com=~s/$sub/$i_val[$n-\
1]/g;\n		      if ($check){$loc_check=~s/$var/$i_v\
al[0]/g;}\n		    }\n		}\n	      if ( $check && -e \
$loc_check)\n		{\n		  print STDERR \"skipping $loc\
_com...\\n\";\n		  }\n	      else\n		{\n		  system\
 \"$loc_com\";\n		}\n	    }\n    exit;\n    }\n\ne\
lsif ($para==1) \n    {\n    print STDERR \"do par\
allel execution of: \\\"$com $list\\\"\\n\";\n    \
\n    if ($log==1) \n	{\n	if ($log_file eq \"stdou\
t\" || $log_file eq \"stderr\" ) \n		{\n		$log_fil\
e=\"\";\n	        }\n\n        else \n		{\n		syste\
m \"echo LOG FILE> $log_file\";\n		\n	        }\n	\
}\n    else	\n	{\n	open ( OUT, \">/dev/null\");\n	\
}\n	\n    \n    $id=0;\n    $n_sub=0;\n    while (\
$val=<F>) \n	    {	    	    \n	    $job_log[$id]=\\
"$HOME/tmp/$unique_prefix.$id.log_file\";\n	    \n\
	    $job=$unique_prefix.\"_$id\";\n	    open (JOB\
, \">$job\");\n	    \n	    $loc_com=$com;\n	    ch\
op $val;\n\n	    $loc_com=~s/\\$/$val/g;\n	 \n	   \
 print JOB \"#!/bin/csh\\n\";\n	    print JOB \"#\\
\$ -cwd\\n\";\n	    print JOB \"#\\$ -N $unique_pr\
efix\\n\";\n	    if ($queue && !($queue eq \" \"))\
 {print JOB \"#\\$ -l $queue\\n\";}\n	    print JO\
B \"#\\n\";	    \n            print JOB \"$loc_com\
\\n\";\n	    print JOB \"echo FINISHED  >> $job_lo\
g[$id]\\n\";\n	    print JOB \"pwd\\n\";\n	    \n	\
    close (JOB);\n	    if ( $output_all==1)\n		{\n\
		system \"qsub $job >  $unique_prefix\";		\n	    \
    }\n	    else\n		{system \"qsub $job -e $stderr\
_file -o $stdio_file >$unique_prefix\";	        \n\
	        } \n\n\n\n	    print STDERR \"$id: $outpu\
t_all\\n\";\n	    $n_sub++;\n	    if ( $max_sub_jo\
bs && $n_sub==$max_sub_jobs) \n		{\n		$n_sub=monit\
or_process($min_sub_jobs,@job_log); 		 \n		\n	    \
    }	\n	   \n            unlink $unique_prefix;\n\
	    sleep $pause_time;\n	    $id++;\n	    }\n\n  \
  close (OUT);\n    close (F);\n\n    print STDERR\
 \"Your $id Jobs Have Been Submited (NAME=$unique_\
prefix)\\n\";\n    monitor_process (0, @job_log);\\
n    foreach $file(@job_log) {if (-e $file) {unlin\
k($file);}}\n    \n    }\n\nsub monitor_process ( \
@job_list)\n    {\n    my (@job_list)=@_;\n    my \
$min_sub_jobs=shift (@job_list);\n    my $n_sub_jo\
bs;\n    my $finished;\n    my $n=0;\n\n    $n_sub\
_jobs=-1;\n    $finished=0;\n    print STDERR \"\\\
nMonitor Batch: [$min_sub_jobs]\";\n       \n    w\
hile (!$finished && (($n_sub_jobs>$min_sub_jobs)||\
 $n_sub_jobs==-1) ) \n	{\n	$finished=1;\n	$n_sub_j\
obs=0;\n	$n=0;\n	foreach $file (@job_list)\n	     \
   {\n	\n		if (-e $file){;}\n		else \n		    {\n		 \
   $finished=0; $n_sub_jobs++;\n	            }\n	 \
       }\n	system \"sleep 1\";\n        }\n    \n \
   return $n_sub_jobs;\n    }\n    \n    \nif ($tm\
p_file_name){unlink($tmp_file_name);}\n","\n\nfore\
ach ($np=0; $np<=$#ARGV; $np++)\n    {\n    $value\
=$ARGV[$np];\n\n    if ($value eq \"-file\")\n    \
  {\n      $file= $ARGV[++$np];\n      }\n    elsi\
f ($value eq \"-type\")\n      {\n        $type= $\
ARGV[++$np];\n      }\n    elsif ($value eq \"-ins\
titute\")\n      {\n        $institute= $ARGV[++$n\
p];\n      }\n    elsif ($value eq \"-author\")\n \
     {\n        $author= $ARGV[++$np];\n      }\n \
   elsif ($value eq \"-date\")\n      {\n        $\
date= $ARGV[++$np];\n      }\n     elsif ($value e\
q \"-program\")\n      {\n        $program= $ARGV[\
++$np];\n      }\n    elsif ($value eq \"-email\")\
\n      {\n        $email= $ARGV[++$np];\n      }\\
n    else\n      {\n	print \"$value is an unkown a\
rgument[FATAL]\\n\";\n	exit (1);\n      }\n  }\n\n\
\n\nopen F, $file || die;\nprint $INSTITUTE;\nif (\
 $type eq \"c\"){print \"/************************\
******COPYRIGHT NOTICE****************************\
***/\\n\";}\nif ( $type eq \"perl\"){print \"#####\
#########################COPYRIGHT NOTICE#########\
#####################/\\n\";}\nif ( $type eq \"txt\
\"){print \"-------------------------------COPYRIG\
HT NOTICE------------------------------/\\n\";}\n\\
n\nwhile (<F>)\n  {\n  s/\\$INSTITUTE/$institute/g\
;\n  s/\\$AUTHOR/$author/g;\n  s/\\$DATE/$date/g;\\
n  s/\\$PROGRAM/$program/g;  \n  s/\\$EMAIL/$email\
/g;  \n  if ( $type eq \"txt\"){print $_;}\n  elsi\
f ($type eq \"c\"){chop $_; print \"\\/*$_*\\/\\n\\
";}\n  elsif ($type eq \"perl\"){print \"\\#$_\";}\
\n}\nclose (F);\nif ( $type eq \"c\"){print \"/***\
***************************COPYRIGHT NOTICE*******\
************************/\\n\";}\nif ( $type eq \"\
perl\"){print \"##############################COPY\
RIGHT NOTICE##############################/\\n\";}\
\nif ( $type eq \"txt\"){print \"-----------------\
--------------COPYRIGHT NOTICE--------------------\
----------/\\n\";}\n\n","\nwhile (<>)	\n	{\n	s/\\=\
cc/123456789/g;\n	s/\\bcc/\\$\\(CC\\)/g;\n	s/12345\
6789/\\=cc/g;\n	print $_;\n	}\n\n","$version=\"1.0\
0\";\n$rseed= int(rand(100000))+1;\n\n\nif ( $#ARG\
V==-1)\n  {\n    print \"msa2bootstrap -i <input_f\
ile> -input <seq|msa|matrix|tree> -n <N-Boostrap> \
-o <outtree> -tmode <nj|upgma|parsimony|ml> -dmode\
 <kimura> -alignpg <t_coffee | muscle | clustalw> \
-rtree <file> -stype <prot|cdna|dna> -recompute -s\
ystem <cygwin|unix>\";\n    print \"\\n\\t-i: inpu\
t file, can be sequneces, msa, matrix, trees, type\
 is specified via -input\";\n    print \"\\n\\t-in\
put: Type of input data\";\n    print \"\\n\\t\\tm\
sa: msa in fasta format\";\n    print \"\\n\\t\\ts\
eq: compute an msa with -alignpg\";\n    print \"\\
\n\\t\\tmatrix: phylipp distance matrix fed direct\
ly to method -tmode [caveat: tmode=nj or upgma]\";\
\n    print \"\\n\\t\\ttree: list of newick trees \
directly fed to consence in order to generate a bo\
otstraped tree\";\n    \n    print \"\\n\\t-n: num\
ber of bootstrap replicates\";\n    print \"\\n\\t\
-o: name of the output tree. Files are not overwri\
tten. Use -recompute to overwrite existing file\";\
\n    print \"\\n\\t-tmode: tree mode: nj|upgma|pa\
rsimony|ml\";\n    print \"\\n\\t-dmode: distance \
mode\";\n    print \"\\n\\t-alignpg: program for a\
ligning sequences (t_coffee=default)\";\n    print\
 \"\\n\\t-rtree: replicate tree file (default: no \
file)\";\n    print \"\\n\\t-rmsa: replicate msa f\
ile (default: no file)\";\n    print \"\\n\\t-rmat\
: replicate matrix file (default: no file)\";\n   \
 print \"\\n\\t-stype: sequence type: protein, dna\
 or cdna\";\n    print \"\\n\\t-recompute: force f\
iles to be overwritten\";\n    print \"\\n\\t-syst\
em: cygwin|unix\";\n      \n\n    \n    &my_exit (\
EXIT_FAILURE);\n  }\nforeach $arg (@ARGV){$command\
.=\"$arg \";}\n\nprint \"CLINE: $command\\n\";\n$t\
hreshold=100;\n$trim_msa=0;\n$stype=\"prot\";\npri\
nt \"msa2bootstrap \";\n\n$system=\"cygwin\";\nif(\
($command=~/\\-system (\\S+)/))\n  {\n    $system=\
$1;\n    if ( $system eq \"cygwin\")\n      {\n	$e\
xec_extension=\".exe\";\n      }\n    elsif ( $sys\
tem eq \"unix\")\n      {\n	$exec_extension=\"\";\\
n	print \"system=Unix\";die;\n      }\n    else\n \
     {\n	print \"msa2boostrap: -system=$system is \
an unknown mode [FATAL]\\n\"; die;\n      }\n    \\
n    print \"-system $system \";\n  }\nif(($comman\
d=~/\\-stype (\\S+)/))\n  {\n    $stype=$1;\n  }\n\
print \"-stype=$stype \";\n\n\n\nif(($command=~/\\\
-i (\\S+)/))\n  {\n    $msa=$1;\n    print \"-i $m\
sa \";\n  }\n\nif(($command=~/\\-rtree (\\S+)/))\n\
  {\n    $rtree=$1;\n    print \"-rtree=$rtree \";\
\n  }\n\nif(($command=~/\\-rmsa (\\S+)/))\n  {\n  \
  $rmsa=$1;\n  }\nif(($command=~/\\-rmat (\\S+)/))\
\n  {\n    $rmat=$1;\n  }\n$input=\"seq\";\nif(($c\
ommand=~/\\-input (\\S+)/))\n  {\n    $input=$1;\n\
  }\nprint \"-input=$input \";\n\n$dmode=\"kimura\\
";\nif(($command=~/\\-dmode (\\S+)/))\n  {\n    $d\
mode=$1;\n  }\nprint \"-dmode=$dmode \";\n$alignpg\
=\"muscle\";\nif(($command=~/\\-alignpg (\\S+)/))\\
n  {\n    $alignpg=$1;\n  }\nprint \"-alignpg=$dmo\
de \";\n\n$tmode=\"nj\";\nif(($command=~/\\-tmode \
(\\S+)/))\n  {\n    $tmode=$1;\n  }\nprint \"-tmod\
e=$tmode \";\n$recompute=0;\nif(($command=~/\\-rec\
ompute/))\n  {\n    $recompute=1;\n    print \"-re\
compute \";\n  }\n\n$out=$msa;\n$out=~s/\\..*//;\n\
$out.=\".bph\";\nif(($command=~/\\-o (\\S+)/))\n  \
{\n    $out=$1;\n    \n  }\nprint \"-out=$out \";\\
nif (-e $out && !$recompute)\n  {\n    print \"\\n\
No Computation Required $out already exists\\n\";\\
n    &my_exit (EXIT_SUCCESS);\n    \n  }\n\n$n=100\
;\nif(($command=~/\\-n (\\d+)/))\n  {\n    $n=$1;\\
n  }\nprint \"-n=$n \";\n$seed=3;\nif(($command=~/\
\\-s (\\d+)/))\n  {\n    $seed=$1;\n  }\nprint \"-\
s=$seed \";\n\nif(($command=~/\\-run_name (\\d+)/)\
)\n  {\n    $suffix=$1;\n  }\nelse\n  {\n    $msa=\
~/([^.]+)/;\n    $suffix=$1;\n  }\nprint \"-run_na\
me=$suffix\\n\";\n\n\nif ( $input eq \"seq\")\n  {\
\n    $seq=$msa;\n    $msa=\"$suffix.prot_msa\";\n\
    \n    if ($stype eq \"cdna\")\n      {\n	$cdna\
_seq=$seq;\n	$clean_cdna_seq=&vtmpnam();\n	$seq=&v\
tmpnam();\n	`t_coffee -other_pg seq_reformat -in $\
cdna_seq -action +clean_cdna >$clean_cdna_seq`;\n	\
`t_coffee -other_pg seq_reformat -in $clean_cdna_s\
eq -action +translate >$seq`;\n	\n      }\n\n    i\
f (!-e $msa || $recompute)\n      {\n	print \"\\n#\
####   Compute an MSA With $alignpg\\n\";\n	\n	if \
( $alignpg eq \"t_coffee\")\n	  {`$alignpg $seq -o\
utfile=$msa >/dev/null 2>/dev/null`;}\n	elsif ( $a\
lignpg eq \"muscle\")\n	  {\n	    `$alignpg -in $s\
eq > $msa 2>/dev/null`;\n	  }\n	elsif ( $alignpg e\
q \"clustalw\")\n	  {\n	    `$alignpg -infile=$seq\
 -outfile=$msa -quicktree >/dev/null 2>/dev/null`;\
\n	  }\n	elsif ( $align eq \"mafft\")\n	  {\n	    \
`$alignpg $seq > $msa >/dev/null 2>/dev/null`;\n	 \
 }\n	else\n	  {\n	    `$alignpg -in=$seq -outfile=\
$msa`;\n	  }\n      }\n    if (!-e $msa)\n      {\\
n	print \"\\nError: $alignpg Could Not produce the\
 MSA $msa [FATAL]\\n\";\n      }\n\n    if ($stype\
 eq \"cdna\")\n      {\n	$msa2=\"$suffix.cdna_msa\\
";\n	`t_coffee -other_pg seq_reformat -in $clean_c\
dna_seq -in2 $msa -action +thread_dna_on_prot_aln \
-output fasta_aln  >$msa2`;\n	$msa=$msa2;\n      }\
\n    \n    $input=\"msa\";\n  }\n\n\n\n$seqboot_o\
=&vtmpnam();\n$seqboot_c=&vtmpnam();\n\n$protdist_\
o=&vtmpnam();\n$protdist_c=&vtmpnam();\nif ( $inpu\
t eq \"msa\")\n  {\n    if ($tmode eq \"nj\" || $t\
mode eq \"upgma\"){$input=\"matrix\";}\n    \n    \
$lmsa= &vtmpnam ();\n    `t_coffee -other_pg seq_r\
eformat -in $msa -output phylip_aln > $lmsa`;\n   \
 \n    if ( -e \"outfile\"){unlink (\"outfile\");}\
\n    # run seqboot\n  \n    if ( $n>1)\n      {\n\
	print \"Run SeqBoot .....\";\n	open (F, \">$seqbo\
ot_c\");\n	print F \"$lmsa\\nR\\n$n\\nY\\n$seed\\n\
\";\n	close (F);\n	`seqboot$exec_extension  < $seq\
boot_c`;\n	if ( -e \"outfile\"){ print \"[OK]\\n\"\
;}\n	else { print \"[FAILED]\\n\";&my_exit (EXIT_F\
AILURE);}\n	`mv outfile $seqboot_o`;\n      }\n   \
 else\n      {\n	`cp $lmsa $seqboot_o`;\n      }\n\
\n    if ($rmsa){`cp $seqboot_o $rmsa`;}\n    \n  \
  if ($tmode eq \"nj\" || $tmode eq \"upgma\")\n  \
    {\n	if ( $stype eq \"prot\")\n	  {\n	    # run\
 protdist\n	    print \"Run Protdist [dmode=$dmode\
]\";\n	    if ($dmode eq \"kimura\")\n	      {\n		\
$dmode=\"P\\nP\\nP\";\n	      }\n	    else\n	     \
 {\n		print \"\\n$dmode is an unknown mode for Pro\
tdist [FATAL:msa2bootstrap.pl]\\n\";\n		&my_exit (\
EXIT_FAILURE);\n	      }\n	    open (F, \">$protdi\
st_c\");\n	    if ($n>1){print F \"$seqboot_o\\n$d\
mode\\nM\\nD\\n$n\\nY\\n\";}\n	    else {printf F \
\"$seqboot_o\\n$dmode\\nY\\n\";}\n	    close (F);\\
n	    `protdist$exec_extension  < $protdist_c`;\n	\
    if ( -e \"outfile\"){ print \"[OK]\\n\";}\n	  \
  else { print \"[FAILED]\\n\";&my_exit (EXIT_FAIL\
URE);}\n	    `mv outfile $protdist_o`;\n	 \n	  }\n\
	elsif ( $stype eq \"cdna\" || $stype eq \"dna\")\\
n	  {\n	    print \"Run dnadist [dmode=default\";\\
n	    open (F, \">$protdist_c\");\n	    if ($n>1){\
print F \"$seqboot_o\\nM\\nD\\n$n\\nY\\n\";}\n	   \
 else {printf F \"$seqboot_o\\nY\\n\";}\n	    clos\
e (F);\n	    `protdist$exec_extension  < $protdist\
_c`;\n	    if ( -e \"outfile\"){ print \"[OK]\\n\"\
;}\n	    else { print \"[FAILED]\\n\";&my_exit (EX\
IT_FAILURE);}\n	    `mv outfile $protdist_o`;\n	  \
}\n      }\n  }\nelsif ( $input eq \"matrix\")\n  \
{\n    $protdist_o=&vtmpnam();\n    print \"MSA: $\
msa\\n\";\n    `cp $msa $protdist_o`;\n    $n=1;\n\
  }\n\n\n\n\n\n$nb_o=&vtmpnam();\n$nb_c=&vtmpnam()\
;\nif ($input eq \"matrix\" && $tmode ne \"parsimo\
ny\" && $tmode ne \"ml\")\n  {\n    print \"Run ne\
ighbor [tmode=$tmode]\";\n\n    if ($tmode eq \"nj\
\")\n      {\n	$tmode=\"\\nN\\nN\";\n      }\n    \
elsif ( $tmode eq \"upgma\")\n      {\n	$tmode = \\
"\\nN\";\n      }\n    else\n      {\n	print \"\\n\
 ERROR: $tmode is an unknown tree computation mode\
\\n\";\n	&my_exit (EXIT_FAILURE);\n      }\n\n    \
open (F, \">$nb_c\");\n    if ($n>1){print F \"$pr\
otdist_o$tmode\\nM\\n$n\\n$seed\\nY\\n\";}\n    el\
se {print F \"$protdist_o$tmode\\nY\\n\";}\n    cl\
ose (F);\n\n    `neighbor$exec_extension  < $nb_c`\
;\n    if ( -e \"outtree\"){ print \"[Neighbor OK]\
\\n\";}\n    else { print \"[FAILED]\\n\";&my_exit\
 (EXIT_FAILURE);}\n    `mv outtree $nb_o`;\n    un\
link (\"outfile\");\n  }\nelsif ($input eq \"msa\"\
 && $tmode eq \"parsimony\")\n  {\n    if ( -e \"o\
utfile\"){unlink (\"outfile\");}\n    if ( -e \"ou\
ttree\"){unlink (\"outtree\");}\n    \n    if ($st\
ype eq \"prot\")\n      {\n	print \"Run protpars [\
tmode=$tmode]\";\n	open (F, \">$nb_c\");\n	if ($n>\
1){print F \"$seqboot_o\\nM\\nD\\n$n\\n$seed\\n10\\
\nY\\n\";}\n	else {print F \"$seqboot_o\\nY\\n\";}\
\n	close (F);\n	`protpars$exec_extension  < $nb_c`\
;\n      }\n    elsif ( $stype eq \"dna\" || $styp\
e eq \"cdna\")\n      {\n	print \"Run dnapars [tmo\
de=$tmode]\";\n	open (F, \">$nb_c\");\n	if ($n>1){\
print F \"$seqboot_o\\nM\\nD\\n$n\\n$seed\\n10\\nY\
\\n\";}\n	else {print F \"$seqboot_o\\nY\\n\";}\n	\
close (F);\n	`dnapars$exec_extension  < $nb_c`;\n \
     }\n    if ( -e \"outtree\"){ print \"[OK]\\n\\
";}\n    else { print \"[FAILED]\\n\";&my_exit (EX\
IT_FAILURE);}\n    `mv outtree $nb_o`;\n   unlink \
(\"outfile\");\n  }\nelsif ($input eq \"msa\" && $\
tmode eq \"ml\")\n  {\n    if ( -e \"outfile\"){un\
link (\"outfile\");}\n    if ( -e \"outtree\"){unl\
ink (\"outtree\");}\n    \n    if ($stype eq \"pro\
t\")\n      {\n	print \"Error: ML impossible with \
Protein Sequences [ERROR]\";\n	&my_exit (EXIT_FAIL\
URE);\n      }\n    elsif ( $stype eq \"dna\" || $\
stype eq \"cdna\")\n      {\n	print \"Run dnaml [t\
mode=$tmode]\";\n	open (F, \">$nb_c\");\n	if ($n>1\
){print F \"$seqboot_o\\nM\\nD\\n$n\\n$seed\\n10\\\
nY\\n\";}\n	else {print F \"$seqboot_o\\nY\\n\";}\\
n	close (F);\n	`dnaml$exec_extension  < $nb_c`;\n \
     }\n    if ( -e \"outtree\"){ print \"[OK]\\n\\
";}\n    else { print \"[FAILED]\\n\";&my_exit (EX\
IT_FAILURE);}\n    `mv outtree $nb_o`;\n   unlink \
(\"outfile\");\n  }\n\n\nelse\n  {\n    `cp $msa $\
nb_o`;\n    $n=2;\n  }\n\nif ($rmsa && -e $seqboot\
_o){print \"\\nOutput List of $n Replicate MSA: $r\
msa\\n\";`cp $seqboot_o $rmsa`;}\nif ($rmat && -e \
$protdist_o){print \"\\nOutput List of $n Replicat\
e MATRICES: $rmat\\n\";`cp $protdist_o $rmat`;}\ni\
f ($rtree && -e $nb_o){print \"\\nOutput List of $\
n Replicate TREES: $rtree\\n\";`cp $nb_o $rtree`;}\
\n\n\n\n$con_o=&vtmpnam();\n$con_c=&vtmpnam();\nif\
 ($n >1)\n  {\n    print \"Run Consense.....\";\n \
   open (F, \">$con_c\");\n    print F \"$nb_o\\nY\
\\n\";\n    close (F);\n    `consense$exec_extensi\
on  < $con_c`;\n    if ( -s \"outtree\"  > 0) { pr\
int \"[OK]\\n\";}\n    else { print \"[FAILED]\\n\\
";&my_exit (EXIT_FAILURE);}\n    `mv outtree $con_\
o`;\n    unlink (\"outfile\");\n  }\nelse\n  {\n  \
  `cp $nb_o $con_o`;\n  }\n\n\n`cp $con_o $out`;\n\
if ( !-e $out)\n  {\n    print \"Tree Computation \
failed [FAILED]\\n\";\n    &my_exit (EXIT_FAILURE)\
;\n  }\nelsif ($n>1)\n  {\n    print \"\\nOutput B\
ootstrapped Tree: $out\\n\";\n    $avg=`t_coffee -\
other_pg seq_reformat -in $out -action +avg_bootst\
rap`;\n    $avg=~s/\\n//g;\n    print \"$avg\\n\";\
\n  }\nelse\n  {\n    print \"\\nOutput Tree: $out\
\\n\";\n  }\n\nopen (F, \"$out\");\nwhile (<F>)\n \
 {\n    \n    $tree.=$_;\n  }\nclose (F);\n$tree=~\
s/\\n//g;\nprint \"BPH: $tree\\n\";\n\n\n&my_exit \
(EXIT_SUCCESS);\n\nsub my_exit \n  {\n    my $m=@_\
[0];\n    &clean_vtmpnam();\n    exit ($m);\n  }\n\
sub vtmpnam \n  {\n    my $file;\n\n\n    $ntmp++;\
\n    $file=\"tmp4msa2bootstrap.$rseed.$$.$ntmp\";\
\n    \n    push (@tmpfile, $file);\n    return $f\
ile;\n  }\nsub clean_vtmpnam \n  {\n    my $t;\n  \
  foreach $t (@tmpfile)\n      {\n	if ( -e $t){unl\
ink ($t)};\n      }\n  }\n","use Env;\n$seq_reform\
at=\"t_coffee -other_pg seq_reformat \";\n$Version\
Tag=\"1.00\";\n$step=1;\n$unset=\"\";\n$scoreT1=$s\
coreT2=$nseqT=$dp_limit=$unset;\n@tl=();\nchomp($t\
c_version=`t_coffee -version`);$tc_version=~s/PROG\
RAM: //;\n\n\nprint STDERR \"\\n******************\
***********************************************\";\
\nprint STDERR \"\\n*           HIGH LEVEL PROGRAM\
: T-COFFEE_DPA Version $VersionTag\";\nprint STDER\
R \"\\n*           LOW  LEVEL PROGRAM: $tc_version\
 \";\nprint STDERR \"\\n**************************\
***************************************\";\n\nif (\
!@ARGV)\n  {\n    print \"t_coffee_dpa accepts eve\
ry t_coffee_flag.\\nType t_coffee to obtain a list\
\\n\";\n    print \"Requires $TC_VERSION\\n\";\n  \
  print \"Requires \";\n    print \"t_coffee_dpa s\
pecific flags:\\n\";\n    print \"\\t-dpa_master_a\
ln....................Master alignment: provided O\
R computed\\n\";\n    print \"\\t-dpa_master_aln..\
..................By default, Computed with t_coff\
ee -very_fast\\n\";\n    print \"\\t-dpa_master_al\
n=<file>.............Use file, (must be an aln in \
Fasta or ClustalW\\n\";\n    print \"\\t-dpa_maste\
r_aln=<program>..........Compute aln with pg -in s\
eq -out aln`\\n\";\n    print \"\\t-dpa_maxnseq...\
....................Maximum number of sequences in\
 subgroups\\n\";\n    print \"\\t-dpa_min_score1..\
..................Minimum Id for two sequences to \
be grouped in ref_aln\\n\";\n    print \"\\t-dpa_m\
in_score2....................Minimum Id within a s\
ubgroup\\n\";\n    print \"\\t-dpa_debug..........\
...............Keep Tmp File (for debug purpose)\\\
n\\n\";\n    \n    exit (0);\n  }\nforeach $arg (@\
ARGV)\n  {\n    $arg_list.=\" $arg\";\n  }\n$arg_l\
ist=~s/[=,;]/ /g;\n\n\n($seq0, $arg_list)=&extract\
_val_from_arg_list(\"^\",$arg_list, \"SPLICE\",\"u\
nset\");\n($seq1, $arg_list)=&extract_val_from_arg\
_list(\"-seq\",$arg_list, \"SPLICE\",\"unset\");\n\
($seq2, $arg_list)=&extract_val_from_arg_list(\"-i\
n\",$arg_list, \"KEEP\",\"unset\");\n($seq3, $arg_\
list)=&extract_val_from_arg_list(\"-infile\",$arg_\
list, \"SPLICE\",\"unset\");\n($prf,  $arg_list)=&\
extract_val_from_arg_list(\"-profile\",$arg_list, \
\"SPLICE\",\"unset\");\n\n$gl{'Seq'}=$seq=&vtmpnam\
();#file containing all the sequences\n\n   #1-rem\
ove sequences from -in\nif ( $arg_list =~/\\-in\\b\
/)\n  {\n    my $save, $name;\n    while($arg_list\
=~/\\-in\\b[^-]+(\\bS[\\w.]+)/)\n      {\n	$name=$\
1;$name=~s/^.//;\n	if ( !-e $name){$save.=\" S$nam\
e \";}\n\n	$arg_list=~s/S$name/ /;\n      }\n    $\
arg_list=~s/\\-in\\b/\\-in $save /;\n  }\n   #2-pr\
epare \n\nif (!($arg_list=~/\\-outorder/))\n  {\n \
   \n    $output_cl .=\" -outorder=$seq\";\n  }\n@\
output_flag=(\"-output\",\"-outfile\", \"-run_name\
\", \"-outorder\"); \nforeach $v1 (@output_flag)\n\
  {\n    ($v2, $arg_list)=&extract_val_from_arg_li\
st($v1,$arg_list, \"SPLICE\",\"unset\");\n    if (\
$v2 ne \"\")\n      {\n\n	if ($v1 eq \"-run_name\"\
){$run_name=$v2;$output_cl .=\" $v1 $v2 \";}\n	els\
if ( $v1 eq \"-outorder\")\n	  {\n	    if ( $v2 eq\
 \"input\"){$v2=$seq;}\n	    $outorder=$v2;$output\
_cl .=\" $v1 $v2 \";\n	  }\n	else\n	  {\n	    $out\
put_cl .=\" $v1 $v2 \";\n	  }\n      }\n }\n\n\n($\
dpa_master_aln, $arg_list)  =&extract_val_from_arg\
_list(\"-dpa_master_aln\",$arg_list, \"SPLICE\", \\
"t_coffee\");\n$dpa_master_aln=~s/\\s//g;\n($nseqT\
, $arg_list)           =&extract_val_from_arg_list\
(\"-dpa_maxnseq\",$arg_list, \"SPLICE\", 30);\n($s\
coreT1, $arg_list)         =&extract_val_from_arg_\
list(\"-dpa_min_score1\",$arg_list, \"SPLICE\", 80\
);\n($scoreT2, $arg_list)         =&extract_val_fr\
om_arg_list(\"-dpa_min_score2\"    ,$arg_list, \"S\
PLICE\", 30);\n($dpa_limit, $arg_list)       =&ext\
ract_val_from_arg_list(\"-dpa_limit\"        ,$arg\
_list, \"SPLICE\", 0);\n($dpa_delta_id, $arg_list)\
    =&extract_val_from_arg_list(\"-dpa_delta_id\" \
       ,$arg_list, \"SPLICE\", 1);\n($dpa_debug, $\
arg_list)       =&extract_val_from_arg_list(\"-dpa\
_debug\"           ,$arg_list, \"SPLICE\", 0);\n\n\
\n$in_seq=$seq0.\" \".$seq1.\" \".$seq2.\" \".$seq\
3;\n$in_prf=(($prf ne $unset)?\"$prf \":\"\");\n&e\
xit_dpa (($in_seq eq \"\" && $in_prf eq \"\")?1:0,\
 \"ERROR: You did not Provide any sequences. Use t\
he -seq flag [FATAL: t_coffee_dpa]\\n\", EXIT_FAIL\
URE);\n\n\nprint STDERR \"\\nSTART DPA COMPUTATION\
\";\n\n\n\nif ($in_seq=~/\\S+/)\n  {\n    \n    pr\
int STDERR \"\\n Step $step: Gather all the sequen\
ces into the tmp file: [$seq]\";$step++;	\n    &my\
_system (\"t_coffee $in_seq -convert -quiet -outpu\
t fasta_seq -outfile=$seq -maxnseq 0\");\n  }\n\ni\
f ( !-e $seq){$seq=\"\";}\n\nif ($in_prf=~/\\S+/)\\
n  {\n    $seq_in_type=\"profile\"; \n    $seq.= $\
in_prf; \n  }\nif ($seq eq \"\"){ &exit_dpa (1, \"\
\\nERROR: No Sequence FOund. Provide Sequences wit\
h the -seq flag [FATAL: t_coffee_dpa]\", EXIT_FAIL\
URE);}\n\n \n\nif ( $run_name)\n  {\n    $suffix=$\
run_name;\n  }\nelsif ($in_seq=~/\\b(S[\\w.]+\\b)/\
)\n  {\n    my $suffix1, $sufffix2;\n    $suffix1=\
$suffix2=$1;\n    $suffix2=~s/^S//;\n    if ( -e $\
suffix1){$suffix=$suffix1;}\n    elsif ( -e $suffi\
x2){$suffix=$suffix2;}\n    else\n      {\n	$suffi\
x=&vtmpnam();	\n      }\n    $suffix=~s/\\.\\w+//;\
\n  }\n\nelse\n  {\n    $suffix=&vtmpnam();\n  }\n\
\n\nif (!$run_name){$output_cl.=\" -run_name $suff\
ix \";}\n\n\n$gl{'Tree'}=&seq2dpa_tree ($seq, \"$s\
uffix.dpadnd\");\n\nprint STDERR \"\\n Step $step:\
 Prepare guide tree: $gl{'Tree'}\";$step++;\n\npri\
nt STDERR \"\\n Step $step: Identify and Align Clo\
sely Related Groups\";$step++;\n%gl=&make_one_pass\
 (0, $scoreT1,\"Align\",%gl);\n\nprint STDERR \"\\\
n Step $step: Make Multiple Group Alignment\";$ste\
p++;\nwhile (!%gl ||$gl{'Ng'}>$nseqT)\n  {\n    %g\
l=&make_one_pass ($nseqT, $scoreT2,\"t_coffee\",%g\
l);\n    if ( $gl{'Newgroups'}==0){$scoreT2--;}   \
 \n  }\nprint STDERR \"\\n Step $step: Make The Fi\
nal Alignment\";$step++;\n\n\n$arg_list .=$output_\
cl;\n\n\n%gl=&tree2group (0,0, %gl);\n$gl{$gl{'0'}\
{'File'}}{'Output'}=\"\";\n$a=0;\n&align_groups (\\
"t_coffee\",'0', $arg_list, \" \", %gl);\n\n\n\nif\
 ( !$dpa_keep_tmpfile){&clean_tmp_file (@tl);}\n\n\
\n\nsub seq2dpa_tree \n  {\n    my $seq=@_[0];\n  \
  my $newtree=@_[1];\n    my $aln=&vtmpnam ();\n\n\
    &my_system (\"t_coffee -special_mode quickaln \
-in $seq -outfile $aln -quiet\");\n    &my_system \
(\"$seq_reformat -in $aln -action +aln2tree +tree2\
dpatree -output newick >$newtree\");\n    return $\
newtree;\n  }	\nsub seq2dpa_tree_old \n  {\n    my\
 $aln=@_[0];\n    my $newtree=@_[1];\n    \n    \n\
    &my_system(\"$seq_reformat -in $aln -action +s\
eq2dpatree -output newick > $newtree\");\n    retu\
rn $newtree;\n  }\nsub aln2dpa_tree \n  {\n    my \
$aln=@_[0];\n    my $newtree=&vtmpnam();\n    \n  \
  &my_system(\"$seq_reformat -in $aln -action +aln\
2tree +tree2dpatree -output newick > $newtree\");\\
n    return $newtree;\n  }\nsub group_file2ngroups\
\n  {\n    my $file=@_[0];\n    my $n;\n    \n    \
open ( F, $file);\n    while (<F>)\n      {\n	$n+=\
/\\>/;\n      }\n    close (F);\n    return $n;\n \
 }\n\nsub make_one_pass\n  {\n    my ($N, $ID,$pg,\
 %gl)=@_;\n    my $a;\n\n    %gl=&tree2group ($N,$\
ID,%gl);\n    if (!$gl{'Newgroups'}){return %gl;}\\
n    else\n      {\n	for ( $a=0; $a< $ng; $a++)\n	\
  {\n	    if ($gl{$gl{$a}{'File'}}{'Ng'}>1){&displ\
ay_group($a, %gl);}\n	    &align_groups ($pg, $a, \
$arg_list, \" -quiet=quiet \", %gl);\n	  }\n	retur\
n %gl;\n      }\n  }\n\nsub tree2group \n  {\n    \
my ($N, $ID, %gl)=@_;\n    my $prefix=&vtmpnam();\\
n    my $group_file=&vtmpnam();\n    my $file;\n  \
  my $oldtree=&vtmpnam();\n    my $n;\n    my $tre\
e;\n\n\n    if ( $gl{'Ng'}==1){return %gl;}\n    $\
tree=$gl{'Tree'}; \n    \n    #1 extract the group\
s\n    &my_system (\"$seq_reformat -in $tree -acti\
on +tree2group $N $ID $prefix > $group_file\");\n \
   $n=group_file2ngroups($group_file);\n    \n    \
\n    $gl{'Newgroups'}=1;\n    if ( $n==$gl{'Ng'})\
\n      {\n	$gl{'Newgroups'}=0;\n	return %gl;\n   \
   }\n    $gl{'Iteration'}++;\n    $gl{'MaxNseq'}=\
$N;$gl{'MinID'}=$ID;\n    $gl{'GroupFile'}=$group_\
file;$gl{'Ng'}=$ng=0;\n    #2 Process the group li\
st into the hash\n    open (F, $group_file);\n    \
while (<F>)\n      {\n	$gl{'File'}.=$_;\n	if (/\\>\
/)\n	  {\n	    $line=$_;\n	    $line=~s/\\>//;\n	 \
   @list=($line=~/(\\S+)/g);\n	    $file=$gl{$ng}{\
'File'}=shift @list;\n	    $gl{$file}{'Output'}=$f\
ile;\n	    \n	    $gl{$file}{'Ng'}=$#list+1;\n	   \
 if ($gl{$file}{'Ng'}>1){ $gl{$file}{'Tlist'}=$gl{\
$file}{'Alist'}=\"(\";}\n	    foreach $l (@list)\n\
	      {\n	\n		$gl{$file}{'List'}.=\" $l \";\n		\n\
		if (!$gl{$l}{'Tlist'})\n		  {\n		    $gl{$l}{'Tl\
ist'}=\"$l\";\n		    $gl{$l}{'Alist'}=\"$l\";\n		 \
   $gl{$l}{'Nseq'}=1;\n		    $gl{$l}{'Ng'}=1;\n		 \
 }\n		$gl{$file}{'Tlist'}.=\"$gl{$l}{'Tlist'},\";\\
n		$gl{$file}{'Alist'}.=\"$gl{$l}{'Tlist'}|\";\n		\
$gl{$file}{'Nseq'}+=$gl{$l}{'Nseq'};\n	      }\n	 \
   \n\n	    chop($gl{$file}{'Tlist'});chop($gl{$fi\
le}{'Alist'});\n	    if ($gl{$file}{'Ng'}>1){$gl{$\
file}{'Tlist'}.=\")\"; $gl{$file}{'Alist'}.=\");\"\
;}\n	    $ng++;\n	  }	\n      }\n    $gl{'Ng'}=$ng\
;\n    close (F);\n    \n    #3 Update the old tre\
e with the new groups\n    $gl{'Tree'}=&vtmpnam();\
\n    &my_system (\"$seq_reformat -in $tree -actio\
n +collapse_tree $group_file -output newick > $gl{\
'Tree'}\");\n    \n    return %gl;\n  }\n\nsub dis\
play_group \n  {\n    my ($g,%gl)=@_;\n    my $f;\\
n    \n    if ( $g==-1)\n      {\n	print STDERR \"\
\\nIteration $gl{'Iteration'} [MaxN=$gl{'MaxNseq'}\
][MinID=$gl{'MinID'}]\";\n      }\n    else\n     \
 {\n\n	$f=$gl{$g}{'File'};\n	$action=($gl{$f}{'Ng'\
}==1 || $gl{'Iteration'}==1)?\"KEEP  \":\"ALIGN \"\
;\n        print STDERR \"\\n\\t[$action][MaxN=$gl\
{'MaxNseq'}][MinID=$gl{'MinID'}][File $f][Nseq=$gl\
{$f}{'Nseq'}][Ngroups=$gl{$f}{'Ng'}][$gl{$f}{'Alis\
t'}]\";\n      }\n  }\n      \n\n\nsub align_group\
s\n  {\n    my ($pg, $g, $arg, $extra_arg,%gl)=@_;\
\n    my $f;\n    my $Output,$Outflag;\n    \n    \
\n    $f=$gl{$g}{'File'};\n    $Output=($gl{$f}{'O\
utput'});\n    \n    if ( $pg eq \"Align\")\n     \
 {\n	if ( !-e $f)\n	  {\n	    $command=\"$seq_refo\
rmat -in $gl{'Seq'}  -action +extract_aln $gl{'Gro\
upFile'}\";\n	    if ($gl{$f}{'Ng'}>1)\n	      {\n\
		&my_system ($command);\n		$command=\"t_coffee -s\
pecial_mode quick_aln  S$f -outfile=$Output -quiet\
\";\n	      }\n	  }\n	else \n	  {$command=\"\";}\n\
      }\n    elsif ( -e $f)\n      {	\n	$Outflag=(\
$Output)?\"-outfile=$Output\":\"\";\n	$command=\"$\
pg -infile $f $Outflag -quiet stdout $arg $extra_a\
rg -maxnseq 0 -convert -quiet stdout\";\n      }\n\
    elsif ( $gl{$f}{'Ng'}==1)\n      {\n	$action=(\
$dpa_debug)?\"cp\":\"mv\";\n	$command=\"$action $g\
l{$f}{'List'} $Output\";\n      }\n    else\n     \
 {\n	$Outflag=($Output)?\"-outfile=$Output\":\"\";\
\n	$command=\"$pg -profile $gl{$f}{'List'} $Outfla\
g $arg $extra_arg -maxnseq 0\";\n      }\n    \n  \
  &my_system ($command);\n    return $outfile;\n  \
}\n    \nsub my_system \n  {\n    my $command=@_[0\
];\n    my $force=@_[1];\n    my $status;\n\n    i\
f ( $dpa_debug) {print STDERR \"\\nCOMMAND: $comma\
nd\";}\n    $status=system ($command);\n\n    if (\
!$force)\n       {\n	 &exit_dpa (($status==1), \"F\
ailed in Command:\\n$command\\n[FATAL: t_coffee_dp\
a]\\n\", EXIT_FAILURE);\n       }\n    \n    retur\
n $status;\n  }\n\nsub vtmpnam\n  {\n    my $prefi\
x=@_[0];\n    my $tmp_file_name;\n\n    $tmp_prefi\
x=($prefix)?$prefix:\"dpa_tmp_file_$$\";\n   \n   \
 $tmp_count++;\n    $tmp_file_name=\"$tmp_prefix\"\
.\"$tmp_count\";\n    $tl[$#tl+1]=$tmp_file_name;\\
n    return $tmp_file_name;\n  }\n\nsub clean_tmp_\
file\n  {\n\n    my $list;\n    my $file;\n    \n \
   if ($dpa_debug){return;}\n    $list=vtmpnam();\\
n    `ls -1 | grep $tmp_prefix>$list`;\n    \n    \
open (F,$list);\n    while ( <F>)\n      {\n	$file\
=$_;\n	chop $file;\n	if ( -e $file){unlink $file;}\
\n      }\n    close (F);\n    unlink $list;\n  }\\
n\n\nsub exit_dpa\n  {\n  my $condition=@_[0];\n  \
my $error_msg=@_[1];\n  my $exit_value=@_[2];\n  i\
f ( $condition)\n    {\n      print \"$error_msg\\\
n\";\n      exit ($exit_value);\n    }\n  else\n  \
  {\n      return;\n    }\n  \n}\nsub extract_val_\
from_arg_list\n  {\n    my $arg=@_[0];\n    my $ar\
g_list=@_[1];\n    my $keep_flag=@_[2];\n    my $d\
efault_value=@_[3];\n    my $val=\"\";\n    \n    \
#protect\n    $arg_list=~s/\\s-/ \\@/g;\n    $arg=\
~s/-/\\@/g;\n    \n    #search\n    if ($arg eq \"\
^\")\n      {\n	$arg_list=~/^([^@]*)/;\n	$val=$1;\\
n      }\n    else\n      {$arg_list=~/$arg ([^@]*\
)/;$val=$1;}\n    \n    #remove trailing spaces\n \
   $val=~s/\\s*$//;\n    \n    #remove the parsed \
sequence if needed\n    if (($val ne \"\") && $kee\
p_flag ne \"KEEP\")\n      {\n	if ( $arg eq \"^\")\
{$arg_list=~s/$val/ /;}\n	else {$arg_list=~s/($arg\
 [^@]*)/ /;}\n      }\n	\n    #unprotect\n    $arg\
_list=~s/\\@/-/g;\n    $arg=~s/\\@/-/g;\n    \n   \
 if (($val eq \"\") && $default_value ne \"unset\"\
){$val=$default_value;}\n    \n    return $val, $a\
rg_list;\n  }\n$program=\"T-COFFEE (Version_12.00.\
7fb08c2)\";\\n\n","\n$DEBUG=1;\n$dpa_nseq=10;\n$dp\
a_sim=0;\nif (!@ARGV)\n  {\n    `t_coffee`;\n    e\
xit (0);\n  }\nforeach $arg (@ARGV)\n  {\n    $arg\
_list.=\" $arg\";\n  }\n$max_nseq=10;\n($seq0, $ar\
g_list)=&extract_val_from_arg_list(\"^\",$arg_list\
);\n($seq1, $arg_list)=&extract_val_from_arg_list(\
\"-seq\",$arg_list);\n($seq2, $arg_list)=&extract_\
val_from_arg_list(\"-in\",$arg_list, \"KEEP\");\n(\
$seq3, $arg_list)=&extract_val_from_arg_list(\"-in\
file\",$arg_list);\n$in_seq=$seq0.\" \".$seq1.\" \\
".$seq2.\" \".$seq3;\n\n$seq=vtmpnam();\n`t_coffee\
 $in_seq -convert -output fasta_seq -outfile=$seq`\
;\n\n\n($dpa_nseq, $arg_list)=&extract_val_from_ar\
g_list(\"-dpa_nseq\",$arg_list);\n($master_aln, $a\
rg_list)=&extract_val_from_arg_list(\"-master_aln\\
",$arg_list);\n($sim_matrix, $arg_list)=&extract_v\
al_from_arg_list(\"-sim_matrix\",$arg_list);\n($co\
re_seq, $arg_list)=&extract_val_from_arg_list(\"-c\
ore_seq\",$arg_list);\n($dpa_sim, $arg_list)=&extr\
act_val_from_arg_list(\"-dpa_sim\",$arg_list);\n($\
run_name, $arg_list)=&extract_val_from_arg_list(\"\
-run_name\",$arg_list);\n($output, $arg_list)=&ext\
ract_val_from_arg_list(\"-output\",$arg_list);\n\n\
\n\nif (!$sim_mat && !$master_aln)#Compute the fas\
t alignment\n  {\n    $ref_aln=vtmpnam();\n    `t_\
coffee -seq=$seq -very_fast -outfile=$ref_aln -qui\
et`;\n    \n  }\n\nif (!$sim_mat)\n  {\n    $sim_m\
at=vtmpnam();\n    `seq_reformat -in $ref_aln -out\
put sim > $sim_mat`;\n  }\n\nif ( !$core_seq)\n  {\
\n    $core_seq=vtmpnam();\n    `seq_reformat -in \
$ref_aln -action +trimTC N$max_nseq -output fasta_\
seq > $core_seq`;\n  }\n@core_name=`seq_reformat -\
in $core_seq -output name `; \n\n@tot_name=`seq_re\
format -in $seq -output name `;\n\nforeach $s (@co\
re_name){$s=~s/\\s//g;$hcore{$s}=1;}\nforeach $s (\
@tot_name){$s=~s/\\s//g;}\nprint STDERR \"T-Coffee\
_dpa:\\n\";\nprint STDERR \"\\tTOTAL  SEQ: @tot_na\
me\\n\";\nprint STDERR \"\\tCHOSEN SEQ: @core_name\
\\n\";\n\n\n\nopen (F, $sim_mat);\nwhile ( <F>)\n \
 {\n    @l=($_=~/(\\b[\\S]+\\b)/g);\n    if (($l[0\
] eq \"TOP\" || $l[0] eq \"BOT\"))\n      {\n	$s1=\
$l[1];$s2=$l[2];$v=$l[3];\n	if ($hcore{$s1} && !$h\
core{$s2})\n	  {\n	    if (!$hseq{$s2}{\"sim\"} ||\
 $v>$hseq{$s2}{\"sim\"})\n	      {\n		$hseq{$s2}{\\
"sim\"}=$v;$hseq{$s2}{\"seq\"}=$s1;\n	      }\n	  \
}\n      }\n  }\nclose (F);\nforeach $s (@tot_name\
)\n  {\n\n    if ( !$hseq{$s}{\"seq\"}){;}\n    el\
se\n      {\n	$s2=$hseq{$s}{\"seq\"};\n	$v=$hseq{$\
s}{\"sim\"};\n		\n	if ($v>$dpa_sim)\n	  {\n	    $h\
seq{$s}{'used'}=1;\n	    $seq_list{$s2}{$seq_list{\
$s2}{'nseq'}++}=$s;\n	  }\n      }\n  }\nforeach $\
s (@core_name){$seq_list{$s}{$seq_list{$s}{'nseq'}\
++}=$s;$hseq{$s}{'used'}=1;}\nforeach $s (@tot_nam\
e){if (!$hseq{$s}{'used'}){$seq_list{'unused'}{$se\
q_list{'unused'}{'nseq'}++}=$s;}}\n\n\n$n=0;\nfore\
ach $s (@core_name)\n  {\n    $ng++;\n    $n=$seq_\
list{$s}{'nseq'};\n    for (@g_list=(), $a=0; $a<$\
n; $a++){@g_list=(@g_list,$seq_list{$s}{$a});}\n\n\
    $g_seq=vtmpnam();\n    $g_aln=vtmpnam();\n    \
\n    print STDERR \"Group $ng: $#g_list Seq: @g_l\
ist: \";\n    \n    \n    `seq_reformat -in $seq -\
action +lower +keep_name +extract_seq  @g_list -ou\
tput fasta_seq > $g_seq`;\n    \n    \n    if ( $#\
g_list==0)\n      {\n	print STDERR \"[No aln]\\n\"\
;\n	$g_aln=$g_seq;\n      }\n    elsif ($#g_list<$\
max_nseq) \n      {\n	print STDERR \"[t_coffee]\\n\
\";\n	`t_coffee $g_seq -outfile=$g_aln -quiet $arg\
_list`;\n      }\n    else\n      {\n	print STDERR\
 \"[t_coffee_dpa]\\n\";\n	`t_coffee_dpa2 $g_seq -o\
utfile=$g_aln $arg_list -sim_matrix $sim_matrix -d\
pa_nseq $dpa_nseq`;\n      }\n    @profile_list=(@\
profile_list, $g_aln);\n  }\n\n\nprint \"UNUSED $s\
eq_list{'unused'}{'nseq'}\";\n\nif ($seq_list{'unu\
sed'}{'nseq'})\n    {\n      $prf=vtmpnam();\n    \
  \n      `t_coffee -profile @profile_list $arg_li\
st -outfile=$prf -quiet`;\n      $n=$seq_list{\"un\
used\"}{'nseq'};\n      $new_seq=vtmpnam();\n     \
 $new_prf=vtmpnam();\n      for ($a=0; $a<$n-1; $a\
++)\n	{\n	  $s=$seq_list{\"unused\"}{$a};\n	  prin\
t STDERR \"\\nADD Sequence $s\";\n	  \n	  `seq_ref\
ormat -in $seq -action +lower +keep_name +extract_\
seq $s  -output fasta_seq > $new_seq`;\n	  `t_coff\
ee -profile $prf $new_seq $arg_list -outfile=$new_\
prf`;\n	  `cp $new_prf $prf`;\n	}\n      $s=$seq_l\
ist{\"unused\"}{$a};\n      `seq_reformat -in $seq\
 -action +lower +keep_name +extract_seq $s  -outpu\
t fasta_seq > $new_seq`;\n      @profile_list=($pr\
f, $new_seq);\n    }\n    \n      \nif ($run_name)\
{$arg_list.=\" -run_name $run_name\";}\nelse \n  {\
\n    $in_seq=~/([\\w-]+)/;\n    $arg_list.=\" -ru\
n_name $1\";\n  }\nif ( $output){$arg_list.=\" -ou\
tput $output \";}\n\n`t_coffee -profile @profile_l\
ist $arg_list`;\n\n\n&clean (@tmp_file_list);\n\n\\
nsub vtmpnam\n  {\n    my $tmp_file_name;\n    $tm\
p_name_counter++;\n    $tmp_file_name=\"tmp_file_$\
tmp_name_counter\\_Pid$$\";\n    $tmp_file_list[$n\
tmp_file++]=$tmp_file_name;\n    return $tmp_file_\
name;\n  }\nsub clean\n  {\n  my @fl=@_;\n  my $fi\
le;\n  return;\n\n  foreach $file ( @fl)\n    {\n \
     if ( -e $file){unlink($file);}\n    }\n}\nsub\
 extract_val_from_arg_list\n  {\n    my $arg=@_[0]\
;\n    my $arg_list=@_[1];\n    my $keep_flag=@_[2\
];\n    #protect\n    $arg_list=~s/\\s-/ \\@/g;\n \
   $arg=~s/-/\\@/g;\n    \n    #search\n    if ($a\
rg eq \"^\")\n      {\n	$arg_list=~/^([^@]*)/;\n	$\
val=$1;\n      }\n    else\n      {$arg_list=~/$ar\
g ([^@]*)/;$val=$1;}\n    \n    #remove the parsed\
 sequence if needed\n    if ($val && $keep_flag ne\
 \"KEEP\")\n      {\n	if ( $arg eq \"^\"){$arg_lis\
t=~s/$val/ /;}\n	else {$arg_list=~s/($arg [^@]*)/ \
/;}\n      }\n	\n    #unprotect\n    $arg_list=~s/\
\\@/-/g;\n    $arg=~s/\\@/-/g;\n    \n    return $\
val, $arg_list;\n  }\n\n","use Env;\nuse FileHandl\
e;\nuse Cwd;\nuse File::Path;\nuse Sys::Hostname;\\
n\n\nour $PIDCHILD;\nour $ERROR_DONE;\nour @TMPFIL\
E_LIST;\nour $EXIT_FAILURE=1;\nour $EXIT_SUCCESS=0\
;\n\nour $REFDIR=getcwd;\nour $EXIT_SUCCESS=0;\nou\
r $EXIT_FAILURE=1;\n\nour $PROGRAM=\"tc_generic_me\
thod.pl\";\nour $CL=$PROGRAM;\n\nour $CLEAN_EXIT_S\
TARTED;\nour $debug_lock=$ENV{\"DEBUG_LOCK\"};\nou\
r $debug_generic_method=$ENV{\"DEBUG_GENERIC_METHO\
D\"};\nour $LOCKDIR=$ENV{\"LOCKDIR_4_TCOFFEE\"};\n\
if (!$LOCKDIR){$LOCKDIR=getcwd();}\nour $ERRORDIR=\
$ENV{\"ERRORDIR_4_TCOFFEE\"};\nour $ERRORFILE=$ENV\
{\"ERRORFILE_4_TCOFFEE\"};\n&set_lock ($$);\nif (i\
sshellpid(getppid())){lock4tc(getppid(), \"LLOCK\"\
, \"LSET\", \"$$\\n\");}\nour %RECODE;\nour $RECOD\
E_N;\n\n\n\n\nour $BLAST_MAX_NRUNS=2;\nour $COMMAN\
D;\nour $PIDCHILD;\n\n$REF_EMAIL=\"\";\n$tmp_dir=\\
"\";\n$init_dir=\"\";\n\n\n$test=0;\nif ($test==1)\
\n  {\n    $SERVER=\"NCBI\";\n    $query=$ARGV[0];\
\n    $hitf=$ARGV[1];\n    %s=read_fasta_seq($quer\
y);\n    @sl=keys(%s);\n    &blast_xml2profile (\"\
xx\", $s{$sl[0]}{seq},$maxid,$minid,$mincov, $hitf\
);\n    myexit ($EXIT_FAILURE);\n  }\n\nforeach $v\
(@ARGV){$cl.=\"$v \";}\n$COMMAND=$cl;\n($mode)=&my\
_get_opt ( $cl, \"-mode=\",1,0);\n\n($A)=(&my_get_\
opt ( $cl, \"-name1=\",0,0));\n($B)=(&my_get_opt (\
 $cl, \"-name2=\",0,0));\n($TMPDIR)=(&my_get_opt (\
 $cl, \"-tmpdir=\",0,0));\n($CACHE)=(&my_get_opt (\
 $cl, \"-cache=\",0,0));\n($SERVER)=((&my_get_opt \
( $cl, \"-server=\",0,0)));\n($EMAIL)=((&my_get_op\
t ( $cl, \"-email=\",0,0)));\n\nif (!$A){$A=\"A\";\
}\nif (!$B){$B=\"B\";}\n\n\nif (!$TMPDIR)\n  {\n  \
  $HOME=$ENV{HOME};\n    if ($ENV{TMP_4_TCOFFEE}){\
$TMPDIR=$ENV{TMP_4_TCOFFEE};}\n    else{$TMPDIR=\"\
$HOME/.t_coffee/tmp/\";}\n  }\nif ( ! -d $TMPDIR)\\
n  {\n    mkdir $TMPDIR;\n  }\nif ( ! -d $TMPDIR)\\
n  {\n    print \"ERROR: Could not create temporar\
y dir: $TMPDIR\\n\";\n    myexit ($EXIT_FAILURE);\\
n  }\n\n$EMAIL=~s/XEMAILX/\\@/g;\nif (!$EMAIL)\n  \
{\n    if ($ENV{EMAIL_4_TCOFFEE}){$EMAIL=$ENV{EMAI\
L_4_TCOFFEE};}\n    elsif ($ENV{EMAIL}){$EMAIL=$EN\
V{EMAIL};}\n    else {$EMAIL=$REF_EMAIL;}\n  }\n\n\
($maxid,$minid,$mincov,$trim)=(&my_get_opt ( $cl, \
\"-maxid=\",0,0, \"-minid=\",0,0,\"-mincov=\",0,0,\
 \"-trim=\",0,0));\nif (!$cl=~/\\-maxid\\=/){$maxi\
d=95;}\nif (!$cl=~/\\-minid\\=/){$minid=35;}\nif (\
!$cl=~/\\-mincov\\=/){$mincov=80;}\nif (!$cl=~/\\-\
trim\\=/){$trim;}\n\n\n\n\nif ($mode eq \"seq_msa\\
")\n  {\n    &seq2msa($mode,&my_get_opt ( $cl, \"-\
infile=\",1,1, \"-method=\",1,2, \"-param=\",0,0,\\
"-outfile=\",1,0, \"-database=\",0,0));\n  }\nelsi\
f ( $mode eq \"tblastx_msa\")\n  {\n    &seq2tblas\
tx_lib ($mode,&my_get_opt ( $cl, \"-infile=\",1,1,\
 \"-outfile=\",1,0));\n  }\nelsif ( $mode eq \"tbl\
astpx_msa\")\n  {\n    &seq2tblastpx_lib ($mode,&m\
y_get_opt ( $cl, \"-infile=\",1,1, \"-outfile=\",1\
,0));\n  }\nelsif ( $mode eq \"thread_pair\")\n  {\
\n    &seq2thread_pair($mode,&my_get_opt ( $cl, \"\
-infile=\",1,1, \"-pdbfile1=\",1,1, \"-method=\",1\
,2,\"-param=\",0,0, \"-outfile=\",1,0, ));\n  }\ne\
lsif ( $mode eq \"pdbid_pair\")\n  {\n    &seq2pdb\
id_pair($mode,&my_get_opt ( $cl, \"-pdbfile1=\",1,\
0, \"-pdbfile2=\",1,0, \"-method=\",1,2,\"-param=\\
",0,0, \"-outfile=\",1,0, ));\n  }\nelsif ( $mode \
eq \"pdb_pair\")\n  {\n    &seq2pdb_pair($mode,&my\
_get_opt ( $cl, \"-pdbfile1=\",1,1, \"-pdbfile2=\"\
,1,1, \"-method=\",1,2,\"-param=\",0,0, \"-outfile\
=\",1,0, ));\n  }\nelsif ( $mode eq \"rnapdb_pair\\
")\n{\n    &seq2rnapdb_pair($mode,&my_get_opt ( $c\
l, \"-pdbfile1=\",1,1, \"-pdbfile2=\",1,1, \"-meth\
od=\",1,2,\"-param=\",0,0, \"-outfile=\",1,0, ));\\
n}\nelsif ( $mode eq \"profile_pair\")\n  {\n     \
&seq2profile_pair($mode,&my_get_opt ( $cl, \"-prof\
ile1=\",1,1, \"-profile2=\",1,1, \"-method=\",1,2,\
\"-param=\",0,0, \"-outfile=\",1,0 ));\n  }\nelsif\
 ($mode eq \"pdb_template_test\")\n  {\n    &blast\
2pdb_template_test ($mode,&my_get_opt ( $cl, \"-in\
file=\",1,1));\n\n  }\nelsif ($mode eq \"psi_templ\
ate_test\")\n  {\n    &psiblast2profile_template_t\
est ($mode,&my_get_opt ( $cl, \"-seq=\",1,1,\"-bla\
st=\",1,1));\n\n  }\n\nelsif ( $mode eq \"pdb_temp\
late\")\n  {\n    &blast2pdb_template ($mode,&my_g\
et_opt ( $cl, \"-infile=\",1,1, \"-database=\",1,0\
, \"-method=\",1,0, \"-outfile=\",1,0,\"-pdb_type=\
\",1,0));\n  }\n\nelsif ( $mode eq \"profile_templ\
ate\")\n  {\n\n    &seq2profile_template ($mode,&m\
y_get_opt ( $cl, \"-infile=\",1,1, \"-database=\",\
1,0, \"-method=\",1,0, \"-outfile=\",1,0));\n  }\n\
elsif ( $mode eq \"psiprofile_template\")\n  {\n  \
  &seq2profile_template ($mode,&my_get_opt ( $cl, \
\"-infile=\",1,1, \"-database=\",1,0, \"-method=\"\
,1,0, \"-outfile=\",1,0));\n  }\nelsif ( $mode eq \
\"RNA_template\")\n  {\n    &seq2RNA_template ($mo\
de,&my_get_opt ( $cl, \"-infile=\",1,1,\"-pdbfile=\
\",1,1,\"-outfile=\",1,0));\n  }\nelsif ( $mode eq\
 \"tm_template\")\n  {\n    &seq2tm_template ($mod\
e,&my_get_opt ( $cl, \"-infile=\",1,1,\"-arch=\",1\
,1,\"-psv=\",1,1, \"-outfile=\",1,0));\n  }\nelsif\
 ( $mode eq \"psitm_template\")\n  {\n    &seq2tm_\
template ($mode,&my_get_opt ( $cl, \"-infile=\",1,\
1, \"-arch=\",1,1,\"-psv=\",1,1, \"-outfile=\",1,0\
,\"-database=\",1,0));\n  }\nelsif ( $mode eq \"ss\
p_template\")\n  {\n    &seq2ssp_template ($mode,&\
my_get_opt ( $cl, \"-infile=\",1,1,\"-seq=\",1,1,\\
"-obs=\",1,1, \"-outfile=\",1,0));\n  }\nelsif ( $\
mode eq \"psissp_template\")\n  {\n    &seq2ssp_te\
mplate ($mode,&my_get_opt ( $cl, \"-infile=\",1,1,\
\"-seq=\",1,1,\"-obs=\",1,1, \"-outfile=\",1,0));\\
n  }\n\n\n\nelse\n  {\n    myexit(flush_error( \"$\
mode is an unknown mode of tc_generic_method.pl\")\
);\n  }\nmyexit ($EXIT_SUCCESS);\n\n\nsub seq2ssp_\
template\n  {\n  my ($mode, $infile,$gor_seq,$gor_\
obs,$outfile)=@_;\n  my %s, %h;\n  my $result;\n  \
my (@profiles);\n  &set_temporary_dir (\"set\",$in\
file,\"seq.pep\");\n  %s=read_fasta_seq (\"seq.pep\
\");\n\n\n  open (R, \">result.aln\");\n\n  #print\
 stdout \"\\n\";\n  foreach $seq (keys(%s))\n    {\
\n\n      open (F, \">seqfile\");\n      $s{$seq}{\
seq}=uc$s{$seq}{seq};\n      print (F \">$s{$seq}{\
name}\\n$s{$seq}{seq}\\n\");\n      close (F);\n  \
    $lib_name=\"$s{$seq}{name}.ssp\";\n      $lib_\
name=&clean_file_name ($lib_name);\n\n      if ($m\
ode eq \"ssp_template\"){&seq2gor_prediction ($s{$\
seq}{name},$s{$seq}{seq}, \"seqfile\", $lib_name,$\
gor_seq, $gor_obs);}\n      elsif ($mode eq \"psis\
sp_template\")\n	{\n	  &seq2msa_gor_prediction ($s\
{$seq}{name},$s{$seq}{seq},\"seqfile\", $lib_name,\
$gor_seq, $gor_obs);\n	}\n\n      if ( !-e $lib_na\
me)\n	{\n	  myexit(flush_error(\"GORIV failed to c\
ompute the secondary structure of $s{$seq}{name}\"\
));\n	  myexit ($EXIT_FAILURE);\n	}\n      else\n	\
{\n	  print stdout \"!\\tProcess: >$s{$seq}{name} \
_E_ $lib_name \\n\";\n	  print R \">$s{$seq}{name}\
 _E_ $lib_name\\n\";\n	}\n      unshift (@profiles\
, $lib_name);\n    }\n  close (R);\n  &set_tempora\
ry_dir (\"unset\",$mode, $method,\"result.aln\",$o\
utfile, @profiles);\n}\n\nsub seq2tm_template\n  {\
\n  my ($mode,$infile,$arch,$psv,$outfile,$db)=@_;\
\n  my %s, %h;\n  my $result;\n  my (@profiles);\n\
  &set_temporary_dir (\"set\",$infile,\"seq.pep\")\
;\n  %s=read_fasta_seq (\"seq.pep\");\n\n\n  open \
(R, \">result.aln\");\n\n  #print stdout \"\\n\";\\
n  foreach $seq (keys(%s))\n    {\n      open (F, \
\">seqfile\");\n      print (F \">$s{$seq}{name}\\\
n$s{$seq}{seq}\\n\");\n      close (F);\n      $li\
b_name=\"$s{$seq}{name}.tmp\";\n      $lib_name=&c\
lean_file_name ($lib_name);\n\n      if ($mode eq \
\"tm_template\")\n	{\n	  &safe_system (\"t_coffee \
-other_pg fasta_seq2hmmtop_fasta.pl -in=seqfile -o\
ut=$lib_name -arch=$arch -psv=$psv\");\n	}\n      \
elsif ( $mode eq \"psitm_template\")\n	{\n	  &seq2\
msa_tm_prediction ($s{$seq}{name},$s{$seq}{seq}, $\
db, \"seqfile\", $lib_name,$arch, $psv);\n	}\n    \
  if ( !-e $lib_name)\n	{\n	  myexit(flush_error(\\
"hmmtop failed to compute the secondary structure \
of $s{$seq}{name}\"));\n	  myexit ($EXIT_FAILURE);\
\n	}\n      else\n	{\n	  print stdout \"!\\tProces\
s: >$s{$seq}{name} _T_ $lib_name\\n\";\n	  print R\
 \">$s{$seq}{name} _T_ $lib_name\\n\";\n	}\n      \
unshift (@profiles, $lib_name);\n    }\n  close (R\
);\n  &set_temporary_dir (\"unset\",$mode, $method\
,\"result.aln\",$outfile, @profiles);\n}\n\n\n\nsu\
b seq2RNA_template\n  {\n    \n    my ($mode, $inf\
ile, $pdbfile, $outfile)=@_;\n    my %s, %h ;\n   \
 my $result;\n    my (@profiles);\n    my ($seq_mo\
de, $pdb_mode, $pwd);\n    \n    #use $seq_mode to\
 estimate the template of sequences WITHOUT a PDB\\
n    #use $pdb_mode to estimate the template of se\
quences WITH    a PDB\n\n    $seq_mode=$ENV{\"SEQ2\
TEMPLATE4_F_\"};\n    $pdb_mode=$ENV{\"PDB2TEMPLAT\
E4_F_\"};\n    \n    if (!$pdb_mode){$pdb_mode=\"f\
ind_pair-p\";}\n    if (!$seq_mode){$seq_mode=\"RN\
Aplfold\";}\n    \n    my $cwd = cwd();\n    &set_\
temporary_dir (\"set\",$infile,\"seq.pep\");\n    \
%s=read_fasta_seq (\"seq.pep\");\n    %pdb_templat\
e_h = &read_template_file($pdbfile);\n    my $pdb_\
chain;\n    \n       \n    open (R, \">result.aln\\
");\n    #print stdout \"\\n\";\n    foreach $seq \
(keys(%s))\n      {\n	\n	open (F, \">seqfile\");\n\
	print (F \">$s{$seq}{name}\\n$s{$seq}{seq}\\n\");\
\n	close (F);\n	$pdb_chain = $pdb_template_h{$seq}\
;\n	$lib_name=\"$s{$seq}{name}.rfold\";\n	$lib_nam\
e=&clean_file_name ($lib_name);\n	if ($pdb_templat\
e_h{$seq} eq \"\")\n	  {\n	    if    ($seq_mode eq\
 \"RNAplfold\"){RNAplfold2lib (\"seqfile\", \"$lib\
_name\");}\n	    elsif ($seq_mode eq \"no\"){$lib_\
name=0;}\n	    else\n	      {\n		myexit(add_error \
(EXIT_FAILURE,$$,$$,getppid(), \"seq2RNA_template \
failure::method $seq_mode not available for sequen\
ces without PDB structures\"));\n	      }\n	  }\n	\
elsif ($pdb_template_h{$seq} ne \"\")\n	  {\n	    \
my $pdbf;\n	    if (-e \"$cwd/$pdb_chain\"){$pdbf=\
\"$cwd/$pdb_chain\";}\n	    else {$pdbf=\"$CACHE$p\
db_chain\";}\n	    \n\n	    if($pdb_mode eq \"x3dn\
a-ssr\")\n	      {\n		x3dnassr2lib (\"seqfile\", \\
"$pdbf\", \"$lib_name\");\n	      }\n	    elsif ($\
pdb_mode eq \"find_pair-p\")\n	      {\n		x3dna_fi\
nd_pair2lib (\"seqfile\", \"$pdbf\", \"$lib_name\"\
, \"find_pair -p\");\n	      }\n	    elsif ($pdb_m\
ode eq \"find_pair\")\n	      {\n		x3dna_find_pair\
2lib (\"seqfile\", \"$pdbf\", \"$lib_name\", \"fin\
d_pair\");\n	      }\n	    elsif ($pdb_mode eq \"R\
NAplfold\")\n	      {\n		RNAplfold2lib (\"seqfile\\
", \"$lib_name\");\n	      }\n	    elsif ($pdb_mod\
e eq \"no\"){$lib_name=0;}\n	    else\n	      {\n	\
	myexit(add_error (EXIT_FAILURE,$$,$$,getppid(), \\
"seq2RNA_template failure::Could not find method $\
pdb_mode\"));\n	      }\n	  }\n	if ($lib_name)\n	 \
 {\n	    print stdout \"!\\tProcess: >$s{$seq}{nam\
e} _F_ $lib_name\\n\";\n	    print R \">$s{$seq}{n\
ame} _F_ $lib_name\\n\";\n	    unshift (@profiles,\
 $lib_name);\n	  }\n      }\n    close (R);\n    &\
set_temporary_dir (\"unset\",$mode, $method,\"resu\
lt.aln\",$outfile, @profiles);\n  }\n\n\n\nsub psi\
blast2profile_template_test\n  {\n  my ($mode, $se\
q,$blast)=@_;\n  my %s, %h, ;\n  my ($result,$psib\
last_output,$profile_name,@profiles);\n  my $trim=\
0;\n  my $maxid=100;\n  my $minid=0;\n  my $mincov\
=0;\n  my $maxcov=100;\n\n  %s=read_fasta_seq ($se\
q);\n  open (R, \">result.aln\");\n\n  #print stdo\
ut \"\\n\";\n  foreach $seq (keys(%s))\n    {\n\n \
     open (F, \">seqfile\");\n      print (F \">$A\
\\n$s{$seq}{seq}\\n\");\n      close (F);\n      $\
psiblast_output=$blast;\n      if ( -e $psiblast_o\
utput)\n	{\n	  %profile=blast_xml2profile($s{$seq}\
{name}, $s{$seq}{seq},$maxid, $minid,$mincov,$psib\
last_output);\n\n\n\n	  $profile_name=\"$s{$seq}{n\
ame}.prf\";\n	  $profile_name=&clean_file_name ($p\
rofile_name);\n	  unshift (@profiles, $profile_nam\
e);\n	  output_profile ($profile_name, \\%profile,\
 $trim);\n	  print stdout \"!\\tProcess: >$s{$seq}\
{name} _R_ $profile_name [$profile{n} Seq.] [$SERV\
ER/blast/$db][$CACHE_STATUS]\\n\";\n	  print R \">\
$s{$seq}{name} _R_ $profile_name\\n\";\n	}\n    }\\
n  close (R);\n\n  die;\n}\nsub seq2profile_templa\
te\n    {\n      my ($mode, $infile, $db, $method,\
 $outfile)=@_;\n      if    ($method eq \"psiblast\
\"){return psiblast2profile_template ($mode, $infi\
le, $db, $method, $outfile);}\n      elsif ($metho\
d eq \"blastp\")   {return psiblast2profile_templa\
te ($mode, $infile, $db, $method, $outfile);}\n   \
   elsif ($method eq \"hh\")      {return hh2profi\
le_template ($mode, $infile, $db, $method, $outfil\
e);}\n    }\n\nsub psiblast2profile_template\n  {\\
n  my ($mode, $infile, $db, $method, $outfile)=@_;\
\n  my %s, %h, ;\n  my ($result,$psiblast_output,$\
profile_name,@profiles);\n  &set_temporary_dir (\"\
set\",$infile,\"seq.pep\");\n  %s=read_fasta_seq (\
\"seq.pep\");\n  open (R, \">result.aln\");\n\n  #\
print stdout \"\\n\";\n  foreach $seq (keys(%s))\n\
    {\n      open (F, \">seqfile\");\n      print \
(F \">$A\\n$s{$seq}{seq}\\n\");\n      close (F);\\
n      $psiblast_output=&run_blast ($s{$seq}{name}\
,$method, $db, \"seqfile\",\"outfile\");\n\n      \
if ( -e $psiblast_output)\n	{\n	  my %profile=blas\
t_xml2profile($s{$seq}{name}, $s{$seq}{seq},$maxid\
, $minid,$mincov,$psiblast_output);\n	  unlink ($p\
siblast_output);\n	  \n	  $profile_name=\"$s{$seq}\
{name}.prf\";\n	  $profile_name=&clean_file_name (\
$profile_name);\n	  unshift (@profiles, $profile_n\
ame);\n	  output_profile ($profile_name, \\%profil\
e, $trim);\n	  \n	  print stdout \"!\\tProcess: >$\
s{$seq}{name} _R_ $profile_name [$profile{n} Seq.]\
 [$SERVER/blast/$db][$CACHE_STATUS]\\n\";\n	  prin\
t R \">$s{$seq}{name} _R_ $profile_name\\n\";\n	  \
\n	  \n	}\n      \n    }\n  close (R);\n  \n  \n\n\
  &set_temporary_dir (\"unset\",$mode, $method,\"r\
esult.aln\",$outfile, @profiles);\n}\n\nsub hh2pro\
file_template\n  {\n\n  #for each sequence, build \
a profile, in FASTA, with ungapped querry on top  \
\n  my ($mode, $infile, $db, $method, $outfile)=@_\
;\n  my %s, %h, ;\n  my ($result,$psiblast_output,\
$profile_name,@profiles);\n  &set_temporary_dir (\\
"set\",$infile,\"seq.pep\");\n  %s=read_fasta_seq \
(\"seq.pep\");\n  open (R, \">result.aln\");\n  \n\
  my $hh=$ENV{\"HHSEARCH_4_TCOFFEE\"};\n  if (!$hh\
)\n    {\n      print \"ERROR: HHSEARCH_4_TCOFFEE \
is not set\\n\";\n      myexit ($EXIT_FAILURE);\n \
   }\n  \n  #print stdout \"\\n\";\n  foreach $seq\
 (keys(%s))\n    {\n      my ($profile_name, $nseq\
);\n      open (F, \">seqfile\");\n      print (F \
\">$A\\n$s{$seq}{seq}\\n\");\n      close (F);\n  \
    \n      #This function should input a querry a\
nd a database and return as output a fasta MSA wit\
h quesry on top\n      $profile_name=\"$s{$seq}{na\
me}.prf\";\n      $profile_name=&clean_file_name (\
$profile_name);\n      unshift (@profiles, $profil\
e_name);\n      \n      \n      safe_system  (\"$h\
h -name=$s{$seq}{name} -method=search -db=$db -seq\
=seqfile -outfile=$profile_name\");\n      if (-e \
$profile_name){$nseq=fasta2nseq($profile_name);}\n\
      \n      print stdout \"!\\tProcess: >$s{$seq\
}{name} _R_ $profile_name [$nseq Seq.] [$method/$d\
b][$CACHE_STATUS]\\n\";\n      print R \">$s{$seq}\
{name} _R_ $profile_name\\n\";\n    }\n  close (R)\
;\n  &set_temporary_dir (\"unset\",$mode, $method,\
\"result.aln\",$outfile, @profiles);\n}\n\nsub bla\
st2pdb_template_test\n    {\n      my ($mode,$infi\
le)=@_;\n      my ($maxid,$minid,$mincov);\n      \
$maxid=100;\n      $minid=0;\n      $mincov=0;\n\n\
      print \"$infile\\n\";\n\n      %p=blast_xml2\
profile($s{$seq}{name}, $s{$seq}{seq},$maxid, $min\
id,$mincov,$infile);\n      $c=1;\n      print std\
out \"!\\tProcess: >$s{$seq}{name} [$SERVER/blast/\
$db][$CACHE_STATUS]\\n\";\n      while (!$found &&\
 $c<$p{n})\n	{\n	  $pdbid=&id2pdbid($p{$c}{identif\
yer});\n	  if ( length ($pdbid)>5){$pdbid=id2pdbid\
($p{$c}{definition});}\n\n	  if ( length ($pdbid)>\
5)\n	    {\n	      myexit(add_error (EXIT_FAILURE,\
$$,$$,getppid(), \"BLAST_FAILURE::Could Not Parse \
PDBID ($p{$c}{identifyer},$p{$c}{definition})\"));\
\n	    }\n\n\n	  if (!&pdb_is_released($pdbid))\n	\
    {\n	      print stdout \"\\t\\t**$pdbid [WARNI\
G: PDB NOT RELEASED or WITHDRAWN]\\n\";\n	      $c\
++;\n	    }\n	  elsif (!&pdb_has_right_type ($pdbi\
d,$type))\n	    {\n	      my $ptype=&pdb2type ($pd\
bid);\n	      my $etype=&type2etype($type);\n\n	  \
    print stdout \"\\t\\t**$pdbid [$ptype cannot b\
e used (expected: $etype)]\\n\";\n	      $c++;\n	 \
   }\n	  else\n	    {\n	      $found=1;\n	    }\n	\
}\n\n      if ($found)\n	{\n	  print stdout \"\\t\\
\t >$s{$seq}{name} _P_ $pdbid\\n\";\n	}\n      els\
e\n	{\n	  print stdout \"\\t\\t >$s{$seq}{name} No\
 Template Selected\\n\";\n	}\n      die;\n    }\ns\
ub blast2pdb_template\n  {\n  my ($mode, $infile, \
$db, $method, $outfile,$type)=@_;\n  my %s, %h, ;\\
n  my ($result,$blast_output);\n  &set_temporary_d\
ir (\"set\",$infile,\"seq.pep\");\n  %s=read_fasta\
_seq (\"seq.pep\");\n  open (R, \">result.aln\");\\
n\n\n  #print stdout \"\\n\";\n  foreach $seq (key\
s(%s))\n    {\n      my $c;\n      my $found;\n\n \
     open (F, \">seqfile\");\n      print (F \">$A\
\\n$s{$seq}{seq}\\n\");\n      close (F);\n\n     \
 $blast_output=&run_blast ($s{$seq}{name},$method,\
 $db, \"seqfile\",\"outfile\");\n\n      %p=blast_\
xml2profile($s{$seq}{name}, $s{$seq}{seq},$maxid, \
$minid,$mincov,$blast_output);\n      unlink ($bla\
st_output);\n\n      $c=1;\n      print stdout \"!\
\\tProcess: >$s{$seq}{name} [$SERVER/blast/$db][$C\
ACHE_STATUS]\\n\";\n      while (!$found && $c<$p{\
n})\n	{\n	  $pdbid=&id2pdbid($p{$c}{identifyer});\\
n	  if ( length ($pdbid)>5){$pdbid=id2pdbid($p{$c}\
{definition});}\n\n	  if ( length ($pdbid)>5)\n	  \
  {\n	      myexit(add_error (EXIT_FAILURE,$$,$$,g\
etppid(), \"BLAST_FAILURE::Could Not Parse PDBID (\
$p{$c}{identifyer},$p{$c}{definition})\"));\n	    \
}\n\n\n	  if (!&pdb_is_released($pdbid))\n	    {\n\
	      print stdout \"\\t\\t**$pdbid [PDB NOT RELE\
ASED or WITHDRAWN]\\n\";\n	      $c++;\n	    }\n	 \
 elsif (!&pdb_has_right_type ($pdbid,$type))\n	   \
 {\n	      my $ptype=&pdb2type ($pdbid);\n	      m\
y $etype=&type2etype($type);\n\n	      print stdou\
t \"\\t\\t**$pdbid [$ptype cannot be used (expecte\
d: $etype)]\\n\";\n	      $c++;\n	    }\n	  else\n\
	    {\n	      $found=1;\n	    }\n	}\n\n      if (\
$found)\n	{\n	  print R \">$s{$seq}{name} _P_ $pdb\
id\\n\";\n	  print stdout \"\\t\\t >$s{$seq}{name}\
 _P_ $pdbid\\n\";\n	}\n      else\n	{\n	  print R \
\">$s{$seq}{name}\\n\";\n	  print stdout \"\\t\\t \
>$s{$seq}{name} No Template Selected\\n\";\n	}\n  \
  }\n  close (R);\n  &set_temporary_dir (\"unset\"\
,$mode, $method,\"result.aln\",$outfile);\n}\nsub \
type2etype\n  {\n    my $type=shift;\n    my $etyp\
e;\n\n    if ( $type=~/n/){$etype.=\"NMR \";}\n   \
 if ( $type=~/d/){$etype.=\"diffraction \";}\n    \
if ( $type=~/m/){$etype.=\"model \";}\n    return \
$etype;\n  }\nsub pdb2type\n  {\n     my $pdb=shif\
t;\n     my $f=vtmpnam();\n\n     my $value= &safe\
_system (\"t_coffee -other_pg extract_from_pdb -mo\
del_type $pdb > $f\");\n     my $r=&file2string ($\
f);\n     chomp($r);\n     return $r;\n   }\nsub p\
db_has_right_type\n  {\n    my $pdb=shift;\n    my\
 $type=shift;\n\n    my $f=vtmpnam();\n\n    my $v\
alue= &safe_system (\"t_coffee -other_pg extract_f\
rom_pdb -model_type $pdb > $f\");\n    my $r=&file\
2string ($f);\n    chomp($r);\n\n\n    if ( $r eq \
\"NMR\" && $type=~/n/){return 1;}\n    elsif ( $r \
eq \"diffraction\" && $type=~/d/){return 1;}\n    \
elsif ( $r eq \"model\" && $type=~/m/){return 1;}\\
n    else {return 0;}\n  }\nsub pdb_is_released\n \
 {\n    my $pdb=shift;\n    my $f=vtmpnam();\n\n  \
  $value= &safe_system (\"t_coffee -other_pg extra\
ct_from_pdb -is_released_pdb_name $pdb > $f\");\n \
   my $r=&file2string ($f);\n    chomp($r);\n    r\
eturn $r;\n  }\nsub blast_msa\n  {\n    my ($blast\
,$infile,$db,$outfile)=@_;\n    my ($a, %s1, %s, %\
qs, %qs1);\n    my $seqfile;\n    my $SEQ=new File\
Handle;\n    my $seqfile=\"seqfile\";\n    my @txt\
;\n\n\n    %s1=&read_fasta_seq ($db);\n    %s=&fas\
ta_hash2index_hash(%s1);\n    %qs1=&read_fasta_seq\
 ($infile);\n    %qs=&fasta_hash2index_hash(%qs1);\
\n\n\n    #&safe_system (\"formatdb -i $db\");\n  \
  if ($blast eq \"blastp\"){&safe_system  (\"blast\
all -i $infile -d $db -m7 -p blastp -o io\");}\n  \
  elsif ($blast eq \"blastn\"){&safe_system  (\"bl\
astn -query $infile -db $db -outfmt 5 -word_size 4\
 -out io\");}\n\n    &set_blast_type (\"io\");\n\n\
\n    my %FB=&xml2tag_list (\"io\", \"Iteration\")\
;\n    open (F, \">$outfile\");\n    print F \"! T\
C_LIB_FORMAT_01\\n\";\n    print F \"$s{n}\\n\";\n\
    for ( my $a=0; $a<$s{n}; $a++)\n      {\n	prin\
t F \"$s{$a}{name} $s{$a}{len} $s{$a}{seq}\\n\";\n\
      }\n\n\n    for ( my $a=0; $a<$FB{n}; $a++)\n\
      {\n	my %p=blast_xml2profile ($qs{$a}{name}, \
$qs{$a}{seq},100, 0, 0, $FB{$a}{body});\n	my $quer\
y=$p{0}{name};\n	my $i= $s1{$query}{order}+1;\n	fo\
r (my $b=1; $b<$p{n}; $b++)\n	  {\n	    my $l=leng\
th ($p{$b}{Qseq});\n	    my $hit=$p{$b}{definition\
};\n	    my $Qstart=$p{$b}{Qstart};\n	    my $Hsta\
rt=$p{$b}{Hstart};\n	    my $identity=$p{$b}{ident\
ity};\n	    my @lrQ=split (//,$p{$b}{Qseq});\n	   \
 my @lrH=split (//,$p{$b}{Hseq});\n\n	    my $j= $\
s1{$hit}{order}+1;\n	    #if ( $j==$i){next;}\n	  \
  printf F \"# %d %d\\n\", $i, $j;\n	    #  print \
 F \"\\n$p{$b}{Qseq} ($Qstart)\\n$p{$b}{Hseq} ($Hs\
tart)\";\n	    for ($c=0; $c<$l; $c++)\n	      {\n\
		my $rQ=$lrQ[$c];\n		my $rH=$lrH[$c];\n		my $n=0;\
\n\n		if ($rQ ne \"-\"){$n++, $Qstart++;}\n		if ($\
rH ne \"-\"){$n++; $Hstart++;}\n\n		if ( $n==2)\n	\
	  {\n		    printf F \"\\t%d %d %d\\n\", $Qstart-1\
, $Hstart-1,$identity;\n		  }\n	      }\n	  }\n   \
   }\n    print F \"! SEQ_1_TO_N\\n\";\n    close \
(F);\n    return $output;\n  }\n\nsub blast_msa_ol\
d\n  {\n    my ($infile,$outfile)=@_;\n    my ($a,\
 %seq);\n    %s1=&read_fasta_seq ($infile);\n    f\
oreach $s (keys (%s1))\n      {\n	$i=$s1{$s}{order\
};\n	$s{$i}{name}=$s;\n	$s{$i}{seq}=$s1{$s}{seq};\\
n	$s{$i}{len}=length( $s{$i}{seq});\n	$s{n}++;\n  \
    }\n    &safe_system (\"formatdb -i $infile\");\
\n    &safe_system (\"blastall -i $infile -d $infi\
le -m7 -o io\");\n    &set_blast_type (\"io\");\n\\
n    %FB=&xml2tag_list (\"io\", \"Iteration\");\n\\
n    open (F, \">$outfile\");\n    print F \"! TC_\
LIB_FORMAT_01\\n\";\n    print F \"$s{n}\\n\";\n  \
  for ( $a=0; $a<$s{n}; $a++)\n      {\n	print F \\
"$s{$a}{name} $s{$a}{len} $s{$a}{seq}\\n\";\n     \
 }\n    for ( $a=0; $a<$FB{n}; $a++)\n      {\n	%p\
=blast_xml2profile ($s{$a}{name}, $s{$a}{seq},100,\
 0, 0, $FB{$a}{body});\n	for ($b=1; $b<$p{n}; $b++\
)\n	  {\n	    my $l=length ($p{$b}{Qseq});\n	    m\
y $hit=$p{$b}{definition};\n	    my $Qstart=$p{$b}\
{Qstart};\n	    my $Hstart=$p{$b}{Hstart};\n	    m\
y $identity=$p{$b}{identity};\n	    my @lrQ=split \
(//,$p{$b}{Qseq});\n	    my @lrH=split (//,$p{$b}{\
Hseq});\n	    my $i= $s1{$s{$a}{name}}{order}+1;\n\
	    my $j= $s1{$hit}{order}+1;\n	    #if ( $j==$i\
){next;}\n	    printf F \"# %d %d\\n\", $i, $j;\n	\
    #  print  F \"\\n$p{$b}{Qseq} ($Qstart)\\n$p{$\
b}{Hseq} ($Hstart)\";\n	    for ($c=0; $c<$l; $c++\
)\n	      {\n		my $rQ=$lrQ[$c];\n		my $rH=$lrH[$c]\
;\n		my $n=0;\n\n		if ($rQ ne \"-\"){$n++, $Qstart\
++;}\n		if ($rH ne \"-\"){$n++; $Hstart++;}\n\n		i\
f ( $n==2)\n		  {\n		    printf F \"\\t%d %d %d\\n\
\", $Qstart-1, $Hstart-1,$identity;\n		  }\n	     \
 }\n	  }\n      }\n    print F \"! SEQ_1_TO_N\\n\"\
;\n    close (F);\n    return $output;\n\n  }\n\ns\
ub seq2msa\n  {\n    my ($mode, $infile, $method, \
$param, $outfile,$database)=@_;\n    &set_temporar\
y_dir (\"set\",$infile,\"seq.pep\", $database, \"d\
b.pep\");\n    $param.=\" >/dev/null 2>&1 \";\n\n\\
n    #make sure test.pep is in FASTA\n    &safe_sy\
stem (\"t_coffee -other_pg seq_reformat -in seq.pe\
p -output fasta_seq > x\");\n    `mv x seq.pep`;\n\
\n    if ( $method eq \"blastp\")\n      {\n	&blas\
t_msa (\"blastp\",\"seq.pep\",$database,\"result.a\
ln\");\n      }\n    elsif ( $method eq \"blastn\"\
)\n      {\n	&blast_msa (\"blastn\",\"seq.pep\",$d\
atabase,\"result.aln\");\n      }\n\n    elsif ( $\
method eq \"muscle\")\n      {\n	`muscle -in seq.p\
ep -out result.aln $param`;\n      }\n    elsif ( \
$method eq \"probcons\")\n      {\n	`probcons seq.\
pep >result.aln 2>/dev/null`;\n      }\n    elsif \
( $method eq \"mafft\")\n      {\n	`mafft --quiet \
--localpair --maxiterate 1000 seq.pep> result.aln \
 2>/dev/null`\n      }\n    elsif ( $method=~/pran\
k/)\n      {\n	`$method -d=seq.pep -o=result.aln -\
quiet 2>/dev/null`;\n	`mv result.aln.1.fas result.\
aln`;\n      }\n    elsif ($method eq \"clustalo\"\
)\n      {\n	`clustalo -i seq.pep > result.aln`;\n\
      }\n    else\n      {\n	`$method -infile=seq.\
pep -outfile=result.aln`;\n      }\n\n    &set_tem\
porary_dir (\"unset\",$mode, $method,\"result.aln\\
",$outfile);\n    myexit ($EXIT_SUCCESS);\n  }\n\n\
sub seq2thread_pair\n  {\n    my ($mode, $infile, \
$pdbfile1, $method, $param, $outfile)=@_;\n    &se\
t_temporary_dir (\"set\",$infile,\"seq.pep\",$pdbf\
ile1,\"struc.pdb\");\n    if ($method eq \"fugueal\
i\")\n      {\n	#Env Variable that need to be defi\
ned for Fugue\n	if (!$ENV{FUGUE_LIB_LIST}){$ENV{FU\
GUE_LIB_LIST}=\"DUMMY\";}\n	if (!$ENV{HOMSTRAD_PAT\
H})  {$ENV{HOMSTRAD_PATH}=\"DUMMY\";}\n	if (!$ENV{\
HOMS_PATH}){$ENV{HOMS_PATH}=\"DUMMY\";}\n\n	`joy s\
truc.pdb >x 2>x`;\n	&check_file(\"struc.tem\", \"J\
oy failed [FATAL:$PROGRAM/$method]\");\n	`melody -\
t struc.tem >x 2>x`;\n	&check_file(\"struc.tem\", \
\"Melody failed [FATAL:$PROGRAM/$method]\");\n	`fu\
gueali -seq seq.pep -prf struc.fug -print > tmp_re\
sult.aln`;\n\n	&check_file(\"tmp_result.aln\", \"F\
ugue failed [FATAL:$PROGRAM/$method]\");\n	&safe_s\
ystem (\"t_coffee -other_pg seq_reformat -in tmp_r\
esult.aln -output fasta_aln >result.aln\");\n     \
 }\n    elsif ( $method eq \"t_coffee\")\n      {\\
n	&safe_system (\"t_coffee -in Pstruc.pdb Sseq.pep\
 Mslow_pair -outfile result.aln -quiet\");\n      \
}\n    else\n      {\n	&safe_system (\"$method -in\
file=seq.pep -pdbfile1=struc.pdb -outfile=result.a\
ln $param>x 2>x\");\n      }\n    &set_temporary_d\
ir (\"unset\",$mode,$method,\"result.aln\",$outfil\
e);\n    myexit ($EXIT_SUCCESS);\n  }\nsub seq2pdb\
id_pair\n  {\n    my ($mode, $pdbfile1, $pdbfile2,\
 $method, $param, $outfile)=@_;\n    my ($name);\n\
\n\n    &set_temporary_dir (\"set\");\n    $name=$\
pdbfile1.\" \".$pdbfile2;\n\n    if (    &cache_fi\
le(\"GET\",\"\",\"$name\",\"$method\",\"dali\",$ou\
tfile,\"EBI\"))\n      {return $outfile;}\n    els\
e\n      {\n	if ($method eq \"daliweb\")\n	  {\n	 \
   $pdbfile1=~/(....)(.)/;\n	    $id1=$1; $c1=$2;\\
n\n	    $pdbfile2=~/(....)(.)/;\n	    $id2=$1; $c2\
=$2;\n\n	    $command=\"t_coffee -other_pg dalilit\
e.pl --pdb1 $id1 --chainid1 $c1 --pdb2 $id2 --chai\
nid2 $c2 --email=$EMAIL  >dali_stderr 2>dali_stder\
r\";\n	    $dali=`$command`;\n\n	    open (F, \"da\
li_stderr\");\n	    while (<F>)\n	      {\n		if ( \
/JobId: dalilite-(\\S+)/)\n		{\n		  $jobid=$1;\n		\
}\n	      }\n	    close (F);\n	    unlink (\"dali_\
stderr\");\n\n	    $output1=\"dalilite-$jobid.txt\\
";\n	    if ( -e $output1)\n	      {\n		unlink ($o\
utput1);\n		&url2file (\"http://www.ebi.ac.uk/Tool\
s/es/cgi-bin/jobresults.cgi/dalilite/dalilite-$job\
id/aln.html\", \"output2\");\n\n		if ( -e \"output\
2\")\n		  {\n		    my ($seq1, $seq2);\n		    $seq1\
=$seq2=\"\";\n\n		    open (F, \"output2\");\n		  \
  while (<F>)\n		      {\n			$l=$_;\n			if ( $l=~/\
Query\\s+(\\S+)/)\n			  {\n			    $seq1.=$1;\n			 \
 }\n			elsif ( $l=~/Sbjct\\s+(\\S+)/)\n			  {\n			\
    $seq2.=$1;\n			  }\n		      }\n		    close (F)\
;\n		    unlink (\"output2\");\n		    if ($seq1 ne\
 \"\" && $seq2 ne \"\")\n		      {\n			$output3=\"\
>$A\\n$seq1\\n>$B\\n$seq2\\n\";\n			$output3=~s/\\\
./-/g;\n			open (F, \">result.aln\");\n			print F \
\"$output3\";\n			close (F);\n		      }\n		  }\n	 \
     }\n	  }\n      }\n    &cache_file(\"SET\",\"\\
",\"$name\",\"$method\",\"dali\",\"result.aln\",\"\
EBI\");\n    &set_temporary_dir (\"unset\",$mode, \
$method, \"result.aln\",$outfile);\n    myexit ($E\
XIT_SUCCESS);\n  }\nsub seq2pdb_pair\n  {\n    my \
($mode, $pdbfile1, $pdbfile2, $method, $param, $ou\
tfile)=@_;\n\n    &set_temporary_dir (\"set\",$pdb\
file1,\"pdb1.pdb\",$pdbfile2,\"pdb2.pdb\");\n    i\
f ($method eq \"t_coffee\")\n      {\n	&safe_syste\
m (\"t_coffee -in Ppdb1.pdb Ppdb2.pdb -quiet -outf\
ile=result.aln\");\n      }\n    elsif ( $method e\
q \"DaliLite\")\n      {\n	if ( &safe_system (\"Da\
liLite -pairwise pdb1.pdb pdb2.pdb >tmp1\")==$EXIT\
_SUCCESS)\n	  {\n	     my ($seq1, $seq2);\n	     $\
seq1=$seq2=\"\";\n\n	     open (F, \"tmp1\");\n	  \
   while (<F>)\n	       {\n		 $l=$_;\n		 if ( $l=~\
/Query\\s+(\\S+)/)\n		   {\n		     $seq1.=$1;\n		 \
  }\n		 elsif ( $l=~/Sbjct\\s+(\\S+)/)\n		   {\n		\
     $seq2.=$1;\n		   }\n	       }\n	     close (F\
);\n	     unlink (\"tmp1\");\n	     if ($seq1 ne \\
"\" && $seq2 ne \"\")\n	       {\n		 my $output3=\\
">$A\\n$seq1\\n>$B\\n$seq2\\n\";\n		 $output3=~s/\\
\./-/g;\n		 open (F, \">result.aln\");\n		 print F\
 \"$output3\";\n		 close (F);\n	       }\n	   }\n	\
else\n	  {\n	    print \"ERROR: DalLite failed to \
align the considered structures[tc_generic_method.\
pl]\\n\";\n	  }\n      }\n    elsif ( $method eq \\
"TMalign\")\n      {\n	if ( &safe_system (\"TMalig\
n pdb1.pdb pdb2.pdb >tmp1\")==$EXIT_SUCCESS)\n	  {\
\n	    `tail -4 tmp1 > tmp2`;\n\n	    open (F, \"t\
mp2\");\n	    while (<F>)\n	      {\n		unshift(@l,\
 $_);\n	      }\n	    close (F);\n	    open (F, \"\
>result.aln\");\n	    $l[3]=~s/[^a-zA-Z0-9-]/\\-/g\
;\n	    $l[1]=~s/[^a-zA-Z0-9-]/\\-/g;\n	    print \
F \">$A\\n$l[3]\\n>$B\\n$l[1]\\n\";\n	    close (F\
);\n	  }\n	else\n	  {\n	    print \"ERROR: TMalign\
 failed to align the considered structures[tc_gene\
ric_method.pl]\\n\";\n	    `rm result.aln >/dev/nu\
ll 2>/dev/null`;\n	  }\n      }\n    elsif ( $meth\
od eq \"mustang\")\n      {\n	if ( &safe_system (\\
"mustang -i pdb1.pdb pdb2.pdb -F fasta >/dev/null \
2>/dev/null\")==$EXIT_SUCCESS)\n	  {\n	    `mv res\
ults.afasta result.aln`;\n	  }\n	else\n	  {\n	    \
print \"ERROR: mustang failed to align the conside\
red structures[tc_generic_method.pl]\\n\";\n	    `\
rm result.aln >/dev/null 2>/dev/null`;\n	  }\n    \
  }\n    else\n      {\n	if ( &safe_system (\"$met\
hod -pdbfile1=pdb1.pep -pdbfile2=pdb2.pdb -outfile\
=result.aln $param>x 2>x\")==$EXIT_SUCCESS)\n	  {\\
n	    `mv results.afasta result.aln`;\n	  }\n	else\
\n	  {\n	    print \"ERROR: $method failed to alig\
n the considered structures[tc_generic_method.pl]\\
\n\";\n	    `rm result.aln >/dev/null 2>/dev/null`\
;\n	  }\n      }\n    &set_temporary_dir (\"unset\\
",$mode, $method, \"result.aln\",$outfile);\n    m\
yexit ($EXIT_SUCCESS);\n  }\n\nsub seq2rnapdb_pair\
\n  {\n    my ($mode, $pdbfile1, $pdbfile2, $metho\
d, $param, $outfile)=@_;\n    \n    if ($method eq\
 \"runsara.py\")\n      {\n	my $path=$ENV{PATH};\n\
	\n	if ($ENV{X3DNA_4_SARA}){$ENV{PATH}=\"$ENV{X3DN\
A_4_SARA}:$path\";}\n	\n	open(TMP,\"<$pdbfile1\");\
\n	my $count = 0;\n	my $line;\n	while (<TMP>)\n	  \
{\n	    $line = $_;\n	    if ($count ==1)\n	      \
{\n		last;\n	      }\n	    $count += 1;\n	  }\n	\n\
	\n	$chain1 = substr($line,length($line)-3,1);\n	\\
n	close TMP;\n	open(TMP,\"<$pdbfile2\");\n	my $cou\
nt = 0;\n	while (<TMP>)\n	  {\n	    $line = $_;\n	\
    if ($count ==1)\n	      {\n		last;\n	      }\n\
	    $count += 1;\n	  }\n	$chain2 = substr($line,l\
ength($line)-3,1);\n	close TMP;\n	\n	$tmp_file=&vt\
mpnam();\n	\n	safe_system(\"runsara.py $pdbfile1 $\
chain1 $pdbfile2 $chain2 -s -o $tmp_file --limitat\
ion 5000 > /dev/null 2> /dev/null\");\n	if ($ENV{X\
3DNA_4_SARA}){$ENV{PATH}=$path;}\n	\n	open(TMP,\"<\
$tmp_file\") or die \"cannot open the sara tmp fil\
e:$!\\n\";\n	open(OUT,\">$outfile\") or die \"cann\
ot open the $outfile file:$!\\n\";\n	\n	my $switch\
 = 0;\n	my $seqNum = 0;\n	foreach my $line (<TMP>)\
\n	  {\n	    next unless ($line=~/SARAALI/);\n	   \
 if ($line=~/>/)\n	      {\n		$switch =0;\n		print\
 OUT \">seq$seqNum\\n\";\n		$seqNum++;\n	      }\n\
	    if ($switch < 2){\n	      $switch++;\n	      \
next;\n	    }\n	    \n	    if ($line =~/REMARK\\s+\
SARAALI\\s+([^\\*]+)\\*/)\n	      {\n		my $string \
= $1;\n		print OUT \"$string\\n\";\n	      }\n	  }\
\n	close TMP;\n	close OUT;\n	unlink($tmp_file);\n \
     }\n  }\nsub seq2profile_pair\n  {\n    my ($m\
ode, $profile1, $profile2, $method, $param, $outfi\
le)=@_;\n    \n    \n    if ($method eq \"clustalw\
\")\n      {\n	`clustalw -profile1=$profile1 -prof\
ile2=$profile2 -outfile=$outfile`;\n      }\n    e\
lsif ( $method eq \"clustalo\")\n      {\n	\n	`clu\
stalo --p1 $profile1 --p2 $profile2 -o $outfile --\
force`;\n      }\n    elsif ( $method eq \"hhalign\
\")\n      {\n	hhalign ( $profile1,$profile2,$outf\
ile,$param);\n      }\n    else\n      {\n	`$metho\
d -profile1=$profile1 -profile2=$profile2 -outfile\
=$outfile $param> /dev/null 2>/dev/null`;\n      }\
\n    myexit ($EXIT_SUCCESS);\n  }\n\nsub pg_is_in\
stalled\n  {\n    my @ml=@_;\n    my ($r, $p, $m);\
\n    my $supported=0;\n\n    my $p=shift (@ml);\n\
    if ($p=~/::/)\n      {\n	if (safe_system (\"pe\
rl -M$p -e 1\")==$EXIT_SUCCESS){return 1;}\n	else \
{return 0;}\n      }\n    else\n      {\n	$r=`whic\
h $p 2>/dev/null`;\n	if ($r eq \"\"){$r=0;}\n	else\
 {$r=1;}\n\n	if ($r==0 && is_blast_package ($p)){r\
eturn pg_is_installed (\"legacy_blast.pl\");}\n	el\
se {return $r;}\n      }\n  }\n\nsub is_blast_pack\
age\n  {\n    my $p=shift;\n    if ( $p=~/blastp/)\
{return 1;}\n    elsif ($p=~/blastall/){return 1;}\
\n    elsif ($p=~/blastn/){return 1;}\n    elsif (\
$p=~/blastx/){return 1;}\n    elsif ($p=~/formatdb\
/){return 1;}\n    else {return 0;}\n  }\n\nsub ch\
eck_internet_connection\n  {\n    my $internet;\n \
   my $tmp;\n    &check_configuration ( \"wget\");\
\n\n    $tmp=&vtmpnam ();\n\n    if     (&pg_is_in\
stalled    (\"wget\")){`wget www.google.com -O$tmp\
 >/dev/null 2>/dev/null`;}\n    elsif  (&pg_is_ins\
talled    (\"curl\")){`curl www.google.com -o$tmp \
>/dev/null 2>/dev/null`;}\n\n    if ( !-e $tmp || \
-s $tmp < 10){$internet=0;}\n    else {$internet=1\
;}\n    if (-e $tmp){unlink $tmp;}\n\n    return $\
internet;\n  }\nsub check_pg_is_installed\n  {\n  \
  my @ml=@_;\n    my $r=&pg_is_installed (@ml);\n \
   if (!$r && $p=~/::/)\n      {\n	print STDERR \"\
\\nYou Must Install the perl package $p on your sy\
stem.\\nRUN:\\n\\tsudo perl -MCPAN -e 'install $pg\
'\\n\";\n      }\n    elsif (!$r)\n      {\n	myexi\
t(flush_error(\"\\nProgram $p Supported but Not In\
stalled on your system\"));\n      }\n    else\n  \
    {\n	return 1;\n      }\n  }\nsub set_temporary\
_dir\n  {\n    my @list=@_;\n    my $dir_mode, $a,\
 $mode, $method;\n\n    $dir_mode=shift (@list);\n\
\n\n    if ( $dir_mode eq \"set\")\n      {\n	$ini\
tial_dir=cwd();\n	if ( !$tmp_dir)\n	  {\n	    $ran\
d=rand (100000);\n	    $tmp_dir=\"$TMPDIR/tmp4tcof\
fee_profile_pair_dir_$$\\_P_$rand\";\n	  }\n	if ( \
!-d $tmp_dir)\n	  {\n	    push (@TMPDIR_LIST, $tmp\
_dir);\n	    `mkdir $tmp_dir`;\n	  }\n\n	for ( $a=\
0; $a<=$#list; $a+=2)\n	      {\n		if (-e $list[$a\
]){ `cp $list[$a] $tmp_dir/$list[$a+1]`;}\n	      \
}\n	chdir $tmp_dir;\n      }\n    elsif ( $dir_mod\
e eq \"unset\")\n      {\n	$mode=shift (@list);\n	\
$method=shift (@list);\n\n	if (!-e $list[0])\n	  {\
\n	   myexit(flush_error(\"Program $method failed \
to produce $list[1]\" ));\n	    myexit ($EXIT_FAIL\
URE);\n	  }\n	else\n	  {\n	    chdir $initial_dir;\
\n	    # `t_coffee -other_pg seq_reformat -in $tmp\
_dir/$list[0] -output fasta_aln -out $tmp_dir/resu\
lt2.aln`;\n	    `cp $tmp_dir/$list[0] $tmp_dir/res\
ult2.aln`;\n	    if ( $list[1] eq \"stdout\")\n	  \
    {\n		open (F, \"$tmp_dir/result2.aln\");\n		wh\
ile (<F>){print $_;}close(F);\n	      }\n	    else\
\n	      {\n		`mv $tmp_dir/result2.aln $list[1]`;\\
n	      }\n	    shift (@list); shift (@list);\n	  \
  foreach $f (@list)\n	      {\n		if (-e (\"$tmp_d\
ir/$f\")){`mv $tmp_dir/$f .`;}\n	      }\n	  }\n  \
    }\n  }\n\n\n\n\nsub my_get_opt\n  {\n    my @l\
ist=@_;\n    my ($cl, $a, $argv, @argl);\n\n    \n\
    @argl=();\n    $cl=shift @list;\n    for ( my \
$a=0; $a<=$#list; $a+=3)\n      {\n	my $option=$li\
st[$a];\n	my $optional=$list[$a+1];\n	my $status=$\
list[$a+2];\n	my $argv=\"\";\n	if ($cl=~/$option(\\
\S+)/){$argv=$1;}\n	@argl=(@argl,$argv);\n\n\n	#$o\
ptional:0=>optional\n	#$optional:1=>must be set\n	\
#$status: 0=>no requirement\n	#$status: 1=>must be\
 an existing file\n	#$status: 2=>must be an instal\
led package\n	\n\n	if ($optional==0){;}\n	elsif ( \
$optional==1 && $argv eq \"\")\n	  {\n	    myexit(\
flush_error( \"ERROR: Option $option must be set\"\
));\n	    myexit ($EXIT_FAILURE);\n	  }\n	if ($sta\
tus==0){;}\n	elsif ($status ==1 && $argv ne \"\" &\
& !-e $argv)\n	  {\n	    myexit(flush_error( \"Fil\
e [$argv] must exist\"));\n	    myexit ($EXIT_FAIL\
URE);\n	  }\n	elsif ( $status==2 && $argv ne \"\" \
&& &check_pg_is_installed ($argv)==0)\n	  {\n	    \
myexit(flush_error( \" $argv is not installed\"));\
\n	    myexit ($EXIT_FAILURE);\n	  }\n      }\n   \
 return @argl;\n    }\n\nsub check_file\n  {\n    \
my ($file, $msg)=@_;\n\n    if ( !-e $file)\n     \
 {\n	myexit(flush_error(\"$msg\"));\n      }\n    \
}\nsub hhalign\n  {\n    my ($aln1, $aln2, $outfil\
e, $param)=@_;\n    my $hh=$ENV{\"HHALIGN_4_TCOFFE\
E\"};\n    \n    \n    if ($hh)\n      {\n	\n	#ext\
ernal_hhalign\n	# set via HHALIGN_4_TCOFFEE\n	#<pg\
> -profile1 <fasta_prf with seq1 top> -profile2 <f\
asta profile with seq2 top> -outfile < fasta align\
mentof seq1 and 2 | tc_lib of seq 1 and 2>\n	\n	sa\
fe_system (\"$hh -method=align -profile1=$aln1 -pr\
ofile2=$aln2 -outfile=$outfile\");\n      }\n    e\
lse\n      {\n	&local_hhalign ($aln1, $aln2, $outf\
ile, $param);\n      }\n  }\n\n    \n    \nsub loc\
al_hhalign\n  {\n    my ($aln1, $aln2, $outfile, $\
param)=@_;\n    my $h1, $h2;\n\n    $h{0}{index}=0\
;\n    $h{1}{index}=1;\n\n    $h{0}{aln}=$aln1;\n \
   $h{1}{aln}=$aln2;\n\n\n\n    %{$h{0}}=aln2psi_p\
rofile (%{$h{0}});\n    %{$h{1}}=aln2psi_profile (\
%{$h{1}});\n\n    $param=~s/#S/ /g;\n    $param=~s\
/#M/\\-/g;\n    $param=~s/#E/\\=/g;\n\n\n\n    $co\
mmand=\"hhalign -i $h{0}{a3m} -t $h{1}{a3m} -tc $o\
utfile.tmp -rank 1 -mapt 0 $param\";\n    `$comman\
d`;\n\n  #  `hhalign -i $h{0}{a3m} -t $h{1}{a3m} -\
tc $outfile.tmp -rank 1 -mapt 0 -gapf 0.8 -gapg 0.\
8`;\n\n\n    # To run global use the following\n\n\
    open (I, \"$outfile.tmp\");\n    open (O, \">$\
outfile\");\n    $h{0}{cons}=s/\\./x/g;\n    $h{1}\
{cons}=s/\\./x/g;\n\n    print O \"! TC_LIB_FORMAT\
_01\\n2\\n$h{0}{name} $h{0}{len} $h{0}{seq}\\n$h{1\
}{name} $h{1}{len} $h{1}{seq}\\n#1 2\\n\";\n\n    \
while (<I>)\n      {\n	if (/(\\d+)\\s+(\\d+)\\s+(\\
\d+)/)\n	  {\n	    print O \"\\t$h{0}{$1}\\t$h{1}{\
$2}\\t$3\\n\";\n	  }\n      }\n    print O \"! SEQ\
_1_TO_N\\n\";\n\n    close (O);\n    close (I);\n \
 }\n\nsub aln2psi_profile\n  {\n    my (%h)=@_;\n \
   my ($aln,$i,$hv, $a, @c, $n);\n\n\n    $i=$h{in\
dex};\n    $aln=$h{aln};\n\n    `cp $aln $$.hhh_al\
n`;\n    $command=\"t_coffee -other_pg seq_reforma\
t -in $aln -output hasch\";\n    $hv=`$command`;ch\
omp ($hv);\n\n    $h{a2m}=\"$tmp/$hv.tmp4hhpred.a2\
m\";\n    $h{a3m}=\"$tmp/$hv.tmp4hhpred.a3m\";\n  \
  if ( -e $h{a3m}){;}\n    else\n      {\n	$x=`whi\
ch hhconsensus`;\n	`hhconsensus  -M 50 -i $h{aln} \
-oa2m $h{a2m}`;\n	if (!-e $h{a2m})\n	  {\n	    pri\
nt STDERR \"Program tc_generic_method.pl FAILED to\
 run:\\n\\thhconsensus  -M 50 -i $h{aln} -oa2m $h{\
a2m}\";\n	    myexit ($EXIT_FAILURE);\n	  }\n\n	`h\
hconsensus  -M 50 -i $h{aln} -oa3m $h{a3m}`;\n	if \
(!-e $h{a3m})\n	  {\n	    print STDERR \"Program t\
c_generic_method.pl FAILED to run:\\n\\thhconsensu\
s  -M 50 -i $h{aln} -oa3m $h{a3m}\";\n	    myexit \
($EXIT_FAILURE);\n	  }\n       `buildali.pl $h{a3m\
} -n 1`;\n      }\n\n\n    $h{a2m_seq}=`head -n 2 \
$h{a2m} | grep -v \">\"`;chomp ($h{a2m_seq});\n   \
 $h{a3m_seq}=`head -n 2 $h{a3m} | grep -v \">\"`;c\
homp ($h{a3m_seq});\n    $h{cons}=$h{a2m_seq};\n  \
  $h{seq}=`head -n 2 $h{aln} | grep -v \">\"`;chom\
p ($h{seq});\n\n\n\n    @c=split (//, $h{cons});\n\
    $h{len}=$#c+1;\n    for ($n=0,$a=0, $b=0; $a<$\
h{len};$a++)\n      {\n	if ( $c[$a]=~/[A-Z]/)\n	  \
{\n	    $h{++$n}=++$b;\n\n	  }\n	elsif ( $c[$a]=~/\
[a-z\\.]/)\n	  {\n	    ++$b;\n	  }\n      }\n\n   \
 $name=`head -n 2 $h{aln} | grep \">\"`;\n    $nam\
e=~/\\>(\\S+)/;\n    $h{name}=$1;\n\n    `cp $h{a2\
m} $i.a2m`;\n    `cp $h{a3m} $i.a3m`;\n    `cp $h{\
aln} $i.hh_aln`;\n\n    return %h;\n  }\nsub read_\
fasta_seq_index\n  {\n    my $f=@_[0];\n    my %hs\
eq;\n    my (@seq, @com, @name);\n    my ($a, $s,$\
nseq);\n\n    open (F, $f);\n    while (<F>)\n    \
  {\n	$s.=$_;\n      }\n    close (F);\n\n\n    @n\
ame=($s=~/>(\\S*).*\\n[^>]*/g);\n\n    @seq =($s=~\
/>.*.*\\n([^>]*)/g);\n    @com =($s=~/>\\S*(.*)\\n\
([^>]*)/g);\n\n\n    $nseq=$#name+1;\n\n    for ($\
a=0; $a<$nseq; $a++)\n      {\n	my $s;\n	my $n=$na\
me[$a];\n	$hseq{$a}{name}=$n;\n	$seq[$a]=~s/[^A-Za\
-z]//g;\n	$hseq{$a}{order}=$a;\n	$hseq{$a}{seq}=$s\
eq[$a];\n	$hseq{$a}{com}=$com[$a];\n\n      }\n   \
 return %hseq;\n  }\nsub read_fasta_seq\n  {\n    \
my $f=@_[0];\n    my %hseq;\n    my (@seq, @com, @\
name);\n    my ($a, $s,$nseq);\n\n    open (F, $f)\
;\n    while (<F>)\n      {\n	$s.=$_;\n      }\n  \
  close (F);\n\n\n    @name=($s=~/>(\\S*).*\\n[^>]\
*/g);\n\n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n    \
@com =($s=~/>\\S*(.*)\\n([^>]*)/g);\n\n\n    $nseq\
=$#name+1;\n\n    for ($a=0; $a<$nseq; $a++)\n    \
  {\n	my $s;\n	my $n=$name[$a];\n	$hseq{$n}{name}=\
$n;\n	$seq[$a]=~s/[^A-Za-z]//g;\n	$hseq{$n}{order}\
=$a;\n	$hseq{$n}{seq}=$seq[$a];\n	$hseq{$n}{com}=$\
com[$a];\n\n      }\n    return %hseq;\n  }\n\n\ns\
ub read_fasta_aln\n  {\n    my $f=@_[0];\n    my %\
hseq;\n    my (@seq, @com, @name);\n    my ($a, $s\
,$nseq);\n\n    open (F, $f);\n    while (<F>)\n  \
    {\n	$s.=$_;\n      }\n    close (F);\n\n\n    \
@name=($s=~/>(\\S*).*\\n[^>]*/g);\n\n    @seq =($s\
=~/>.*.*\\n([^>]*)/g);\n    @com =($s=~/>\\S*(.*)\\
\n([^>]*)/g);\n\n\n    $nseq=$#name+1;\n\n    for \
($a=0; $a<$nseq; $a++)\n      {\n	my $s;\n	my $n=$\
name[$a];\n	$hseq{$n}{name}=$n;\n	$seq[$a]=~s/[^A-\
Za-z-.()[\\]]//g;\n	$hseq{$n}{order}=$a;\n	$hseq{$\
n}{seq}=$seq[$a];\n	$hseq{$n}{com}=$com[$a];\n\n  \
    }\n    return %hseq;\n  }\n\nsub recode_name2\\
n{\n	my ($in)=shift;\n	my $mode=shift;\n\n	my %seq\
;\n	my $new_name;\n\n	if (! -e $in){return;}\n\n	#\
needed by ClustalOmega to avoid very long names\n	\
open (INFILE, \"+<$in\");\n\n	my $line;\n\n	if ($m\
ode eq \"code\")\n	{\n		chomp($line = <INFILE>);\n\
		my $line_length = length($line);\n		$new_name=++\
$RECODE_N;\n		$new_name=\">$new_name\";\n		my $new\
_length = length($new_name);\n		$RECODE {$new_name\
}=$line;\n		for ($count = $new_length; $count < $l\
ine_length; $count++)\n		{\n			$new_name .= \" \";\
\n		}\n		$new_name=\"$new_name\\n\";\n		seek INFIL\
E, 0, 0\n			or die \"could not seek: $!\";\n		prin\
t INFILE \"$new_name\";\n	}\n	else\n	{\n		my $n_fo\
und = 0;\n		my $file_pos=0;\n		$file_pos=tell INFI\
LE;\n		while (<INFILE>)\n		{\n			$line=$_;\n			$li\
ne =~ s/\\s*$//;\n\n			$old_name= $RECODE{$line};\\
n			if ($old_name ne \"\")\n			{\n				seek INFILE,\
 $file_pos, 0\n					or die \"could not seek: $!\";\
\n				print INFILE \"$old_name\\n\";\n				$file_po\
s++;\n				if ($file_pos == 2)\n				{\n					print \\
"stop\\n\";\n					break;\n				}\n			}\n			$file_po\
s=tell INFILE;\n		}\n\n	}\n\n\n	close INFILE;\n}\n\
\n\nsub recode_name\n{\n	my ($in)=shift;\n	my $mod\
e=shift;\n	my $f=new FileHandle;\n	my %seq;\n	my $\
new_name;\n\n	if (! -e $in){return;}\n\n	#needed b\
y ClustalOmega to avoid very long names\n	%seq=rea\
d_fasta_aln ($in);\n\n	open ($f, \">$in\");\n	fore\
ach my $s (keys(%seq))\n	{\n		if ($mode eq \"code\\
")\n		{\n			$new_name=++$RECODE_N;\n			$RECODE {$n\
ew_name}=$seq{$s}{name};\n		}\n		else\n		{\n			$ne\
w_name=$RECODE{$seq{$s}{name}};\n		}\n		print $f \\
">$new_name\\n$seq{$s}{seq}\\n\";\n	}\n	close $f;\\
n}\n\nsub fasta_hash2index_hash\n  {\n    my %s1=@\
_;\n    my %s;\n    foreach my $s (keys (%s1))\n  \
    {\n	my $i=$s1{$s}{order};\n	$s{$i}{name}=$s;\n\
	$s{$i}{seq}=$s1{$s}{seq};\n	$s{$i}{len}=length( $\
s{$i}{seq});\n	$s{n}++;\n      }\n    return %s;\n\
  }\nsub file_contains\n  {\n    my ($file, $tag, \
$max)=(@_);\n    my ($n);\n    $n=0;\n\n    if ( !\
-e $file && ($file =~/$tag/)) {return 1;}\n    els\
if ( !-e $file){return 0;}\n    else\n      {\n	op\
en (FC, \"$file\");\n	while ( <FC>)\n	  {\n	    if\
 ( ($_=~/$tag/))\n	      {\n		close (FC);\n		retur\
n 1;\n	      }\n	    elsif ($max && $n>$max)\n	   \
   {\n		close (FC);\n		return 0;\n	      }\n	    $\
n++;\n	  }\n      }\n    close (FC);\n    return 0\
;\n  }\n\n\nsub file2string\n  {\n    my $f=@_[0];\
\n    my $string, $l;\n    open (F,\"$f\");\n    w\
hile (<F>)\n      {\n\n	$l=$_;\n	#chomp ($l);\n	$s\
tring.=$l;\n      }\n    close (F);\n    $string=~\
s/\\r\\n//g;\n    $string=~s/\\n//g;\n    return $\
string;\n  }\n\n\nsub tag2value\n  {\n\n    my $ta\
g=(@_[0]);\n    my $word=(@_[1]);\n    my $return;\
\n\n    $tag=~/$word=\"([^\"]+)\"/;\n    $return=$\
1;\n    return $return;\n  }\n\nsub hit_tag2pdbid\\
n  {\n    my $tag=(@_[0]);\n    my $pdbid;\n\n    \
$tag=~/id=\"(\\S+)\"/;\n    $pdbid=$1;\n    $pdbid\
=~s/_//;\n    return $pdbid;\n  }\nsub id2pdbid\n \
 {\n    my $in=@_[0];\n    my $id;\n\n    $in=~/(\\
\S+)/;\n    $id=$in;\n    $id=~s/PDB/pdb/g;\n\n   \
 if ($id =~/pdb(.*)/){$id=$1;}\n    elsif ( $id=~/\
(\\S+)\\s+mol:protein/){$id=$1;}\n    $id=~s/[:|ï¿\
½ï¿½_]//g;\n    return $id;\n  }\nsub set_blast_ty\
pe\n  {\n    my $file =@_[0];\n    if (&file_conta\
ins ($file,\"EBIApplicationResult\",100)){$BLAST_T\
YPE=\"EBI\";}\n    elsif (&file_contains ($file,\"\
NCBI_BlastOutput\",100)) {$BLAST_TYPE=\"NCBI\";}\n\
    else\n      {\n	$BLAST_TYPE=\"\";\n      }\n  \
  return $BLAST_TYPE;\n  }\nsub is_valid_blast_xml\
\n    {\n      my $file=shift;\n      my $line;\n\\
n\n      if ( !-e $file) {return 0;}\n      $line=\
&file2tail ($file,100);\n\n      if ( $line=~/<\\/\
EBIApplicationResult/ || $line=~/<\\/NCBI_BlastOut\
put/ || $line=~/<\\/BlastOutput/ ){return 1;}\n   \
   return 0;\n    }\nsub file2blast_flavor\n      \
{\n	my $file=shift;\n	if (&file_contains ($file,\"\
EBIApplicationResult\",100)){return \"EBI\";}\n	el\
sif (&file_contains ($file,\"NCBI_BlastOutput\",10\
0)){return \"NCBI\";}\n	else {return \"UNKNOWN\";}\
\n      }\nsub blast_xml2profile\n  {\n    my ($na\
me,$seq,$maxid, $minid, $mincov, $file)=(@_);\n   \
 my (%p, $a, $string, $n);\n\n\n\n    if ($BLAST_T\
YPE eq \"EBI\" || &file_contains ($file,\"EBIAppli\
cationResult\",100)){%p=ebi_blast_xml2profile(@_);\
}\n    elsif ($BLAST_TYPE eq \"NCBI\" || &file_con\
tains ($file,\"NCBI_BlastOutput\",100)){%p=ncbi_bl\
ast_xml2profile(@_);}\n    else\n      {\n	myexit(\
add_error ( $$,$$,getppid(), \"BLAST_FAILURE::unko\
wn XML\",$CL));\n      }\n    for ($a=0; $a<$p{n};\
 $a++)\n      {\n	my $name=$p{$a}{name};\n	$p{$nam\
e}{seq}=$p{$a}{seq};\n	$p{$name}{index}=$a;\n     \
 }\n    return %p;\n  }\nsub ncbi_tblastx_xml2lib_\
file\n  {\n    my  ($outlib,$string)=(@_);\n    my\
 ($L,$l, $a,$b,$c,$d,$i,$nhits,@identifyerL);\n   \
 my (%ITERATION);\n\n    open (F, \">>$outlib\");\\
n\n    $seq=~s/[^a-zA-Z]//g;\n    $L=length ($seq)\
;\n\n    %ITERATION=xml2tag_list ($string, \"Itera\
tion\");\n    for ($i=0; $i<$ITERATION{n};$i++)\n \
     {\n	my ($qindex, $qlen, %hit, $string);\n	$st\
ring=$ITERATION{$i}{body};\n\n	$qindex=xmltag2valu\
e($string,\"Iteration_iter-num\");\n	$qlen  =xmlta\
g2value($string,\"Iteration_query-len\");\n	%hit=&\
xml2tag_list  ($string, \"Hit\");\n\n	for ($a=0; $\
a<$hit{n}; $a++)\n	  {\n	    my ($string);\n	    $\
string=$hit{$a}{body};\n\n	    $hindex=xmltag2valu\
e($string,\"Hit_accession\")+1;\n	    if ($hindex<\
=$qindex){next;}\n	    else  {print F  \"# $qindex\
 $hindex\\n\";}\n\n\n	    $hlen=xmltag2value  ($st\
ring,\"Hit_len\");\n	    %HSP=&xml2tag_list  ($str\
ing, \"Hsp\");\n\n	    for ($b=0; $b<$HSP{n}; $b++\
)\n	      {\n		my ($string, $qs,$qe,$qf,$hs,$he,$h\
f,$s, $d, $e);\n		$string=$HSP{$b}{body};\n\n		$qs\
=xmltag2value  ($string,\"Hsp_query-from\");\n		$q\
e=xmltag2value  ($string,\"Hsp_query-to\");\n		$qf\
=xmltag2value  ($string,\"Hsp_query-frame\");\n\n	\
	$hs=xmltag2value  ($string,\"Hsp_hit-from\");\n		\
$he=xmltag2value  ($string,\"Hsp_hit-to\");\n		$hf\
=xmltag2value  ($string,\"Hsp_hit-frame\");\n\n		$\
s=xmltag2value  ($string,\"Hsp_identity\");\n		$l=\
xmltag2value  ($string,\"Hsp_align-len\");\n		$s=i\
nt(($s*100)/$l);\n\n		if ($qf>0)\n		  {$rqs=$qs; $\
rqe=$qe;}\n		else\n		  {\n		    $rqe=($qlen-$qs)+1\
;\n		    $rqs=($qlen-$qe)+1;\n		  }\n\n		if ($hf>0\
)\n		  {$rhs=$hs; $rhe=$he;}\n		else\n		  {\n		   \
 $rhe=($hlen-$hs)+1;\n		    $rhs=($hlen-$he)+1;\n	\
	  }\n		for ($d=0,$e=$rqs; $e<$rqe; $e++,$d++)\n		\
  {\n		    my ($r1,$r2);\n		    $r1=$e;\n		    $r2\
=$rhs+$d;\n		    print F \" $r1 $r2 $s 0\\n\";\n		\
  }\n	      }\n	  }\n      }\n    print F \"! SEQ_\
1_TO_N\\n\";\n\n    close (F);\n    return %lib;\n\
  }\n\nsub ncbi_tblastpx_xml2lib_file\n  {\n    my\
  ($outlib,$string,%s)=(@_);\n    my ($L,$l, $a,$b\
,$c,$d,$i,$nhits,@identifyerL);\n    my (%ITERATIO\
N,%hdes, %qdes);\n\n    open (F, \">>$outlib\");\n\
\n    $seq=~s/[^a-zA-Z]//g;\n    $L=length ($seq);\
\n\n    %ITERATION=xml2tag_list ($string, \"Iterat\
ion\");\n    for ($i=0; $i<$ITERATION{n};$i++)\n  \
    {\n	my ($qindex, $qlen, %hit, $string);\n	$str\
ing=$ITERATION{$i}{body};\n\n	$qdef=xmltag2value($\
string,\"Iteration_query-def\");\n	%qdes=&tblastpx\
_name2description($qdef,%s);\n	$qlen  =xmltag2valu\
e($string,\"Iteration_query-len\");\n	%hit=&xml2ta\
g_list  ($string, \"Hit\");\n\n	for ($a=0; $a<$hit\
{n}; $a++)\n	  {\n	    my ($string);\n	    $string\
=$hit{$a}{body};\n	    $hdef=xmltag2value($string,\
\"Hit_def\");\n	    %hdes=&tblastpx_name2descripti\
on($hdef,%s);\n	    if ($hdes{index}<=$qdes{index}\
){next;}\n	    else  {print F  \"# $qdes{index} $h\
des{index}\\n\";}\n\n\n	    $hlen=xmltag2value  ($\
string,\"Hit_len\");\n	    %HSP=&xml2tag_list  ($s\
tring, \"Hsp\");\n\n	    for ($b=0; $b<$HSP{n}; $b\
++)\n	      {\n		my ($string, $l,$qs,$qe,$qf,$hs,$\
he,$hf,$s, $d, $e, @s1, @s2);\n		$string=$HSP{$b}{\
body};\n\n		$qs=xmltag2value  ($string,\"Hsp_query\
-from\");\n		$qe=xmltag2value  ($string,\"Hsp_quer\
y-to\");\n		$qf=$qdes{frame};\n		$qseq=xmltag2valu\
e  ($string,\"Hsp_qseq\");\n\n		$hs=xmltag2value  \
($string,\"Hsp_hit-from\");\n		$he=xmltag2value  (\
$string,\"Hsp_hit-to\");\n		$hf=$hdes{frame};\n		$\
hseq=xmltag2value  ($string,\"Hsp_hseq\");\n\n		$s\
=xmltag2value  ($string,\"Hsp_identity\");\n		$l=x\
mltag2value  ($string,\"Hsp_align-len\");\n		$s=in\
t(($s*100)/$l);\n		@s1=tblastpx_hsp2coordinates($q\
seq,$qs,$qe,%qdes);\n		@s2=tblastpx_hsp2coordinate\
s($hseq,$hs,$he,%hdes);\n\n\n		for ($f=0; $f<=$#s1\
; $f++)\n		  {\n		    if ($s1[$f]==-1 || $s2[$f]==\
-1){next;}\n		    else\n		      {\n			print F \" $\
s1[$f] $s2[$f] $s 0\\n\";\n		      }\n		  }\n	    \
  }\n	  }\n      }\n    print F \"! SEQ_1_TO_N\\n\\
";\n\n    close (F);\n    return %lib;\n  }\nsub t\
blastpx_hsp2coordinates\n  {\n    my ($seq, $s, $e\
, %des)=@_;\n    my @list;\n    my @sa;\n    my @g\
ap=(-1,-1,-1);\n\n    $s=$des{start}+3*($s-1);\n\n\
    if ($des{strand} eq \"d\"){;}\n    else {$s=($\
des{length}-$s)+1;}\n\n    foreach $c (split (//,$\
seq))\n      {\n	if ( $c eq '-'){push (@list,@gap)\
;}\n	elsif ($des{strand} eq \"d\")\n	  {\n	    pus\
h(@list,$s++,$s++,$s++);\n	  }\n	else\n	  {\n	    \
push(@list, $s--,$s--,$s--);\n	  }\n      }\n    r\
eturn @list;\n  }\n\nsub tblastpx_name2description\
\n  {\n    my ($name, %s)=@_;\n    my @at=split(\"\
__\", $name);\n    my %des;\n\n    $des{name}=$at[\
0];\n    $des{strand}=$at[1];\n\n    $des{start}=$\
at[2];\n    $des{end}=$at[3];\n    $des{length}=$a\
t[4];\n    $des{index}=$s{$at[0]}{order}+1;\n    r\
eturn %des;\n  }\nsub ncbi_blast_xml2profile\n  {\\
n    my ($name,$seq,$maxid, $minid, $mincov, $stri\
ng)=(@_);\n    my ($L,$l, $a,$b,$c,$d,$nhits,@iden\
tifyerL);\n\n\n    $seq=~s/[^a-zA-Z]//g;\n    $L=l\
ength ($seq);\n\n    #This is causing the NCBI par\
ser to fail when Iteration_query-def is missing\n \
   #%query=&xml2tag_list ($string, \"Iteration_que\
ry-def\");\n    #$name=$query{0}{body};\n\n    %hi\
t=&xml2tag_list ($string, \"Hit\");\n\n\n    for (\
$nhits=0,$a=0; $a<$hit{n}; $a++)\n      {\n	my ($l\
db,$id, $identity, $expectation, $start, $end, $co\
verage, $r);\n	my (%ID,%DE,%HSP);\n\n	$ldb=\"\";\n\
\n	%ID=&xml2tag_list ($hit{$a}{body}, \"Hit_id\");\
\n	$identifyer=$ID{0}{body};\n\n	%DE=&xml2tag_list\
 ($hit{$a}{body}, \"Hit_def\");\n	$definition=$DE{\
0}{body};\n\n	%HSP=&xml2tag_list ($hit{$a}{body}, \
\"Hsp\");\n	for ($b=0; $b<$HSP{n}; $b++)\n	  {\n	 \
   my (%START,%END,%E,%I,%Q,%M);\n\n\n	    %START=\
&xml2tag_list ($HSP{$b}{body}, \"Hsp_query-from\")\
;\n	    %HSTART=&xml2tag_list ($HSP{$b}{body}, \"H\
sp_hit-from\");\n\n	    %LEN=  &xml2tag_list ($HSP\
{$b}{body}, \"Hsp_align-len\");\n	    %END=  &xml2\
tag_list ($HSP{$b}{body}, \"Hsp_query-to\");\n	   \
 %HEND=  &xml2tag_list ($HSP{$b}{body}, \"Hsp_hit-\
to\");\n	    %E=&xml2tag_list     ($HSP{$b}{body},\
 \"Hsp_evalue\");\n	    %I=&xml2tag_list     ($HSP\
{$b}{body}, \"Hsp_identity\");\n	    %Q=&xml2tag_l\
ist     ($HSP{$b}{body}, \"Hsp_qseq\");\n	    %M=&\
xml2tag_list     ($HSP{$b}{body}, \"Hsp_hseq\");\n\
\n	    for ($e=0; $e<$Q{n}; $e++)\n\n	      {\n		$\
qs=$Q{$e}{body};\n		$ms=$M{$e}{body};\n\n		$expect\
ation=$E{$e}{body};\n		$identity=($LEN{$e}{body}==\
0)?0:$I{$e}{body}/$LEN{$e}{body}*100;\n		$start=$S\
TART{$e}{body};\n		$end=$END{$e}{body};\n		$Hstart\
=$HSTART{$e}{body};\n		$Hend=$HEND{$e}{body};\n\n	\
	$coverage=($L)?(($end-$start)*100)/$L:0;\n\n		if \
($identity>$maxid || $identity<$minid || $coverage\
<$mincov){next;}\n		@lr1=(split (//,$qs));\n		@lr2\
=(split (//,$ms));\n		$l=$#lr1+1;\n		for ($c=0;$c<\
$L;$c++){$p[$nhits][$c]=\"-\";}\n		for ($d=0,$c=0;\
 $c<$l; $c++)\n		  {\n		    $r=$lr1[$c];\n		    if\
 ( $r=~/[A-Za-z]/)\n		      {\n\n			$p[$nhits][$d \
+ $start-1]=$lr2[$c];\n			$d++;\n		      }\n		  }\\
n		$Qseq[$nhits]=$qs;\n		$Hseq[$nhits]=$ms;\n		$Qs\
tartL[$nhits]=$start;\n		$HstartL[$nhits]=$Hstart;\
\n		$identityL[$nhits]=$identity;\n		$endL[$nhits]\
=$end;\n		$definitionL[$nhits]=$definition;\n		$id\
entifyerL[$nhits]=$identifyer;\n		$comment[$nhits]\
=\"$ldb|$identifyer [Eval=$expectation][id=$identi\
ty%][start=$Hstart end=$Hend]\";\n		$nhits++;\n	  \
    }\n	  }\n      }\n\n\n    $profile{n}=0;\n    \
$profile{$profile{n}}{name}=$name;\n    $profile{$\
profile{n}}{seq}=$seq;\n    $profile {n}++;\n\n   \
 for ($a=0; $a<$nhits; $a++)\n      {\n	$n=$a+1;\n\
\n	$profile{$n}{name}=\"$name\\_$a\";\n	$profile{$\
n}{seq}=\"\";\n	$profile{$n}{Qseq}=$Qseq[$a];\n	$p\
rofile{$n}{Hseq}=$Hseq[$a];\n	$profile{$n}{Qstart}\
=$QstartL[$a];\n	$profile{$n}{Hstart}=$HstartL[$a]\
;\n	$profile{$n}{identity}=$identityL[$a];\n	$prof\
ile{$n}{definition}=$definitionL[$a];\n	$profile{$\
n}{identifyer}=$identifyerL[$a];\n	$profile{$n}{co\
mment}=$comment[$a];\n\n	for ($b=0; $b<$L; $b++)\n\
	  {\n	    if ($p[$a][$b])\n	      {\n		$profile{$\
n}{seq}.=$p[$a][$b];\n	      }\n	    else\n	      \
{\n		$profile{$n}{seq}.=\"-\";\n	      }\n	  }\n  \
    }\n\n    $profile{n}=$nhits+1;\n    return %pr\
ofile;\n  }\nsub ebi_blast_xml2profile\n  {\n    m\
y ($name,$seq,$maxid, $minid, $mincov, $string)=(@\
_);\n    my ($L,$l, $a,$b,$c,$d,$nhits,@identifyer\
L,$identifyer);\n\n\n\n    $seq=~s/[^a-zA-Z]//g;\n\
    $L=length ($seq);\n    %hit=&xml2tag_list ($st\
ring, \"hit\");\n\n    for ($nhits=0,$a=0; $a<$hit\
{n}; $a++)\n      {\n	my ($ldb,$id, $identity, $ex\
pectation, $start, $end, $coverage, $r);\n	my (%Q,\
%M,%E,%I);\n\n	$ldb=&tag2value ($hit{$a}{open}, \"\
database\");\n	$identifyer=&tag2value ($hit{$a}{op\
en}, \"id\");\n\n	$description=&tag2value ($hit{$a\
}{open}, \"description\");\n\n	%Q=&xml2tag_list ($\
hit{$a}{body}, \"querySeq\");\n	%M=&xml2tag_list (\
$hit{$a}{body}, \"matchSeq\");\n	%E=&xml2tag_list \
($hit{$a}{body}, \"expectation\");\n	%I=&xml2tag_l\
ist ($hit{$a}{body}, \"identity\");\n\n\n	for ($b=\
0; $b<$Q{n}; $b++)\n	  {\n\n	    $qs=$Q{$b}{body};\
\n	    $ms=$M{$b}{body};\n\n	    $expectation=$E{$\
b}{body};\n	    $identity=$I{$b}{body};\n\n\n	    \
$start=&tag2value ($Q{$b}{open}, \"start\");\n	   \
 $end=&tag2value ($Q{$b}{open}, \"end\");\n	    $s\
tartM=&tag2value ($M{$b}{open}, \"start\");\n	    \
$endM=&tag2value ($M{$b}{open}, \"end\");\n	    $c\
overage=(($end-$start)*100)/$L;\n\n	   # print \"$\
id: ID: $identity COV: $coverage [$start $end]\\n\\
";\n\n	    if ($identity>$maxid || $identity<$mini\
d || $coverage<$mincov){next;}\n	    # print \"KEE\
P\\n\";\n\n\n	    @lr1=(split (//,$qs));\n	    @lr\
2=(split (//,$ms));\n	    $l=$#lr1+1;\n	    for ($\
c=0;$c<$L;$c++){$p[$nhits][$c]=\"-\";}\n	    for (\
$d=0,$c=0; $c<$l; $c++)\n	      {\n		$r=$lr1[$c];\\
n		if ( $r=~/[A-Za-z]/)\n		  {\n\n		    $p[$nhits]\
[$d + $start-1]=$lr2[$c];\n		    $d++;\n		  }\n	  \
    }\n\n	    $Qseq[$nhits]=$qs;\n	    $Hseq[$nhit\
s]=$ms;\n	    $QstartL[$nhits]=$start;\n	    $Hsta\
rtL[$nhits]=$Hstart;\n	    $identityL[$nhits]=$ide\
ntity;\n	    $endL[$nhits]=$end;\n	    $definition\
L[$nhits]=$definition;\n	    $identifyerL[$nhits]=\
$identifyer;\n	    $comment[$nhits]=\"$ldb|$identi\
fyer [Eval=$expectation][id=$identity%][start=$sta\
rtM end=$endM]\";\n	    $nhits++;\n	  }\n      }\n\
\n    $profile{n}=0;\n    $profile{$profile{n}}{na\
me}=$name;\n    $profile{$profile{n}}{seq}=$seq;\n\
    $profile {n}++;\n\n    for ($a=0; $a<$nhits; $\
a++)\n      {\n	$n=$a+1;\n	$profile{$n}{name}=\"$n\
ame\\_$a\";\n	$profile{$n}{seq}=\"\";\n	$profile{$\
n}{Qseq}=$Qseq[$a];\n	$profile{$n}{Hseq}=$Hseq[$a]\
;\n	$profile{$n}{Qstart}=$QstartL[$a];\n	$profile{\
$n}{Hstart}=$HstartL[$a];\n	$profile{$n}{identity}\
=$identityL[$a];\n	$profile{$n}{definition}=$defin\
itionL[$a];\n	$profile{$n}{identifyer}=$identifyer\
L[$a];\n	$profile{$n}{comment}=$comment[$a];\n\n	f\
or ($b=0; $b<$L; $b++)\n	  {\n	    if ($p[$a][$b])\
\n	      {\n		$profile{$n}{seq}.=$p[$a][$b];\n	   \
   }\n	    else\n	      {\n		$profile{$n}{seq}.=\"\
-\";\n	      }\n	  }\n      }\n    $profile{n}=$nh\
its+1;\n\n    return %profile;\n  }\nsub output_pr\
ofile\n  {\n    my ($outfile,$profileR, $trim)=(@_\
);\n    my ($a);\n    my %profile=%$profileR;\n   \
 my $P= new FileHandle;\n    my $tmp=vtmpnam();\n\\
n    open ($P, \">$tmp\");\n    for ($a=0; $a<$pro\
file{n}; $a++)\n      {\n	print $P \">$profile{$a}\
{name} $profile{$a}{comment}\\n$profile{$a}{seq}\\\
n\";\n      }\n    close ($P);\n\n    if ( $trim)\\
n      {\n	\n	if ($trim>0)\n	  {\n	    &safe_syste\
m (\"t_coffee -other_pg seq_reformat -in $tmp -act\
ion +trim _aln_n$trim\\_K1 -output fasta_aln -out \
$outfile\");\n	  }\n	else\n	  {\n	    &safe_system\
 (\"t_coffee -other_pg seq_reformat -in $tmp -acti\
on +trim _aln_%%$trim\\_K1 -output fasta_aln -out \
$outfile\");\n	  }\n      }\n    else\n      {\n	&\
safe_system (\"mv $tmp $outfile\");\n      }\n    \
return;\n  }\nsub blast_xml2hit_list\n  {\n    my \
$string=(@_[0]);\n    return &xml2tag_list ($strin\
g, \"hit\");\n  }\nsub xmltag2value\n  {\n    my (\
$string_in, $tag)=@_;\n    my %TAG;\n    %TAG=xml2\
tag_list ($string_in, $tag);\n    return $TAG{0}{b\
ody};\n  }\n\nsub xml2tag_list\n  {\n    my ($stri\
ng_in,$tag)=@_;\n    my $tag_in, $tag_out;\n    my\
 %tag;\n\n    if (-e $string_in)\n      {\n	$strin\
g=&file2string ($string_in);\n      }\n    else\n \
     {\n	$string=$string_in;\n      }\n    $tag_in\
1=\"<$tag \";\n    $tag_in2=\"<$tag>\";\n    $tag_\
out=\"/$tag>\";\n    $string=~s/>/>##1/g;\n    $st\
ring=~s/</##2</g;\n    $string=~s/##1/<#/g;\n    $\
string=~s/##2/#>/g;\n    @l=($string=~/(\\<[^>]+\\\
>)/g);\n    $tag{n}=0;\n    $in=0;$n=-1;\n\n\n\n  \
  foreach $t (@l)\n      {\n\n	$t=~s/<#//;\n	$t=~s\
/#>//;\n\n	if ( $t=~/$tag_in1/ || $t=~/$tag_in2/)\\
n	  {\n\n	    $in=1;\n	    $tag{$tag{n}}{open}=$t;\
\n	    $n++;\n\n	  }\n	elsif ($t=~/$tag_out/)\n	  \
{\n\n\n	    $tag{$tag{n}}{close}=$t;\n	    $tag{n}\
++;\n	    $in=0;\n	  }\n	elsif ($in)\n	  {\n\n	   \
 $tag{$tag{n}}{body}.=$t;\n	  }\n      }\n\n    re\
turn %tag;\n  }\n\n\nsub seq2gor_prediction\n  {\n\
    my ($name, $seq,$infile, $outfile, $gor_seq, $\
gor_obs)=(@_);\n    my ($l);\n\n    `gorIV -prd $i\
nfile -seq $gor_seq -obs $gor_obs > gor_tmp`;\n   \
 open (GR, \">$outfile\");\n    open (OG, \"gor_tm\
p\");\n\n    while (<OG>)\n      {\n\n	$l=$_;\n	if\
 ($l=~/\\>/){print GR \"$l\";}\n	elsif ( $l=~/Pred\
icted Sec. Struct./)\n	  {\n	    $l=~s/Predicted S\
ec. Struct\\.//;\n	    print GR \"$l\";\n	  }\n   \
   }\n    close (GR);\n    close (OG);\n    return\
;\n  }\nsub seq2msa_tm_prediction\n  {\n    my ($n\
ame, $seq, $db, $infile, $outfile, $arch, $psv)=(@\
_);\n    my (%p,%gseq,%R, $blast_output, %s, $l);\\
n    my $R2=new FileHandle;\n    my $method=\"psit\
m\";\n    my $SERVER=\"EBI\";\n\n    $blast_output\
=&run_blast ($name,\"blastp\", $db, $infile, \"out\
file\");\n\n    if (&cache_file(\"GET\",$infile,$n\
ame,$method,$db,$outfile,$SERVER))\n      {\n	prin\
t \"\\tPSITM: USE Cache\\n\";\n	return $outfile;\n\
      }\n    else\n      {\n	$CACHE_STATUS=\"COMPU\
TE CACHE\";\n	%p=blast_xml2profile($name,$seq,$max\
id, $minid,$mincov,$blast_output);\n\n\n	open (F, \
\">tm_input\");\n	for (my $a=0; $a<$p{n}; $a++)\n	\
  {\n	    my $s;\n\n	    $s=$p{$a}{seq};\n	    $s=\
uc($s);\n	    print F \">$p{$a}{name}\\n$s\\n\";\n\
	    #print stdout \">$p{$a}{name}\\n$s\\n\";\n	  \
}\n	close (F);\n	print \"\\tPSITM: kept  $p{n} Hom\
ologues for Sequence $p{0}{name}\\n\";\n	&safe_sys\
tem (\"t_coffee -other_pg fasta_seq2hmmtop_fasta.p\
l -in=tm_input -out=$outfile -output=cons -cov=70 \
-trim=95 -arch=$arch -psv=$psv\");\n	unlink (\"tm_\
input\");\n	&cache_file(\"SET\",$infile,$name,$met\
hod,$db,$outfile,$SERVER);\n	return;\n      }\n  }\
\n\n\nsub seq2msa_gor_prediction\n  {\n    my ($na\
me, $seq,$infile, $outfile, $gor_seq, $gor_obs)=(@\
_);\n    my (%p,%gseq,%R, $blast_output, %s, $l);\\
n    my $R2=new FileHandle;\n    my $db=\"uniprot\\
";\n    my $method=\"psigor\";\n    my $SERVER=\"E\
BI\";\n\n    $blast_output=&run_blast ($name,\"bla\
stp\", \"uniprot\", $infile, \"outfile\");\n\n    \
if (&cache_file(\"GET\",$infile,$name,$method,$db,\
$outfile,$SERVER))\n      {\n	print \"\\tPSIGOR: U\
SE Cache\\n\";\n	return $outfile;\n      }\n    el\
se\n      {\n	$CACHE_STATUS=\"COMPUTE CACHE\";\n	%\
p=blast_xml2profile($name,$seq,$maxid, $minid,$min\
cov,$blast_output);\n\n\n	open (F, \">gor_input\")\
;\n	for (my $a=0; $a<$p{n}; $a++)\n	  {\n	    my $\
s;\n\n	    $s=$p{$a}{seq};\n	    $s=uc($s);\n	    \
print F \">$p{$a}{name}\\n$s\\n\";\n	    #print st\
dout \">$p{$a}{name}\\n$s\\n\";\n	  }\n	close (F);\
\n	print \"\\tGORTM: kept  $p{n} Homologues for Se\
quence $p{0}{name}\\n\";\n	&safe_system (\"t_coffe\
e -other_pg fasta_seq2hmmtop_fasta.pl -in=gor_inpu\
t -out=$outfile -output=cons -cov=70 -trim=95 -gor\
_seq=$gor_seq -gor_obs=$gor_obs -mode=gor\");\n	un\
link (\"tm_input\");\n	&cache_file(\"SET\",$infile\
,$name,$method,$db,$outfile,$SERVER);\n	return;\n \
     }\n  }\n\n\n\nsub run_blast\n  {\n    my ($na\
me, $method, $db, $infile, $outfile, $run)=(@_);\n\
    if (!$run){$run=1;}\n    my $error_log=vtmpnam\
();\n    my $cl_db;\n    \n    if (&cache_file(\"G\
ET\",$infile,$name,$method,$db,$outfile,$SERVER) &\
& is_valid_blast_xml ($outfile))\n      {return $o\
utfile;}\n    else\n      {\n	$CACHE_STATUS=\"COMP\
UTE CACHE\";\n	if ( $SERVER eq \"EBI_SOAP\")\n	  {\
\n	    &check_configuration (\"EMAIL\",\"SOAP::Lig\
ht\",\"INTERNET\");\n\n	    $cl_method=$method;\n	\
    if ($cl_method =~/wu/)\n	      {\n		$cl_method\
=~s/wu//;\n		if ( $cl_method eq \"psiblast\")\n		 \
 {\n		    add_warning($$,$$,\"PSI BLAST cannot be \
used with the wuBLAST Client. Use server=EBI Or se\
rver=LOCAL. blastp will be used instead\");\n		   \
 $cl_method=\"blastp\";\n		  }\n\n		$command=\"t_c\
offee -other_pg wublast.pl --email $EMAIL $infile \
-D $db -p $cl_method --outfile $outfile -o xml>/de\
v/null 2>$error_log\";\n		&safe_system ( $command)\
;\n		if (-e \"$outfile.xml\") {`mv $outfile.xml $o\
utfile`;}\n	      }\n	    else\n	      {\n		if ($c\
l_method eq \"psiblast\"){$cl_method =\"blastp -j5\
\";}\n\n		$command=\"t_coffee -other_pg blastpgp.p\
l --email $EMAIL $infile -d $db --outfile $outfile\
 -p $cl_method --mode PSI-Blast>/dev/null 2>$error\
_log\";\n		&safe_system ( $command);\n\n		if (-e \\
"$outfile.xml\") {`mv $outfile.xml $outfile`;}\n	 \
     }\n	  }\n	elsif ($SERVER eq \"EBI_REST\" || $\
SERVER eq \"EBI\")\n	  {\n	    $cl_method=$method;\
\n	    &check_configuration(\"EMAIL\",\"XML::Simpl\
e\", \"INTERNET\");\n	    if ($db eq \"uniprot\"){\
$db1=\"uniprotkb\";}\n	    else {$db1=$db;}\n\n	  \
  \n	    if ($cl_method =~/wu/)\n	      {\n		$cl_m\
ethod=~s/wu//;\n		if ( $cl_method eq \"psiblast\")\
{$cl_method=\"blastp\";}\n\n		$command=\"t_coffee \
-other_pg wublast_lwp.pl --email $EMAIL -D $db1 -p\
 $cl_method --outfile $outfile --align 5 --stype p\
rotein $infile>/dev/null 2>error_log\";\n	      }\\
n	    else\n	      {\n		if ( $cl_method =~/psiblas\
t/){$cl_method =\"blastp -j5\";}\n		$command=\"t_c\
offee -other_pg ncbiblast_lwp.pl --email $EMAIL -D\
 $db1 -p $cl_method --outfile $outfile --align 5 -\
-stype protein $infile>/dev/null 2>$error_log\";\n\
		#DEBUG\n		#$command=\"t_coffee -other_pg ncbibla\
st_lwp.pl --email $EMAIL -D $db1 -p $cl_method --o\
utfile $outfile --align 5 --stype protein $infile\\
";\n		\n		my $maxrun=5;#number of crashes accepetd\
\n		my $nrun;\n		my $keep_going=1;\n		while ($keep\
_going)\n		  {\n		    \n		    #print \"----- $comm\
and [$nrun]\\n\";\n		    $nrun++;\n		    $keep_goi\
ng=0;\n		    &safe_system ( $command,5);\n		    \n\
		    my $success=0;\n		    $success =$success || \
-e \"$outfile.out.xml\";\n		    $success =$success\
 || -e \"$outfile.xml.xml\";\n		    $success =$suc\
cess || -e \"$outfile.out..xml\";\n		    $success \
=$success || -e \"$outfile.xml..xml\";\n		    \n		\
    if (!$success && ($nrun<$maxrun || -e \"$outfi\
le.out.txt\"))\n		      {\n			$keep_going=1;\n			a\
dd_warning($$,$$,\"[ncbiblast_lwp.pl] [$command] f\
ailed to produce xml output -- will ne tried again\
 [$nrun]\");\n		      }\n		  }\n		\n		if (-e \"$ou\
tfile.out.xml\") {`mv $outfile.out.xml $outfile`;}\
\n		elsif (-e \"$outfile.xml.xml\"){`mv $outfile.x\
ml.xml $outfile`;}\n		elsif (-e \"$outfile.out..xm\
l\") {`mv $outfile.out..xml $outfile`;}\n		elsif (\
-e \"$outfile.xml..xml\"){`mv $outfile.xml..xml $o\
utfile`;}\n		else\n		  {\n		    add_warning($$,$$,\
\"[ncbiblast_lwp.pl] [$command] failed to produce \
xml output\");\n		  }\n	      }\n	  }\n	elsif ($SE\
RVER eq \"NCBI\")\n	  {\n	    &check_configuration\
 (\"INTERNET\");\n	    if ($db eq \"uniprot\"){$cl\
_db=\"swissprot\";}\n	    else {$cl_db=$db;}\n\n	 \
   if ( $method eq \"psiblast\")\n	      {\n		add_\
warning($$,$$,\"PSI BLAST cannot be used with the \
NCBI BLAST Client. Use server=EBI Or server=LOCAL.\
 blastp will be used instead\");\n		$cl_method=\"b\
lastp\";\n	      }\n	    else\n	      {\n		$cl_met\
hod=$method;\n	      }\n	      \n	    &check_confi\
guration ($cl_method);  \n	    $command=\"$cl_meth\
od -db $cl_db -query $infile -out $outfile -outfmt\
 5 -remote\";\n	    &safe_system ($command);\n	  }\
\n	elsif ($SERVER =~/CLIENT_(.*)/)\n	  {\n	    my \
$client=$1;\n	    $command=\"$client -p $method -d\
 $db -i $infile -o $outfile -m 7\";\n	    &safe_sy\
stem ($command);\n	  }\n	elsif ( $SERVER eq \"LOCA\
L_blastall\")\n	  {\n	    &check_configuration (\"\
blastall\");\n	    if ($method eq \"blastp\")\n	  \
    {\n		$command=\"blastall -d $db -i $infile -o \
$outfile -m7 -p blastp\";\n	      }\n	    &safe_sy\
stem ($command);\n	  }\n	elsif ( $SERVER eq \"LOCA\
L\")\n	  {\n	    if ($ENV{\"BLAST_DB_DIR\"}) {\n	 \
   	$x=$ENV{\"BLAST_DB_DIR\"};\n			$cl_db=\"$x/$db\
\";\n	    }\n	    else{\n			$cl_db=$db;\n	    }\n\\
n        ##\n		## BLAST+ provide different binarie\
s names and CLI options\n		## Use the 'legacy_blas\
t.pl' to keep compatibility with old blast command\
s\n		##\n		$path=`which legacy_blast.pl 2>/dev/nul\
l`;  \n		$path=`dirname $path`; \n		chomp($path);\\
n	    if ($method eq \"blastp\"){\n			&check_confi\
guration(\"legacy_blast.pl\");\n			$command=\"lega\
cy_blast.pl blastpgp --path $path -d $cl_db -i $in\
file -o $outfile -m7 -j1\";\n	    }\n	    elsif ($\
method eq \"psiblast\")\n	      {\n		&check_config\
uration(\"legacy_blast.pl\");\n		$command=\"legacy\
_blast.pl blastpgp --path $path -d $cl_db -i $infi\
le -o $outfile -m7 -j5\";\n	      }\n	    elsif ($\
method eq \"blastn\")\n	      {\n		&check_configur\
ation(\"legacy_blast.pl\");\n		$command=\"legacy_b\
last.pl blastall --path $path -p blastn -d $cl_db \
-i $infile -o $outfile -m7 -W6\";\n	      }\n	    \
&safe_system ($command);\n	  }\n	else\n	  {\n\n	  \
  myexit(add_error (EXIT_FAILURE,$$,$$,getppid(), \
\"BLAST_FAILURE::UnknownServer\",$CL));\n	  }\n\n\\
n	#Check that everything went well\n\n	if ( !-e $o\
utfile || !&is_valid_blast_xml($outfile))\n	  {\n\\
n	    if ( -e $outfile)\n	      {\n		add_warning (\
$$,$$,\"Corrupted Blast Output (Run $run)\");\n		u\
nlink($outfile);\n	      }\n	    if ( -e $error_lo\
g)\n	      {\n\n		my $error_msg=file2string ($erro\
r_log);\n\n		if ( $error_msg =~/enter a valid emai\
l/)\n		  {\n		    myexit(add_error (EXIT_FAILURE,$\
$,$$,getppid(), \"BLAST_FAILURE::Invalid_or_reject\
ed_email::$EMAIL\", \"$command\"));\n		  }\n	     \
 }\n	    if ( $run==$BLAST_MAX_NRUNS)\n	      {\n\\
n		myexit(add_error (EXIT_FAILURE,$$,$$,getppid(),\
 \"BLAST_FAILURE::UnknownReason\", \"$command\"));\
\n	      }\n	    else\n	      {\n		my $out;\n		if \
($SERVER eq \"NCBI\") {$SERVER=\"EBI\"; }\n		elsif\
 ($SERVER eq \"EBI\"){$SERVER=\"NCBI\";}\n		add_wa\
rning ($$,$$,\"Blast for $name failed (Run: $run o\
ut of $BLAST_MAX_NRUNS. Use $SERVER)\");\n		$out=&\
run_blast ($name, $method, $db,$infile, $outfile, \
$run+1);\n		if ($SERVER eq \"NCBI\") {$SERVER=\"EB\
I\"; }\n		elsif ($SERVER eq \"EBI\"){$SERVER=\"NCB\
I\";}\n		return $out;\n	      }\n	  }\n\n	&cache_f\
ile(\"SET\",$infile,$name,$method,$db,$outfile,$SE\
RVER);\n	#system (\"cp $outfile ~/Dropbox/tmp/cedr\
ic.out\");\n	#die;\n	return $outfile;\n      }\n  \
}\n\nsub cache_file\n  {\n    my ($cache_mode,$inf\
ile,$name,$method,$db, $outfile,$server)=(@_);\n  \
  my $cache_file;\n    #Protect names so that they\
 can be turned into legal filenames\n    $name=&cl\
ean_file_name ($name);\n\n    if ($db=~/\\//)\n   \
   {\n	$db=~/([^\\/]+)$/;\n	$db=$1;\n      }\n    \
$cache_file_sh=\"$name.$method.$db.$server.tmp\";\\
n    $cache_file=\"$CACHE/$name.$method.$db.$serve\
r.tmp\";\n\n    if ($infile ne \"\")\n      {\n	$c\
ache_file_infile_sh=\"$name.$method.$db.$server.in\
file.tmp\";\n	$cache_file_infile=\"$CACHE/$name.$m\
ethod.$db.$server.infile.tmp\";\n      }\n\n    if\
 ($cache_mode eq \"GET\")\n      {\n	if ($CACHE eq\
 \"\" || $CACHE eq \"no\" || $CACHE eq \"ignore\" \
 || $CACHE eq \"local\" || $CACHE eq \"update\"){r\
eturn 0;}\n	elsif ( !-d $CACHE)\n	  {\n	    print \
STDERR \"ERROR: Cache Dir: $CACHE Does not Exist\"\
;\n	    return 0;\n	  }\n	else\n	  {\n	    if ( -e\
 $cache_file && &fasta_file1_eq_fasta_file2($infil\
e,$cache_file_infile)==1)\n	      {\n		`cp $cache_\
file $outfile`;\n		$CACHE_STATUS=\"READ CACHE\";\n\
		return 1;\n	      }\n	  }\n      }\n    elsif ($\
cache_mode eq \"SET\")\n      {\n	if ($CACHE eq \"\
\" || $CACHE eq \"no\" || $CACHE eq \"ignore\"  ||\
 $CACHE eq \"local\" || $CACHE eq \"update\"){retu\
rn 0;}\n	elsif ( !-d $CACHE)\n	  {\n	    print STD\
ERR \"ERROR: Cache Dir: $CACHE Does not Exist\";\n\
	    return 0;\n	  }\n	elsif (-e $outfile)\n	  {\n\
	    `cp $outfile $cache_file`;\n	    if ($cache_f\
ile_infile ne \"\"){ `cp $infile $cache_file_infil\
e`;}\n\n	    #functions for updating the cache\n	 \
   #`t_coffee -other_pg clean_cache.pl -file $cach\
e_file_sh -dir $CACHE`;\n	    #`t_coffee -other_pg\
 clean_cache.pl -file $cache_file_infile_sh -dir $\
CACHE`;\n	    return 1;\n	  }\n      }\n    $CACHE\
_STATUS=\"COMPUTE CACHE\";\n    return 0;\n  }\nsu\
b file1_eq_file2\n  {\n    my ($f1, $f2)=@_;\n    \
if ( $f1 eq \"\"){return 1;}\n    elsif ( $f2 eq \\
"\"){return 1;}\n    elsif ( !-e $f1){return 0;}\n\
    elsif ( !-e $f2){return 0;}\n    elsif ($f1 eq\
 \"\" || $f2 eq \"\" || `diff $f1 $f2` eq \"\"){re\
turn 1;}\n\n    return 0;\n  }\nsub clean_file_nam\
e\n  {\n    my $name=@_[0];\n\n    $name=~s/[^A-Za\
-z1-9.-]/_/g;\n    return $name;\n  }\nsub url2fil\
e\n  {\n    my ($address, $out)=(@_);\n\n    if (&\
pg_is_installed (\"wget\"))\n	{\n	  return &safe_s\
ystem (\"wget $address -O$out >/dev/null 2>/dev/nu\
ll\");\n	}\n    elsif (&pg_is_installed (\"curl\")\
)\n      {\n	return &safe_system (\"curl $address \
-o$out >/dev/null 2>/dev/null\");\n      }\n    el\
se\n      {\n	myexit(flus_error(\"neither curl nor\
 wget are installed. Imnpossible to fectch remote \
file\"));\n	exit ($EXIT_FAILURE);\n      }\n  }\ns\
ub fasta_file1_eq_fasta_file2\n  {\n    my ($f1, $\
f2)=@_;\n    my (%s1, %s2);\n    my @names;\n    %\
s1=read_fasta_seq ($f1);\n    %s2=read_fasta_seq (\
$f2);\n\n    @names=(keys (%s1));\n\n    foreach $\
n (keys(%s1))\n      {\n	if ($s1{$n}{seq} ne $s2{$\
n}{seq}){return 0;}\n      }\n\n    foreach $n (ke\
ys(%s2))\n      {\n	if ($s1{$n}{seq} ne $s2{$n}{se\
q}){return 0;}\n      }\n    return 1;\n  }\n\n\n\\
nsub read_template_file\n  {\n    my $pdb_template\
s = @_[0];\n    my $tmp=new FileHandle;\n    open \
($tmp, \"<$pdb_templates\");\n    my %temp_h;\n   \
 my ($skip,$seq, $temp);\n\n    #supports both a s\
imple [seq pdb] format and the regular fasta like \
template format\n    while (<$tmp>)\n      {\n	\n	\
$line = $_;\n	if ($line=~/\\>(\\S+)\\s_._\\s(\\S+)\
/){$temp_h{$1}= $2;}\n	elsif ($line =~/(\\S+)\\s(\\
\S+)/){$temp_h{$1}= $2;}\n      }\n    close($tmp)\
;\n    return %temp_h;\n  }\n\n\n\n\n\n\nsub seq2t\
blastx_lib\n  {\n    my ($mode, $infile, $outfile)\
=@_;\n    my (%s, $method,$nseq);\n\n    $method=$\
mode;\n    &set_temporary_dir (\"set\",$infile,\"i\
nfile\");\n    %s=read_fasta_seq(\"infile\");\n\n\\
n    foreach $seq (keys(%s))\n      {\n	$slist[$s{\
$seq}{order}]=$s{$seq}{seq};\n	$sname[$s{$seq}{ord\
er}]=$s{$seq}{name};\n	$slen[$s{$seq}{order}]=leng\
th ($s{$seq}{seq});\n      }\n    $nseq=$#sname+1;\
\n    open (F, \">outfile\");\n    print F \"! TC_\
LIB_FORMAT_01\\n\";\n    print F \"$nseq\\n\";\n  \
  for ($a=0; $a<$nseq;$a++)\n      {\n	print F \"$\
sname[$a] $slen[$a]  $slist[$a]\\n\"\n      }\n   \
 close (F);\n    &safe_system (\"formatdb -i infil\
e -p F\");\n    &safe_system (\"blastall -p tblast\
x -i infile -d infile -m 7 -S1>blast.output\");\n\\
n    ncbi_tblastx_xml2lib_file (\"outfile\", file2\
string (\"blast.output\"));\n    &set_temporary_di\
r (\"unset\",$mode, $method, \"outfile\",$outfile)\
;\n    myexit ($EXIT_SUCCESS);\n    }\nsub seq2tbl\
astpx_lib\n  {\n    my ($mode, $infile, $outfile)=\
@_;\n    my (%s, $method,$nseq);\n    $method=$mod\
e;\n    &set_temporary_dir (\"set\",$infile,\"infi\
le\");\n    %s=read_fasta_seq(\"infile\");\n\n    \
foreach $seq (keys(%s))\n      {\n	$slist[$s{$seq}\
{order}]=$s{$seq}{seq};\n	$sname[$s{$seq}{order}]=\
$s{$seq}{name};\n	$slen[$s{$seq}{order}]=length ($\
s{$seq}{seq});\n      }\n    $nseq=$#sname+1;\n   \
 open (F, \">outfile\");\n    print F \"! TC_LIB_F\
ORMAT_01\\n\";\n    print F \"$nseq\\n\";\n    for\
 ($a=0; $a<$nseq;$a++)\n      {\n	print F \"$sname\
[$a] $slen[$a]  $slist[$a]\\n\"\n      }\n    clos\
e (F);\n    &safe_system(\"t_coffee -other_pg seq_\
reformat -in infile -output tblastx_db1 > tblastxd\
b\");\n    &safe_system (\"formatdb -i tblastxdb -\
p T\");\n    &safe_system (\"blastall -p blastp -i\
 tblastxdb -d tblastxdb -m7 >blast.output\");\n   \
 ncbi_tblastpx_xml2lib_file (\"outfile\", file2str\
ing (\"blast.output\"), %s);\n    &set_temporary_d\
ir (\"unset\",$mode, $method, \"outfile\",$outfile\
);\n    myexit ($EXIT_SUCCESS);\n    }\n\nsub x3dn\
a_find_pair2lib\n      {\n      my ($seq, $pdb, $l\
ib, $pg)=@_;\n      my $outfile1=\"dssr-2ndstrs.db\
n\";\n      my $outfile2=\"simple.output\";\n     \
 my $f= new FileHandle;\n      my ($rnaSS,$pdbSS);\
\n      my $command;\n      my %s_pdb;\n      my %\
s_seq;\n      \n      #$pg: \"find_pair\" OR \"fin\
d_pair -p\"\n      \n      if (!pg_is_installed (\\
"find_pair\"))\n	{\n	  add_warning ($$,$$, \"x3dna\
/find_pairs could not be used to extract RNA secon\
dary structures. Secondary structures will be extr\
acted by x3dna-ssr instead\");\n	  return x3dnassr\
2lib ($seq, $pdb, $lib);\n	}\n      \n      #get P\
DB sequence\n      safe_system (\"t_coffee -other_\
pg extract_from_pdb $pdb -seq >$outfile1\");\n    \
  \n      #get find_pair contacts\n      $command=\
\"$pg $pdb simple.output > /dev/null 2>/dev/null\"\
;\n      safe_system ($command);\n\n      if (($co\
mmand=~/find_pair -p/)){$outfile2=\"allpairs.ana\"\
;}\n      else {$outfile2=\"simple.output\";}\n   \
   \n      if ( !-e $outfile2)\n	{\n	  myexit(flus\
h_error(\"x3dna failed to compute the secondary st\
ructure file $outfile2 for $pdb\"));\n	  myexit ($\
EXIT_FAILURE);\n	}\n      \n\n      #Handle situat\
ions when the pdb sequence differs from the RNA se\
quence\n      #my @out=file2array($outfile1);\n   \
   %s_pdb=read_fasta_seq_index ($outfile1);\n     \
 %s_seq=read_fasta_seq_index ($seq);\n      my $rn\
aS=uc($s_seq{0}{seq});\n      my $pdbS=uc($s_pdb{0\
}{seq});\n      \n      my $vienna;\n      my @lu;\
\n    \n      if ($rnaS ne $pdbS)\n	{\n	  \n	  my \
($rna,$pdb);\n	  $rnaSS=$rnaS;\n	  $pdbSS=$pdbS;\n\
	  $rnaSS=~s/T/U/g;\n	  $pdbSS=~s/T/U/g;\n	  ($rna\
SS,$pdbSS)=nw ($rnaS, $pdbS);\n	  \n	  my @rnaA =s\
plit (//,$rnaSS);\n	  my @pdbA=split (//,$pdbSS);\\
n	  my $l=@rnaA;\n	  \n	  #print \"\\n--- $s_seq{0\
}{name} $rnaSS\\n--- $s_seq{0}{name} $pdbSS\\n\\n\\
";\n	  \n	  for (my $b=0,my $a=0; $a<$l; $a++)\n	 \
   {\n	      if   ($rnaA[$a] ne '-' && $pdbA[$a] n\
e '-'){$lu[++$pdb]=++$rna;}\n	      elsif($rnaA[$a\
] eq '-'){$lu[++$pdb]=-1;}\n	      elsif($pdbA[$a]\
 eq '-'){++$rna;}\n	    }\n	}\n      else\n	{\n	  \
for (my $a=0; $a<=length ($rnaS); $a++)\n	    {\n	\
      $lu[$a]=$a;\n	    }\n	}\n      my $l=length \
($rnaS);\n      open ($f, \">$lib\");\n      print\
 $f \"! TC_LIB_FORMAT_01\\n\";\n      print $f \"1\
\\n\";\n      print $f \"$s_seq{0}{name} $l $rnaS\\
\n\";\n      print $f \"!CMT: [SOURCE] >$s_seq{0}{\
name} 3D contact library Generated by $pg (x3dna)\\
\n\";\n      print $f \"#1 1\\n\";\n      \n      \
my $ne;\n      my @array=file2array($outfile2);\n \
     for (my $a=0; $a<5; $a++){shift (@array);}\n \
     while (!($array[0]=~/####/))\n	{\n	  my $line\
= shift (@array);\n	  my @l=($line=~/(\\d+)/g);\n	\
  \n	 \n	  my $f1=$lu[$l[0]];\n	  my $s1=$lu[$l[1]\
];\n\n	  #print \"\\n$line\\n$l[0] --> $f1\\n$l[1]\
 --> $s1\\n\\n\"; \n	  \n	  if (!$f1 || !$s1)\n	  \
  {\n	      print \"\\n---- $rnaSS\\n---- $pdbSS\\\
n$line\\n[$l[0] --- $l[1]]<---->[$f1 --- $s1]\\n\"\
;\n	      myexit(flush_error(\"Error while parsing\
 s3dna::find_pair output\"));\n	    }\n	  elsif ($\
f1==-1 || $s1==-1){;}\n	  elsif ($f1<$s1){print $f\
 \"$f1 $s1 100\\n\";}\n	  else {print $f \"$s1 $f1\
 100\\n\";$ne++;}\n	}\n      print $f \"! SEQ_1_TO\
_N\\n\";\n      close ($f);\n      return;\n    }\\
nsub RNAplfold2lib\n  {\n    my ($seq, $lib)=@_;\n\
    my $f= new FileHandle;\n    \n    &safe_system\
 (\"t_coffee -other_pg RNAplfold2tclib.pl -in=$seq\
 -out=$lib\");\n    \n    if ( !-e $lib)\n	{\n	 my\
exit(flush_error(\"RNAplfold failed to compute the\
 secondary structure of $s{$seq}{name}\"));\n	 mye\
xit ($EXIT_FAILURE);\n       }\n    open ($f, \">>\
$lib\");\n    print $f \"!CMT: [SOURCE] 2D contact\
 library Generated by RNAPlfold (Vienna Package)\\\
n\";\n    close $f;\n    return;\n  }\nsub x3dnass\
r2lib\n    {\n      my ($seq, $pdb, $lib)=@_;\n   \
   my $outfile=\"dssr-2ndstrs.dbn\";\n      my $f=\
 new FileHandle;\n      \n\n      if (!pg_is_insta\
lled (\"x3dna-ssr\"))\n	{\n	  add_warning ($$,$$, \
\"x3dna-ssr could not be used to extract RNA secon\
dary structures. Secondary structures will be pred\
icted ab-initio instead with RNAPlfold\");\n	  ret\
urn RNAplfold2lib ($seq,$lib);\n	}\n      \n      \
safe_system (\"x3dna-ssr -i=$pdb >/dev/null 2>/dev\
/null\");\n      if ( !-e $outfile)\n	{\n	  myexit\
(flush_error(\"x3dna-ssr failed to compute the sec\
ondary structure file \"));\n	  myexit ($EXIT_FAIL\
URE);\n	}\n\n      #Handle situations when the pdb\
 sequence differs from the RNA sequence\n      @ou\
t=file2array($outfile);\n      my %s=read_fasta_se\
q ($seq);\n      my @names=keys (%s);\n      my $r\
naS=uc($s{$names[0]}{seq});\n      my $pdbS=uc($ou\
t[1]);\n      my $vienna;\n      \n      #x3dna re\
turns non legitimate nucleotides\n       $pdbS=~s/\
[^AGCTU]//g;\n      \n      if ($rnaS ne $pdbS)\n	\
{\n	  my ($rna,$pdb);\n	  my $rnaSS=$rnaS;\n	  my \
$pdbSS=$pdbS;\n	  $rnaSS=~s/T/U/g;\n	  $pdbSS=~s/T\
/U/g;\n	  ($rnaSS,$pdbSS)=nw ($rnaSS, $pdbSS);\n	 \
 my @rnaA =split (//,$rnaSS);\n	  my @pdbA=split (\
//,$pdbSS);\n	  my @SS=split (//, $out[2]);\n	  \n\
	  my $l=@rnaA;\n	  for (my $b=0,my $a=0; $a<$l; $\
a++)\n	    {\n	      if   ($rnaA[$a] ne '-' && $pd\
bA[$a] ne '-'){$vienna.=$SS[$b++];}\n	      elsif(\
$rnaA[$a] eq '-'){$b++;}\n	      elsif($pdbA[$a] e\
q '-'){$vienna.='.';}\n	    }\n	}\n      else\n	{\\
n	  $vienna=$out[2];\n	}\n    \n\n      open ($f, \
\">seq\");\n      print $f \">$names[0]\\n$rnaS\\n\
\";\n      close $f;\n      \n      open ($f, \">s\
tr\");\n      print $f \">$names[0]\\n$vienna\\n\"\
;\n      close $f;\n      \n      safe_system (\"t\
_coffee -other_pg seq_reformat -in seq -in2 str -o\
utput vienna2tc_lib >$lib\");\n      if ( !-e $lib\
)\n	    {\n	      myexit(flush_error(\"seq_reforma\
t failed to convert your secondary structure\"));\\
n	      myexit ($EXIT_FAILURE);\n	    }\n      \n \
     open ($f, \">>$lib\");\n      print $f \"!CMT\
: [SOURCE] >$names[0] 2D Contact library generated\
 by x3dna-ssr\\n\";\n      #print $f \"! Vienna_Fo\
rmat: >$names[0]\\n\";\n      #print $f \"! Vienna\
_Format: $vienna\\n\";\n      \n      close $f;\n \
     return;\n    }\n\n\nsub file2head\n      {\n	\
my $file = shift;\n	my $size = shift;\n	my $f= new\
 FileHandle;\n	my $line;\n	open ($f,$file);\n	read\
 ($f,$line, $size);\n	close ($f);\n	return $line;\\
n      }\nsub file2tail\n      {\n	my $file = shif\
t;\n	my $size = shift;\n	my $f= new FileHandle;\n	\
my $line;\n\n	open ($f,$file);\n	seek ($f,$size*-1\
, 2);\n	read ($f,$line, $size);\n	close ($f);\n	re\
turn $line;\n      }\n\n\nsub vtmpnam\n      {\n	m\
y $r=rand(100000);\n	my $f=\"file.$r.$$\";\n	while\
 (-e $f)\n	  {\n	    $f=vtmpnam();\n	  }\n	push (@\
TMPFILE_LIST, $f);\n	return $f;\n      }\n\nsub my\
exit\n  {\n    my $code=@_[0];\n    if ($CLEAN_EXI\
T_STARTED==1){return;}\n    else {$CLEAN_EXIT_STAR\
TED=1;}\n    ### ONLY BARE EXIT\n    exit ($code);\
\n  }\nsub set_error_lock\n    {\n      my $name =\
 shift;\n      my $pid=$$;\n\n\n      &lock4tc ($$\
,\"LERROR\", \"LSET\", \"$$ -- ERROR: $name $PROGR\
AM\\n\");\n      return;\n    }\nsub set_lock\n  {\
\n    my $pid=shift;\n    my $msg= shift;\n    my \
$p=getppid();\n    &lock4tc ($pid,\"LLOCK\",\"LRES\
ET\",\"$p$msg\\n\");\n  }\nsub unset_lock\n   {\n\\
n    my $pid=shift;\n    &lock4tc ($pid,\"LLOCK\",\
\"LRELEASE\",\"\");\n  }\nsub shift_lock\n  {\n   \
 my $from=shift;\n    my $to=shift;\n    my $from_\
type=shift;\n    my $to_type=shift;\n    my $actio\
n=shift;\n    my $msg;\n\n    if (!&lock4tc($from,\
 $from_type, \"LCHECK\", \"\")){return 0;}\n    $m\
sg=&lock4tc ($from, $from_type, \"LREAD\", \"\");\\
n    &lock4tc ($from, $from_type,\"LRELEASE\", $ms\
g);\n    &lock4tc ($to, $to_type, $action, $msg);\\
n    return;\n  }\nsub isshellpid\n  {\n    my $p=\
shift;\n    if (!lock4tc ($p, \"LLOCK\", \"LCHECK\\
")){return 0;}\n    else\n      {\n	my $c=lock4tc(\
$p, \"LLOCK\", \"LREAD\");\n	if ( $c=~/-SHELL-/){r\
eturn 1;}\n      }\n    return 0;\n  }\nsub isroot\
pid\n  {\n    if(lock4tc (getppid(), \"LLOCK\", \"\
LCHECK\")){return 0;}\n    else {return 1;}\n  }\n\
sub lock4tc\n	{\n	  my ($pid,$type,$action,$value)\
=@_;\n	  my $fname;\n	  my $host=hostname;\n\n	  i\
f ($type eq \"LLOCK\"){$fname=\"$LOCKDIR/.$pid.$ho\
st.lock4tcoffee\";}\n	  elsif ( $type eq \"LERROR\\
"){ $fname=\"$LOCKDIR/.$pid.$host.error4tcoffee\";\
}\n	  elsif ( $type eq \"LWARNING\"){ $fname=\"$LO\
CKDIR/.$pid.$host.warning4tcoffee\";}\n\n	  if ($d\
ebug_lock)\n	    {\n	      print STDERR \"\\n\\t--\
-lock4tc(tcg): $action => $fname =>$value (RD: $LO\
CKDIR)\\n\";\n	    }\n\n	  if    ($action eq \"LCH\
ECK\") {return -e $fname;}\n	  elsif ($action eq \\
"LREAD\"){return file2string($fname);}\n	  elsif (\
$action eq \"LSET\") {return string2file ($value, \
$fname, \">>\");}\n	  elsif ($action eq \"LRESET\"\
) {return string2file ($value, $fname, \">\");}\n	\
  elsif ($action eq \"LRELEASE\")\n	    {\n	      \
if ( $debug_lock)\n		{\n		  my $g=new FileHandle;\\
n		  open ($g, \">>$fname\");\n		  print $g \"\\nD\
estroyed by $$\\n\";\n		  close ($g);\n		  safe_sy\
stem (\"mv $fname $fname.old\");\n		}\n	      else\
\n		{\n		  unlink ($fname);\n		}\n	    }\n	  retur\
n \"\";\n	}\n\nsub file2string\n	{\n	  my $file=@_\
[0];\n	  my $f=new FileHandle;\n	  my $r;\n	  open\
 ($f, \"$file\");\n	  while (<$f>){$r.=$_;}\n	  cl\
ose ($f);\n	  return $r;\n	}\nsub file2array\n	{\n\
	  my $file=@_[0];\n	  my $f=new FileHandle;\n	  m\
y @r;\n	  open ($f, \"$file\");\n	  while (<$f>){@\
r=(@r,$_);}\n	  close ($f);\n	  return @r;\n	}\nsu\
b string2file\n    {\n    my ($s,$file,$mode)=@_;\\
n    my $f=new FileHandle;\n\n    open ($f, \"$mod\
e$file\");\n    print $f  \"$s\";\n    close ($f);\
\n  }\n\nBEGIN\n    {\n      srand;\n\n      $SIG{\
'SIGUP'}='signal_cleanup';\n      $SIG{'SIGINT'}='\
signal_cleanup';\n      $SIG{'SIGQUIT'}='signal_cl\
eanup';\n      $SIG{'SIGILL'}='signal_cleanup';\n \
     $SIG{'SIGTRAP'}='signal_cleanup';\n      $SIG\
{'SIGABRT'}='signal_cleanup';\n      $SIG{'SIGEMT'\
}='signal_cleanup';\n      $SIG{'SIGFPE'}='signal_\
cleanup';\n\n      $SIG{'SIGKILL'}='signal_cleanup\
';\n      $SIG{'SIGPIPE'}='signal_cleanup';\n     \
 $SIG{'SIGSTOP'}='signal_cleanup';\n      $SIG{'SI\
GTTIN'}='signal_cleanup';\n      $SIG{'SIGXFSZ'}='\
signal_cleanup';\n      $SIG{'SIGINFO'}='signal_cl\
eanup';\n\n      $SIG{'SIGBUS'}='signal_cleanup';\\
n      $SIG{'SIGALRM'}='signal_cleanup';\n      $S\
IG{'SIGTSTP'}='signal_cleanup';\n      $SIG{'SIGTT\
OU'}='signal_cleanup';\n      $SIG{'SIGVTALRM'}='s\
ignal_cleanup';\n      $SIG{'SIGUSR1'}='signal_cle\
anup';\n\n\n      $SIG{'SIGSEGV'}='signal_cleanup'\
;\n      $SIG{'SIGTERM'}='signal_cleanup';\n      \
$SIG{'SIGCONT'}='signal_cleanup';\n      $SIG{'SIG\
IO'}='signal_cleanup';\n      $SIG{'SIGPROF'}='sig\
nal_cleanup';\n      $SIG{'SIGUSR2'}='signal_clean\
up';\n\n      $SIG{'SIGSYS'}='signal_cleanup';\n  \
    $SIG{'SIGURG'}='signal_cleanup';\n      $SIG{'\
SIGCHLD'}='signal_cleanup';\n      $SIG{'SIGXCPU'}\
='signal_cleanup';\n      $SIG{'SIGWINCH'}='signal\
_cleanup';\n\n      $SIG{'INT'}='signal_cleanup';\\
n      $SIG{'TERM'}='signal_cleanup';\n      $SIG{\
'KILL'}='signal_cleanup';\n      $SIG{'QUIT'}='sig\
nal_cleanup';\n\n      our $debug_lock=$ENV{\"DEBU\
G_LOCK\"};\n\n\n\n\n      foreach my $a (@ARGV){$C\
L.=\" $a\";}\n      if ( $debug_lock ){print STDER\
R \"\\n\\n\\n********** START PG: $PROGRAM *******\
******\\n\";}\n      if ( $debug_lock ){print STDE\
RR \"\\n\\n\\n**********(tcg) LOCKDIR: $LOCKDIR $$\
 *************\\n\";}\n      if ( $debug_lock ){pr\
int STDERR \"\\n --- $$ -- $CL\\n\";}\n\n\n\n\n   \
 }\nsub flush_error\n  {\n    my $msg=shift;\n    \
return add_error ($EXIT_FAILURE,$$, $$,getppid(), \
$msg, $CL);\n  }\nsub add_error\n  {\n    my $code\
=shift;\n    my $rpid=shift;\n    my $pid=shift;\n\
    my $ppid=shift;\n    my $type=shift;\n    my $\
com=shift;\n\n    $ERROR_DONE=1;\n    lock4tc ($rp\
id, \"LERROR\",\"LSET\",\"$pid -- ERROR: $type\\n\\
");\n    lock4tc ($$, \"LERROR\",\"LSET\", \"$pid \
-- COM: $com\\n\");\n    lock4tc ($$, \"LERROR\",\\
"LSET\", \"$pid -- STACK: $ppid -> $pid\\n\");\n\n\
    return $code;\n  }\nsub add_warning\n  {\n    \
my $rpid=shift;\n    my $pid =shift;\n    my $comm\
and=shift;\n    my $msg=\"$$ -- WARNING: $command\\
\n\";\n    print STDERR \"$msg\";\n    lock4tc ($$\
, \"LWARNING\", \"LSET\", $msg);\n  }\n\nsub signa\
l_cleanup\n  {\n    print dtderr \"\\n**** $$ (tcg\
) was killed\\n\";\n    &cleanup;\n    exit ($EXIT\
_FAILURE);\n  }\nsub clean_dir\n  {\n    my $dir=@\
_[0];\n    if ( !-d $dir){return ;}\n    elsif (!(\
$dir=~/tmp/)){return ;}#safety check 1\n    elsif \
(($dir=~/\\*/)){return ;}#safety check 2\n    else\
\n      {\n	`rm -rf $dir`;\n      }\n    return;\n\
  }\nsub cleanup\n  {\n    #print stderr \"\\n----\
tc: $$ Kills $PIDCHILD\\n\";\n    #kill (SIGTERM,$\
PIDCHILD);\n    my $p=getppid();\n    $CLEAN_EXIT_\
STARTED=1;\n\n\n\n    if (&lock4tc($$,\"LERROR\", \
\"LCHECK\", \"\"))\n      {\n	my $ppid=getppid();\\
n	if (!$ERROR_DONE)\n	  {\n	    &lock4tc($$,\"LERR\
OR\", \"LSET\", \"$$ -- STACK: $p -> $$\\n\");\n	 \
   &lock4tc($$,\"LERROR\", \"LSET\", \"$$ -- COM: \
$CL\\n\");\n	  }\n      }\n    my $warning=&lock4t\
c($$, \"LWARNING\", \"LREAD\", \"\");\n    my $err\
or=&lock4tc($$,  \"LERROR\", \"LREAD\", \"\");\n  \
  #release error and warning lock if root\n\n    i\
f (isrootpid() && ($warning || $error) )\n      {\\
n\n	print STDERR \"**************** Summary ******\
*******\\n$error\\n$warning\\n\";\n\n	&lock4tc($$,\
\"LERROR\",\"RELEASE\",\"\");\n	&lock4tc($$,\"LWAR\
NING\",\"RELEASE\",\"\");\n      }\n\n\n    foreac\
h my $f (@TMPFILE_LIST)\n      {\n	if (-e $f){unli\
nk ($f);}\n      }\n    foreach my $d (@TMPDIR_LIS\
T)\n      {\n	clean_dir ($d);\n      }\n    #No Mo\
re Lock Release\n    #&lock4tc($$,\"LLOCK\",\"LREL\
EASE\",\"\"); #release lock\n\n    if ( $debug_loc\
k ){print STDERR \"\\n\\n\\n********** END PG: $PR\
OGRAM ($$) *************\\n\";}\n    if ( $debug_l\
ock ){print STDERR \"\\n\\n\\n**********(tcg) LOCK\
DIR: $LOCKDIR $$ *************\\n\";}\n  }\nEND\n \
 {\n\n    &cleanup();\n  }\n\nsub blast_com2new_bl\
ast_com\n    {\n      my $com=shift;\n	  if ($com=\
~/formatdb/)\n	    {\n	      $com=~s/formatdb/make\
blastdb/;\n	      $com=~s/\\-i/\\-in/;\n	      if \
($com =~/pF/){$com=~s/\\-pF/\\-dbtype nucl/;}\n	  \
    if ($com =~/p F/){$com=~s/\\-p F/\\-dbtype nuc\
l/;}\n	      $com=\"$com -logfile /dev/null\";\n	 \
     return $com;\n	    }\n	  else {return $com;}\\
n\n    }\nsub safe_system\n{\n  my $com=shift;\n  \
my $ntry=shift;\n  my $ctry=shift;\n  my $pid;\n  \
my $status;\n  my $ppid=getppid();\n  if ($com eq \
\"\"){return 1;}\n\n  if ( ($com=~/^blast/) ||($co\
m=~/^formatdb/)){$com=&blast_com2new_blast_com($co\
m);}\n\n  if (($pid = fork ()) < 0){return (-1);}\\
n  if ($pid == 0)\n    {\n      set_lock($$, \" -S\
HELL- $com (tcg)\");\n      if( $debug_generic_met\
hod ) { printf \"~ exec: %s\\n\", $com; }\n      e\
xec ($com);\n      if( $debug_generic_method ) { p\
rintf \"~ exitcode: %s\\n\", $?; }\n    }\n  else\\
n    {\n      lock4tc ($$, \"LLOCK\", \"LSET\", \"\
$pid\\n\");#update parent\n      $PIDCHILD=$pid;\n\
    }\n  if ($debug_lock){printf STDERR \"\\n\\t .\
... safe_system (fasta_seq2hmm)  p: $$ c: $pid COM\
: $com\\n\";}\n\n  waitpid ($pid,WTERMSIG);\n\n  s\
hift_lock ($pid,$$, \"LWARNING\",\"LWARNING\", \"L\
SET\");\n\n  if ($? == $EXIT_FAILURE || lock4tc($p\
id, \"LERROR\", \"LCHECK\", \"\"))\n    {\n      i\
f ($ntry && $ctry <$ntry)\n	{\n\n	  add_warning ($\
$,$$,\"$com failed [retry: $ctry out of $ntry]\");\
\n	  lock4tc ($pid, \"LRELEASE\", \"LERROR\", \"\"\
);\n	  #if ($com=~/EBI/){$com=~s/EBI/NCBI/;}\n	  #\
elsif ($com=~/NCBI/){$com=~s/NCBI/EBI/;}\n\n	  ret\
urn safe_system ($com, $ntry, ++$ctry);\n	}\n     \
 elsif ($ntry == -1)\n	{\n	  if (!shift_lock ($pid\
, $$, \"LERROR\", \"LWARNING\", \"LSET\"))\n	    {\
\n	      add_warning ($$,$$,\"$com failed\");\n	  \
  }\n	  else\n	    {\n	      lock4tc ($pid, \"LREL\
EASE\", \"LERROR\", \"\");\n	    }\n	  return $?;}\
\n      else\n	{\n	  if (!shift_lock ($pid,$$, \"L\
ERROR\",\"LERROR\", \"LSET\"))\n	    {\n	      mye\
xit(add_error ($EXIT_FAILURE,$$,$pid,getppid(), \"\
UNSPECIFIED system\", $com));\n	    }\n	}\n    }\n\
  return $?;\n}\n\nsub check_configuration\n    {\\
n      my @l=@_;\n      my $v;\n      foreach my $\
p (@l)\n	{\n\n	  if   ( $p eq \"EMAIL\")\n	    {\n\
	      if ( !($EMAIL=~/@/))\n		{\n		add_warning($$\
,$$,\"Could Not Use EMAIL\");\n		myexit(add_error \
($EXIT_FAILURE,$$,$$,getppid(),\"EMAIL\",\"$CL\"))\
;\n	      }\n	    }\n	  elsif( $p eq \"INTERNET\")\
\n	    {\n	      if ( !&check_internet_connection(\
))\n		{\n		  myexit(add_error ($EXIT_FAILURE,$$,$$\
,getppid(),\"INTERNET\",\"$CL\"));\n		}\n	    }\n	\
  elsif( $p eq \"wget\")\n	    {\n	      if (!&pg_\
is_installed (\"wget\") && !&pg_is_installed (\"cu\
rl\"))\n		{\n		  myexit(add_error ($EXIT_FAILURE,$\
$,$$,getppid(),\"PG_NOT_INSTALLED:wget\",\"$CL\"))\
;\n		}\n	    }\n	  elsif( !(&pg_is_installed ($p))\
)\n	    {\n	      myexit(add_error ($EXIT_FAILURE,\
$$,$$,getppid(),\"PG_NOT_INSTALLED:$p\",\"$CL\"));\
\n	    }\n	}\n      return 1;\n    }\nsub nw\n    \
  {\n	my($A,$B)=@_;\n	my ($i,$j, $s);\n	my $gep=-2\
;\n	my $match=+2;\n	my $mismatch=0;\n	my ($sub, $i\
ns, $del);\n\n\n	if ($A eq $B){return ($A,$B);}\n	\
\n	$A=~s/[\\s\\d]//g;	\n	$B=~s/[\\s\\d]//g;	\n\n\n\
	my @rA=split ('',$A);\n	my @rB=split ('',$B);\n	\\
n	#evaluate substitutions\n	my $lenA=@rA;\n	my $le\
nB=@rB;\n	\n	for ($i=0; $i<=$lenA; $i++){$smat[$i]\
[0]=$i*$gep;$tb[$i][0 ]= 1;}\n	for ($j=0; $j<=$len\
B; $j++){$smat[0][$j]=$j*$gep;$tb[0 ][$j]=-1;}\n	\\
n	for ($i=1; $i<=$lenA; $i++)\n	  {\n	    for ($j=\
1; $j<=$lenB; $j++)\n	      {\n		if ($rA[$i-1] eq \
$rB[$j-1]){$s=$match;}\n		else {$s=$mismatch;}\n		\
\n		$sub=$smat[$i-1][$j-1]+$s;\n		$del=$smat[$i  ]\
[$j-1]+$gep;\n		$ins=$smat[$i-1][$j  ]+$gep;\n		\n\
		if   ($sub>=$del && $sub>=$ins){$smat[$i][$j]=$s\
ub;$tb[$i][$j]=0;}\n		elsif($del>$ins){$smat[$i][$\
j]=$del;$tb[$i][$j]=-1;}\n		else {$smat[$i][$j]=$i\
ns;$tb[$i][$j]=1;}\n		}\n	  }\n	#print \"\\n---- S\
CORE=$smat[$lenA][$lenB]\\n\";\n	\n	$i=$lenA;\n	$j\
=$lenB;\n	my $aln_len=0;\n\n	while (!($i==0 && $j=\
=0))\n	  {\n	    if ($tb[$i][$j]==0)\n	    {\n	   \
   $aA[$aln_len]=$rA[--$i];\n	      $aB[$aln_len]=\
$rB[--$j];\n	    }\n	  elsif ($tb[$i][$j]==-1)\n	 \
   {\n	      $aA[$aln_len]='-';\n	      $aB[$aln_l\
en]=$rB[--$j];\n	    }\n	  elsif ($tb[$i][$j]==1)\\
n	    {\n	      $aA[$aln_len]=$rA[--$i];\n	      $\
aB[$aln_len]='-';\n	    }\n	  $aln_len++;\n	  }\n	\
\n	\n	@aA=reverse (@aA);\n	@aB=reverse (@aB);\n	my\
 $sA=join('',@aA);\n	my $sB=join('',@aB);\n	return\
 ($sA,$sB);\n      }\n      \nsub fasta2nseq\n	{\n\
	  \n	  my $f=@_[0];\n	  my $nseq;\n\n	  open (F, \
\"$f\") or return 0;\n	  while (<F>)\n	    {\n	   \
   if ($_=~/\\>/){$nseq++;}\n	    }\n	  close (F);\
\n	  return $nseq;\n	}\n	\n$program=\"T-COFFEE (Ve\
rsion_12.00.7fb08c2)\";\\n\n","use Env;\nuse FileH\
andle;\nuse Cwd;\nuse File::Path;\nuse Sys::Hostna\
me;\nmy $f = new FileHandle;\n\nopen ($f, $ARGV[1]\
);\n$atom=$ARGV[0];\n\n$atom=~s/PRIME/\\'/;\nwhile\
 (<$f>)\n  {\n    my $l=$_;\n\n    $l=~s/$atom/CA \
/;\n    \n    \n    $l=~s/  G /GLY /g;\n    $l=~s/\
  C /CYS /g;\n    $l=~s/  T /THR /g;\n    $l=~s/  \
A /ALA /g;\n    $l=~s/  U /THR /g;\n    \n    $l=~\
s/ DG /GLY /g;\n    $l=~s/ DC /CYS /g;\n    $l=~s/\
 DT /THR /g;\n    $l=~s/ DA /ALA /g;\n    $l=~s/ D\
U /THR /g;\n    \n    print $l;\n  }\n\n\n\n","*TC\
_METHOD_FORMAT_01\n******************generic_metho\
d.tc_method*************\n*\n*       Incorporating\
 new methods in T-Coffee\n*       Cedric Notredame\
 26/08/08\n*\n************************************\
*******************\n*This file is a method file\n\
*Copy it and adapt it to your need so that the met\
hod \n*you want to use can be incorporated within \
T-Coffee\n****************************************\
***************\n*                  USAGE         \
                     *\n**************************\
*****************************\n*This file is passe\
d to t_coffee via -in:\n*\n*	t_coffee -in Mgeneric\
_method.method\n*\n*	The method is passed to the s\
hell using the following\n*call:\n*<EXECUTABLE><PA\
RAM1><IN_FLAG><seq_file><PARAM2><OUT_FLAG><outname\
><PARAM>\n*\n*Conventions:\n*<FLAG_NAME> 	<TYPE>		\
<VALUE>\n*<VALUE>:	no_name 	<=> Replaced with a sp\
ace\n*<VALUE>:	&nbsp	<=> Replaced with a space\n*\\
n*************************************************\
******\n*                  ALN_MODE               \
            *\n***********************************\
********************\n*pairwise   ->all Vs all (no\
 self )[(n2-n)/2aln]\n*m_pairwise ->all Vs all (no\
 self)[n^2-n]^2\n*s_pairwise ->all Vs all (self): \
[n^2-n]/2 + n\n*multiple   ->All the sequences in \
one go\n*\nALN_MODE		pairwise\n*\n****************\
***************************************\n*        \
          OUT_MODE                           *\n**\
**************************************************\
***\n* mode for the output:\n*External methods: \n\
* aln -> alignmnent File (Fasta or ClustalW Format\
)\n* lib-> Lib file (TC_LIB_FORMAT_01)\n*Internal \
Methods:\n* fL -> Internal Function returning a Li\
st (Librairie)\n* fA -> Internal Function returnin\
g an Alignmnent\n*\nOUT_MODE		aln\n***************\
****************************************\n*       \
           SEQ_TYPE                           *\n*\
**************************************************\
****\n*G: Genomic, S: Sequence, P: PDB, R: Profile\
\n*Examples:\n*SEQTYPE	S	sequences against sequenc\
es (default)\n*SEQTYPE	S_P	sequence against struct\
ure\n*SEQTYPE	P_P	structure against structure\n*SE\
QTYPE	PS	mix of sequences and structure	\n*\nSEQ_T\
YPE	S\n*\n\n**************************************\
*****************\n*                COMMAND LINE  \
                       *\n*EXECUTABLE PARAM1 IN_FL\
AG OUT_FLAG PARAM             *\n*****************\
**************************************\n**********\
*********************************************\n*  \
                EXECUTABLE                        \
 *\n**********************************************\
*********\n*name of the executable\n*passed to the\
 shell: executable\n*	\nEXECUTABLE	tc_generic_meth\
od.pl\n*\n****************************************\
***************\n*                  IN_FLAG       \
                      *\n*************************\
******************************\n*IN_FLAG\n*flag in\
dicating the name of the in coming sequences\n*IN_\
FLAG S no_name ->no flag\n*IN_FLAG S &bnsp-in&bnsp\
 -> \" -in \"\n*\nIN_FLAG		-infile=\n*\n**********\
*********************************************\n*  \
                OUT_FLAG                          \
 *\n**********************************************\
*********\n*OUT_FLAG\n*flag indicating the name of\
 the out-coming data\n*same conventions as IN_FLAG\
\n*OUT_FLAG	S no_name ->no flag\n*if you want to r\
edirect, pass the parameters via PARAM1\n*set OUT_\
FLAG to >\n*\nOUT_FLAG		-outfile=\n*\n************\
*******************************************\n*    \
              PARAM_1                             \
 *\n**********************************************\
*********\n*<EXECUTABLE><PARAM1><IN_FLAG><seq_file\
><PARAM2><OUT_FLAG><outname><PARAM>\n*Parameters s\
ent to the EXECUTABLE and specified *before* IN_FL\
AG \n*If there is more than 1 PARAM line, the line\
s are\n*concatenated\n*Command_line: @EP@PARAM@-ga\
popen%e10%s-gapext%e20\n*	%s white space\n*	%e equ\
al sign\n*\n*PARAM1	\n*\n*\n*\n*******************\
************************************\n*           \
       PARAM_2                              *\n***\
**************************************************\
**\n*<EXECUTABLE><PARAM1><IN_FLAG><seq_file><PARAM\
2><OUT_FLAG><outname><PARAM>\n*Parameters sent to \
the EXECUTABLE and specified \n*after* IN_FLAG and\
 *before* OUT_FLAG\n*If there is more than 1 PARAM\
 line, the lines are\n*concatenated\n*\n*PARAM1	\n\
*\n*\n********************************************\
***********\n*                  PARAM             \
                 *\n******************************\
*************************\n*<EXECUTABLE><PARAM1><I\
N_FLAG><seq_file><PARAM2><OUT_FLAG><outname><PARAM\
>\n*Parameters sent to the EXECUTABLE and specifie\
d *after* OUT_FLAG\n*If there is more than 1 PARAM\
 line, the lines are\n*concatenated\n*\nPARAM	-mod\
e=seq_msa -method=clustalw\nPARAM   -OUTORDER=INPU\
T -NEWTREE=core -align -gapopen=-15\n*\n**********\
*********************************************\n*  \
                END                               \
 *\n**********************************************\
*********\n","*TC_METHOD_FORMAT_01\n**************\
*clustalw_method.tc_method*********\nEXECUTABLE	cl\
ustalw\nALN_MODE		pairwise\nIN_FLAG		-INFILE=\nOUT\
_FLAG		-OUTFILE=\nOUT_MODE		aln\nPARAM		-gapopen=-\
10\nSEQ_TYPE		S\n*********************************\
****************\n","$VersionTag =                \
                                                  \
                                                  \
               2.43;\nuse Env;\nuse FileHandle;\nu\
se Cwd;\nuse File::Path;\nuse Sys::Hostname;\n\nou\
r $PIDCHILD;\nour $ERROR_DONE;\nour @TMPFILE_LIST;\
\nour $EXIT_FAILURE=1;\nour $EXIT_SUCCESS=0;\n\nou\
r $REFDIR=getcwd;\nour $EXIT_SUCCESS=0;\nour $EXIT\
_FAILURE=1;\n\nour $PROGRAM=\"extract_from_pdb\";\\
nour $CL=$PROGRAM;\n\nour $CLEAN_EXIT_STARTED;\nou\
r $debug_lock=$ENV{\"DEBUG_LOCK\"};\nour $LOCKDIR=\
$ENV{\"LOCKDIR_4_TCOFFEE\"};\nif (!$LOCKDIR){$LOCK\
DIR=getcwd();}\nour $ERRORDIR=$ENV{\"ERRORDIR_4_TC\
OFFEE\"};\nour $ERRORFILE=$ENV{\"ERRORFILE_4_TCOFF\
EE\"};\n&set_lock ($$);\nif (isshellpid(getppid())\
){lock4tc(getppid(), \"LLOCK\", \"LSET\", \"$$\\n\\
");}\n      \nour $SILENT=\" >/dev/null 2>/dev/nul\
l\";\nour $INTERNET=-1;\n\n\n\n\n\n\n\nour $BLAST_\
MAX_NRUNS=2;\nour $EXIT_SUCCESS=0;\nour $EXIT_FAIL\
URE=1;\nour $CONFIGURATION=-1;\nour $REF_EMAIL=\"\\
";\nour $PROGRAM=\"extract_from_pdb\";\n\n\nmy %on\
elett_prot=&fill_onelett_prot();\nmy %threelett_pr\
ot=&fill_threelett_prot();\nmy %onelett_RNA=&fill_\
onelett_RNA();\nmy %threelett_RNA=&fill_threelett_\
RNA();\nmy %onelett_DNA=&fill_onelett_DNA();\nmy %\
threelett_DNA=&fill_threelett_DNA();\n\n\n\n\n\nmy\
 %onelett = (\n'P' => \\%onelett_prot,\n'D' => \\%\
onelett_DNA,\n'R' => \\%onelett_RNA\n);\n\n\nmy %t\
hreelett = (\n'P' => \\%threelett_prot,\n'D' => \\\
%threelett_DNA,\n'R' => \\%threelett_RNA\n);\n\n\n\
\n\n\n\n\nif($ARGV[0]=~/help/ ||$ARGV[0]=~/man/ ||\
 $ARGV[0]=~/HELP/ || $ARGV[0]=~/Man/ || $ARGV[0] e\
q \"-h\"  || $ARGV[0] eq \"-H\"  )\n{die \"SYNTAX:\
 extract_from_pdb Version $VersionTag	\n	Minimum: \
            [extract_from_pdb file] \n			   OR \n	\
		     [... | extract_from_pdb]\n 	Flags (Default \
setting on the first line)\n	   -version..........\
.........[Returns the Version Number]\n           \
-force.....................[Forces the file to be \
treated like a PDB file]\n                        \
              [Regenerates the header and SEQRES f\
ields]\n           -force_name................[For\
ces the file to be named after name]]\n           \
-infile.....file...........[Flag can be omited]\n	\
		              [File must be pdb or fro pgm]\n   \
                                   [File can also \
be compressed Z or gz]\n                          \
            [In the case of a compressed file, you\
 can omit the gz|Z extension]\n           -netfile\
...................[File will be fetch from the ne\
t using wget]\n                                   \
   [wget or curl must be installed]\n             \
                         [ftp://ftp.gnu.org/pub/gn\
u/wget/]\n                                      [h\
ttp://curl.haxx.se/]\n                            \
          [Must also be used to retrieve the file \
from a local pdb copy (cf netaddress)]\n          \
 -netaddress................[Address used for the \
retrieving the netfile]\n                         \
             [http://www.rcsb.org/pdb/cgi/export.c\
gi/%%.pdb.gz?format=PDB&pdbId=%%&compression=gz]\n\
                                      [http://www.\
expasy.ch/cgi-bin/get-pdb-entry.pl?%%]\n          \
                            [local -> will get the\
 file from pdb_dir (see pdb_dir)]\n           -net\
compression............[Extension if the netfile c\
omes compressed]\n                                \
      [gz]\n           -pdb_dir...................\
[address of the repertory where the pdb is install\
ed]\n                                      [Suppor\
ts standard ftp style installation OR every stru i\
n DIR]\n                                      [Giv\
e the ..../pdb/structure/ dir]\n                  \
                    [If value omitted, the pg gets\
 it from the env variable PDB_DIR]\n           -ne\
tcompression_pg.........[gunzip]\n           -is_p\
db_name..........name.[Returns 1 if the name is a \
PDB ID, 0 otherwise]\n           -model_type......\
.....name.[Returns the model type if valid PDB nam\
e]\n           -is_released_pdb_name name.[Returns\
 1 if the name corresponds to a released PDB file]\
\n           -get_pdb_chains.....name...[Returns t\
he list of chains corresponding to the entry]\n   \
        -get_pdb_id.........name...[Returns the PD\
B id within the provided pdb file]\n           -ge\
t_fugue_name.....name...[Turns a name into a name \
valid for fugue]\n                                \
      [Uses the netaddress to do so]\n	   -chain..\
....FIRST..........[Extract the first chain only]\\
n		       A B C..........[Extract Several chains i\
f needed]\n		       ALL............[Extract all th\
e chains]	\n           -ligand.....ALL............\
[Extract the ligands in the chain (HETATM)]\n     \
                  <name1>,<name2>[Extract All the \
named lignds]\n	   -ligand_only...............[Ext\
ract only the ligands]\n           -ligand_list...\
............[Extract the list of ligands]\n	   -co\
or.......<start>..<end>.[Coordinates of the fragme\
nt to extract]\n			              [Omit end to incl\
ude the Cter]\n           -num........absolute....\
...[absolute: relative to the seq] \n             \
          file...........[file: relative to file]\\
n           -num_out....new............[new: start\
 1->L]\n                       old............[old\
: keep the file coordinates]\n           -delete..\
...<start>..<end>.[Delete from residue start to re\
sidue end]\n	   -atom.......CA.............[Atoms \
to include, ALL for all of them]\n		       CA O N.\
........[Indicate several atoms if needed]\n	   -c\
ode.......3..............[Use the 1 letter code or\
 the 3 letters code]\n	   -mode.......raw.........\
...[Output original pdb file]\n                   \
    pdb............[Output something that looks li\
ke pdb]\n		       fasta..........[Output the seque\
nces in fasta format]\n		       simple.........[Ou\
tput a format easy to parse in C ]\n            -s\
eq_field..ATOM...........[Field used to extract th\
e sequence]\n		       SEQRES.........[Use the comp\
lete sequence]\n	   -seq.......................[Eq\
uivalent to  -mode fasta]\n	   -model......1......\
........[Chosen Model in an NMR file]\n           \
-nodiagnostic..............[Switches Error Message\
s off]\n           -debug.....................[Set\
s the DEBUG ON]\n           -no_remote_pdb_dir....\
.....[Do not look for a remote file]\n           -\
cache_pdb.................[Cache Value, default is\
 $HOME/.t_coffee/cache, other values: NO<=> No cac\
he]\n\n      Environement Variables\n           Th\
ese variables can be set from the environement\n  \
         Command line values with the correspondin\
g flag superseed evironement value\n           NO_\
REMOTE_PDB_DIR..........[Prevents the program from\
 searching remote file: faster]\n           PDB_DI\
R....................[Indicates where PDB file mus\
t be fetched (localy)]\n\n	 PROBLEMS: please conta\
ct cedric.notredame\\@europe.com\\n\";\n	 exit ($E\
XIT_SUCCESS);\n}\n\n$np=0;\n$n_para=$#ARGV;\n$mode\
l=1;\n$pdb_dir=$ENV{'PDB_DIR'};if ($pdb_dir){$pdb_\
dir.=\"/\";}\n$debug=$ENV{'DEBUG_EXTRACT_FROM_PDB'\
};\n\n$no_remote_pdb_dir=$ENV{NO_REMOTE_PDB_DIR};\\
n$HOME=$ENV{'HOME'};\nif ( $ENV{CACHE_4_TCOFFEE})\\
n{$cache=$ENV{CACHE_4_TCOFFEE};}\nelse\n{\n    $ca\
che=\"$HOME/.t_coffee/cache/\";\n}\n\n   \n$netadd\
ress=\"http://www.rcsb.org/pdb/files/%%.pdb.gz\";\\
n$netcompression_pg=\"gunzip\";\n$netcompression=\\
"gz\";\n\nforeach ($np=0; $np<=$n_para; $np++)\n  \
{        \n    $value=$ARGV[$np];\n   \n    if  ($\
np==0 && !($value=~/^-.*/))\n      { \n	$pdb_file=\
 $ARGV[$np];\n      }\n    elsif ( !($value=~/^-.*\
/))\n      {\n	print \"@ARGV\";\n	die;\n      } \n\
    \n    elsif ($value eq \"-nodiagnostic\"){$nod\
iagnostic=1;}\n    elsif ($value eq \"-force\")\n \
     {\n	$force_pdb=1;\n      }\n    elsif ($value\
 eq \"-force_name\")\n      {\n	$force_name=$ARGV[\
++$np];\n	$force_pdb=1;\n      }\n    \n    elsif \
($value eq \"-is_pdb_name\")\n      {\n	$pdb_file=\
 $ARGV[++$np];	\n	$is_pdb_name=1;	\n      } \n    \
elsif ($value eq \"-is_released_pdb_name\")\n     \
 {\n	$pdb_file= $ARGV[++$np];	\n	$is_released_pdb_\
name=1;\n      }\n    elsif ($value eq \"-model_ty\
pe\")\n      {\n	$pdb_file= $ARGV[++$np];	\n	$mode\
l_type=1;\n      }\n    elsif ($value eq \"-debug\\
")\n{\n	$debug=1;\n}\n    elsif ($value eq \"-get_\
pdb_chains\")\n{\n	$pdb_file= $ARGV[++$np];\n	$get\
_pdb_chains=1;\n}\n    elsif ($value eq \"-get_pdb\
_ligands\")\n{\n	$get_pdb_ligands=1;\n}\n    \n   \
 elsif ($value eq \"-get_pdb_id\")\n{\n	$pdb_file=\
 $ARGV[++$np];\n	$get_pdb_id=1;\n	\n}\n    \n    e\
lsif ( $value eq \"-get_fugue_name\")\n{\n	$pdb_fi\
le= $ARGV[++$np];\n	$get_fugue_name=1;\n}\n    els\
if ( $value eq \"-infile\")\n{\n       $pdb_file= \
$ARGV[++$np];\n} \n    elsif ($value eq \"-netfile\
\")\n{\n	$netfile=1;\n	if ( !($ARGV[$np+1]=~/^-.*/\
)){$pdb_file= $ARGV[++$np];}\n}\n    elsif (  $val\
ue eq \"-num\")\n{\n       $numbering= $ARGV[++$np\
];\n}\n    elsif (  $value eq \"-num_out\")\n{\n  \
     $numbering_out= $ARGV[++$np];\n}\n    elsif (\
 $value eq \"-netaddress\")\n{\n	$netadress=$ARGV[\
++$np];\n}\n     \n    elsif ( $value eq \"-netcom\
pression\")\n{\n	 $netcompression=$ARGV[++$np];\n}\
\n    elsif ( $value eq \"-pdb_dir\")\n{\n	 if ( !\
($ARGV[$np+1]=~/^-.*/)){$pdb_dir= \"$ARGV[++$np]/\\
";}\n}\n     elsif ( $value eq \"-no_remote_pdb_di\
r\")\n{\n	$no_remote_pdb_dir=1;\n	if ( !($ARGV[$np\
+1]=~/^-.*/)){$pdb_dir= \"$ARGV[++$np]/\";}\n}\n  \
  elsif ( $value eq \"-cache\")\n{\n	$cache=$ARGV[\
++$np];\n}\n    \n    elsif ($value eq \"-netcompr\
ession_pg\")\n{\n	  $netcompression_pg=$ARGV[++$np\
];\n}\n     elsif ($value eq \"-mode\")\n{\n      \
 $MODE=$ARGV[++$np];\n}\n\n    elsif ( $value eq \\
"-model\")\n{\n       $model= $ARGV[++$np];\n}\n  \
  elsif ($value eq \"-seq_field\" )\n{\n       $se\
q_field= $ARGV[++$np];\n}   \n    elsif ($value eq\
 \"-coor\" )\n{\n       $start= $ARGV[++$np];\n  \\
n       if (($ARGV[$np+1] eq \"\") ||($ARGV[$np+1]\
=~/^-.*/)){$end=\"*\";} \n       else {$end=   $AR\
GV[++$np];}     \n       $coor_set=1;\n}\n    elsi\
f ($value eq \"-delete\" )\n{\n       $delete_star\
t= $ARGV[++$np];\n       $delete_end= $ARGV[++$np]\
;\n       $delete_set=1;\n}\n    elsif  ($value eq\
 \"-code\")\n{\n       $code= $ARGV[++$np];\n}\n  \
  elsif  ($value eq \"-no_hetatm\")\n{\n       $no\
_hetatm=1;\n}\n    elsif ($value eq \"-chain\")\n{\
\n       while (!($ARGV[$np+1] eq \"\") &&!($ARGV[\
$np+1]=~/^-.*/))\n{\n	      ++$np;\n	      @c_chai\
n=(@chain,  $ARGV[$np]);\n	      $hc_chain{$ARGV[$\
np]}=$#c_chain+1;\n}           \n}\n    elsif ($va\
lue eq \"-atom\")\n{\n\n       while (!($ARGV[$np+\
1] eq \"\") && !($ARGV[$np+1]=~/^-.*/))\n{\n	     \
 ++$np;\n	      $atom[$n_atom++]=  $ARGV[$np];\n	 \
     $atom_list{$ARGV[$np]}=1;	      \n} \n       \
\n}\n    elsif ( $value eq \"-unfold\")\n{\n	$unfo\
ld=1;\n}\n    elsif ($value eq \"-seq\" ||$value e\
q \"-fasta\" )\n{\n       $MODE=\"fasta\";\n}\n   \
 elsif ( $value eq \"-version\")\n{\n	print STDERR\
  \"\\nextract_from_pdb: Version $VersionTag\\n\";\
\n	&myexit ($EXIT_SUCCESS);\n}\n    elsif ( $value\
 eq \"-ligand\")\n{\n	while (!($ARGV[$np+1] eq \"\\
") && !($ARGV[$np+1]=~/^-.*/))\n{\n	    ++$np;\n	 \
   $ligand=1;\n	    $ligand_list{$ARGV[$np]}=1;	  \
    \n} \n	$hc_chain{'LIGAND'}=1;\n}\n    elsif ( \
$value eq \"-ligand_only\")\n{\n	$ligand_only=1;\n\
}\n}\nif ( $debug)\n{\n    print STDERR \"\\n[DEBU\
G:extract_from_pdb] NO_REMOTE_PDB_DIR: $no_remote_\
pdb_dir\\n\";\n    print STDERR \"\\n[DEBUG:extrac\
t_from_pdb] PDB_DIR: $pdb_dir\\n\";\n}\n\n\nif ( $\
is_pdb_name)\n  {\n    if (&remote_is_pdb_name($pd\
b_file))\n      {\n	print \"1\";\n      }\n    els\
e\n      {\n	print \"0\";\n      }\n    exit ($EXI\
T_SUCCESS);\n  }\n\nif ( $is_released_pdb_name)\n \
 {\n    \n    if (&is_released($pdb_file))\n      \
{\n	print \"1\";\n      }\n    else\n      {\n	pri\
nt \"0\";\n      }\n    exit ($EXIT_SUCCESS);\n  }\
\nif ($model_type)\n  {\n   \n    printf \"%s\", &\
pdb2model_type($pdb_file);\n    exit ($EXIT_SUCCES\
S);\n    \n  }\n    \n\nif (!$force_name)\n{\n    \
$pdb_file=~/([^\\/]*)$/;\n    $force_name=$1;\n}\n\
\n$local_pdb_file=$pdb_file;\n\nif ( $debug){print\
 STDERR \"\\n[DEBUG: extract_from_pdb] Scan For $l\
ocal_pdb_file\\n\";}\n\n$mem=$no_remote_pdb_dir;\n\
$no_remote_pdb_dir=1;\n$tmp_pdb_file=get_pdb_file \
($local_pdb_file);\n\nif ( !-e $tmp_pdb_file || $t\
mp_pdb_file eq \"\")\n  {\n    $local_pdb_file=$pd\
b_file;\n    ($local_pdb_file, $suffix_chain)=&pdb\
_name2name_and_chain($local_pdb_file);\n\n    if (\
$local_pdb_file)\n      {\n	if ( $debug){print STD\
ERR \"\\nSplit $pdb_file into $local_pdb_file and \
$suffix_chain \\n\";}\n	$tmp_pdb_file=get_pdb_file\
 ($local_pdb_file);\n	if ( $tmp_pdb_file ne \"\")\\
n	  {\n	    @c_chain=();\n	    @c_chain=($suffix_c\
hain);\n	    %hc_chain=();\n	    $hc_chain{$suffix\
_chain}=1;\n	  }\n      }\n  }\n\n$no_remote_pdb_d\
ir=$mem;\nif ($no_remote_pdb_dir==0)\n  {\n    \n \
   if ( !-e $tmp_pdb_file || $tmp_pdb_file eq \"\"\
)\n      {\n	\n	$local_pdb_file=$pdb_file;\n	($loc\
al_pdb_file, $suffix_chain)=&pdb_name2name_and_cha\
in($local_pdb_file);\n	if ($local_pdb_file)\n	  {\\
n	    \n	    if ( $debug){print STDERR \"\\nSplit \
$pdb_file into $local_pdb_file and $suffix_chain \\
\n\";}\n	    \n	    $tmp_pdb_file=get_pdb_file ($l\
ocal_pdb_file);    \n	    \n	    if ( $tmp_pdb_fil\
e ne \"\")\n	      {\n		@c_chain=();\n		@c_chain=(\
$suffix_chain);\n		%hc_chain=();\n		$hc_chain{$suf\
fix_chain}=1;\n	      }\n	  }\n      }\n  }\n\nif \
( $debug){print STDERR \"\\n$pdb_file copied into \
##$tmp_pdb_file##\\n\";}\n\nif ( !-e $tmp_pdb_file\
 || $tmp_pdb_file eq \"\")\n{\n	if ($is_pdb_name)\\
n{\n	    print \"0\\n\"; exit ($EXIT_SUCCESS);\n}\\
n	else\n{\n  \n	    print \"\\nEXTRACT_FROM_PDB: N\
O RESULT for $pdb_file\\n\";\n	    &myexit ($EXIT_\
SUCCESS);	\n}\n}\n\n\n\n\n%molecule_type=&pdbfile2\
chaintype($tmp_pdb_file);\nif ( $debug){print STDE\
RR \"\\n\\tSequence Type determined\\n\";}\n\n$pdb\
_id=&get_pdb_id ($tmp_pdb_file);\nif ( $debug){pri\
nt STDERR \"\\n\\tID: $pdb_id (for $tmp_pdb_file)\\
\n\";}\n\nif ( $pdb_id eq \"\"){$pdb_id=$force_nam\
e;}\n\n@f_chain=&get_chain_list ($tmp_pdb_file);\n\
if ( $debug){print STDERR \"\\n\\tChain_list:@f_ch\
ain\\n\";}\n\nif ( $get_pdb_chains)\n{\n    print \
\"@f_chain\\n\";\n    &myexit ($EXIT_SUCCESS);\n}\\
nif ( $get_pdb_ligands)\n{\n    %complete_ligand_l\
ist=&get_ligand_list ($tmp_pdb_file);\n    print $\
complete_ligand_list{\"result\"};\n    &myexit ($E\
XIT_SUCCESS);\n}\n\nelsif ( $get_pdb_id ||$get_fug\
ue_name )\n{\n    if    (@c_chain && $c_chain[0] e\
q \"FIRST\"){$pdb_id=$pdb_id.$f_chain[0];}\n    el\
sif (@c_chain && $c_chain[0] ne \" \"){$pdb_id=$pd\
b_id.$c_chain[0];}\n    \n    print \"$pdb_id\\n\"\
;\n    &myexit ($EXIT_SUCCESS);\n    \n}\nelsif ( \
$is_pdb_name)\n{\n    printf \"1\\n\";\n    &myexi\
t ($EXIT_SUCCESS);\n}\n\n\n\n$structure_file=vtmpn\
am();\n\nif ( $debug){print STDERR \"\\n\\tCheck_p\
oint #1: $tmp_pdb_file  $structure_file\\n\";}\n\n\
$INFILE=vfopen (\"$tmp_pdb_file\", \"r\"); \nmy $T\
MP=vfopen (\"$structure_file\", \"w\");\n\n$print_\
model=1;\n$in_model=0;\n\nif ( $debug){print STDER\
R \"\\n\\tCheck_point #2\\n\";}\nwhile ( <$INFILE>\
)\n{\n  my $first_model=0;\n  $line=$_;\n\n  if ( \
!$first_model && ($line =~/^MODEL\\s*(\\d*)/))\n  \
  {\n      $first_model=$1;\n      if ($model==1){\
$model=$first_model;}\n    }\n  \n  if (($line =~/\
^MODEL\\s*(\\d*)/))\n    {\n      if ($1==$model)\\
n	{\n	  $in_model=1;\n	  $print_model=1;\n	  $is_n\
mr=1;\n	}\n      elsif ( $in_model==0)\n	{\n	  $pr\
int_model=0;\n	}\n      elsif ( $in_model==1)\n	{\\
n	  last;\n	}\n    }\n  if ($print_model){print $T\
MP $line;}  \n}\nclose ($TMP);\nclose ($INFILE);\n\
\nif ( $debug){print STDERR \"\\n\\tCheck_point #3\
\\n\";}	\n\n  if ($numbering eq \"\"){$numbering=\\
"absolute\";}\n  if ($numbering_out eq \"\"){$numb\
ering_out=\"new\";}\n\n  if ( $delete_set && $coor\
_set) {die \"-delete and -coor are mutually exclus\
ive, sorry\\n\";}\n  if ( $n_atom==0){$atom_list[$\
n_atom++]=\"ALL\";$atom_list{$atom_list[0]}=1;}\n \
 if ( $seq_field eq \"\"){$seq_field=\"ATOM\";}\n \
 \n  if ( $MODE eq \"\"){$MODE=\"pdb\";}\n  elsif \
( $MODE eq \"simple\" && $code==0){$code=1;}\n\n  \
if ( $code==0){$code=3;}\n\n\nif ($f_chain[0] eq \\
" \"){$hc_chain{' '}=1;$c_chain[0]=\" \";}\nelsif \
(!@c_chain){$hc_chain{FIRST}=1;$c_chain[0]=\"FIRST\
\";}#make sure the first chain is taken by default\
\n\nif    ($hc_chain{ALL}) \n{\n      @c_chain=@f_\
chain;\n      foreach $e (@c_chain){$hc_chain{$e}=\
1;}\n}\nelsif($hc_chain{FIRST})\n{\n	@c_chain=($f_\
chain[0]);\n	$hc_chain{$f_chain[0]}=1;\n}\n\n\n$MA\
IN_HOM_CODE=&get_main_hom_code ($structure_file);\\
n$INFILE=vfopen ($structure_file, \"r\");\n\n\nif \
( $MODE eq \"raw_pdb\" || $MODE eq \"raw\")\n{\n  \
  while (<$INFILE>)\n{	print \"$_\";}\n    close (\
 $INFILE);\n    &myexit($EXIT_SUCCESS);\n}    \nif\
 ( $MODE eq \"raw4fugue\" )\n{\n    while (<$INFIL\
E>)\n{	\n	$l=$_;\n	if ($l=~/^SEQRES/)\n{\n	    \n	\
    $c= substr($l,11,1);\n	    if ($hc_chain {$c})\
{print \"$l\";}\n}\n	elsif ( $l=~/^ATOM/)\n{\n	   \
 $c=substr($l,21,1);\n	    if ($hc_chain {$c}){pri\
nt \"$l\";}\n}\n}\n    close ( $INFILE);\n    &mye\
xit($EXIT_SUCCESS);\n}    \n\nif ( $MODE eq \"pdb\\
")\n{\n\n    $read_header=0;\n    while (<$INFILE>\
) \n{\n	    $line=$_;\n	    if    ($line =~ /^HEAD\
ER/){print \"$line\";$read_header=1;}\n}\n    clos\
e ($INFILE);\n\n    if (!$read_header)\n{\n	print \
\"HEADER    UNKNOWN                               \
  00-JAN-00   $force_name\\n\";\n}\n\n    $INFILE=\
vfopen ($structure_file, \"r\");\n    \n    print \
\"COMPND   1 CHAIN:\";\n    $last=pop(@c_chain);\n\
    foreach $c ( @c_chain){ print \" $c,\";}\n    \
if ( $last eq \" \"){print \" NULL;\\n\";}\n    el\
se \n{\n      print \" $last;\\n\";\n}\n    @c_cha\
in=(@c_chain, $last);\n    \n    print \"REMARK Ou\
tput of the program extract_from_pdb (Version $Ver\
sionTag)\\n\";\n    print \"REMARK Legal PDB forma\
t not Guaranteed\\n\";\n    print \"REMARK This fo\
rmat is not meant to be used in place of the PDB f\
ormat\\n\";\n    print \"REMARK The header refers \
to the original entry\\n\";\n    print \"REMARK Th\
e sequence from the original file has been taken i\
n the field: $seq_field\\n\";\n    print \"REMARK \
extract_from_pdb, 2001, 2002, 2003, 2004, 2005 200\
6 (c) CNRS and Cedric Notredame\\n\";   \n    if (\
 $coor_set)\n{\n       print \"REMARK Partial chai\
n: Start $start End $end\\n\";\n}\n    if ( $is_nm\
r)\n{\n       print \"REMARK NMR structure: MODEL \
$model\\n\";\n}\n   \n    if ( $n_atom!=0)\n{\n   \
    print \"REMARK Contains Coordinates of: \";\n \
      foreach $a (@atom){print \"$a \";}\n       p\
rint \"\\n\";\n}  \n}\n\n\n\n\nmy $residue_index =\
 -999;\nmy $old_c = \"TemporaryChain\";\n\nwhile (\
<$INFILE>) \n{\n	$line=$_;\n\n\n	if ($line =~ /^SE\
QRES/)\n{\n\n		@field=/(\\S*)\\s*/g;\n\n		$c= subs\
tr($_,11,1);\n\n		\n		$l=$#field;\n		for ($a=4; $a\
<$#field ;)\n{\n			if (!$onelett{$molecule_type{$c\
}}->{$field[$a]})\n{\n				splice @field, $a, 1;\n}\
\n			else \n{\n				$a++;\n}\n}\n	\n		if ( $c ne $i\
n_chain)\n{\n			$pdb_chain_list[$n_pdb_chains]=$c;\
\n			$pdb_chain_len [$n_pdb_chains]=$len;\n			$in_\
chain=$c;\n			$n_pdb_chains++;\n}\n	\n		for ( $a=4\
; $a<$#field;$a++)\n{\n			$complete_seq{$c}[$compl\
ete_seq_len{$c}++]=$field[$a];\n}\n}\n    elsif ( \
$line=~/^ATOM/ || ($line=~/^HETATM/ && &is_aa(subs\
tr($line,17,3),substr($line,21,1)) && !$no_hetatm)\
)\n{\n\n	 \n    $RAW_AT_ID=$AT_ID=substr($line,12,\
4);\n	$RES_ID=&is_aa(substr($line,17,3),substr($li\
ne,21,1));\n	$CHAIN=substr($line,21,1);\n\n    $RE\
S_NO=substr($line,22,4);\n	$HOM_CODE=substr ($line\
, 26, 1);\n	$TEMP=substr($line,60,6);\n	\n	$TEMP=~\
s/\\s//g;\n        $AT_ID=~s/\\s//g;\n	$RES_ID=~s/\
\\s//g;\n        $RES_NO=~s/\\s//g;\n		\n	if ( $HO\
M_CODE ne $MAIN_HOM_CODE){next;}\n	elsif ( $alread\
y_read2{$CHAIN}{$RES_ID}{$AT_ID}{$RES_NO}){next;}\\
n	else{$already_read2{$CHAIN}{$RES_ID}{$AT_ID}{$RE\
S_NO}=1;}\n	\n	\n	if ($coor_set && $numbering eq \\
"file\" && $residue_index ne $RES_NO)\n{\n	    \n	\
    if ( $RES_NO<=$start){$real_start{$CHAIN}++;}\\
n	    if ( $RES_NO<=$end){$real_end{$CHAIN}++;}\n}\
\n	elsif ($numbering eq \"absolute\")\n{\n	    $re\
al_start{$CHAIN}=$start;\n	    $real_end{$CHAIN}=$\
end;\n}\n\n        $KEY=\"ALL\";\n        if ( $CH\
AIN ne $in_atom_chain)\n{\n	    \n	  $pdb_atom_cha\
in_list[$n_pdb_atom_chains]=$c;\n	  $pdb_atom_chai\
n_len [$n_pdb_atom_chains]=$len;\n	  $in_atom_chai\
n=$c;\n	  $n_pdb_atom_chains++;\n}\n	\n	if ( $resi\
due_index ne $RES_NO)\n{\n	     $residue_index = $\
RES_NO;\n	     $atom_seq{$CHAIN}[$atom_seq_len{$CH\
AIN}++]=$RES_ID;;\n}\n}\n\n}\nclose ($INFILE);\n\n\
\n\n\n\n\n$INFILE=vfopen ($structure_file, \"r\");\
\nforeach $c (@c_chain)\n{\n\n	if    ( $seq_field \
eq \"SEQRES\"){@pdb_seq=@{$complete_seq{$c}};}\n	e\
lsif ( $seq_field eq \"ATOM\")  {@pdb_seq=@{$atom_\
seq{$c}};}\n	\n\n	$full_length=$l=$#pdb_seq+1;\n		\
\n	if ( $real_end{$c}==\"*\"){$real_end{$c}=$full_\
length;}\n	if ( $coor_set)\n{	   \n\n	   if ( $rea\
l_end{$c} < $l){splice @pdb_seq, $real_end{$c}, $l\
;}\n	   if ( $real_start{$c} < $l){splice @pdb_seq\
, 0, $real_start{$c}-1;}	  	   \n	   $l=$#pdb_seq;\
\n}\n\n	elsif ( $delete_set)\n{\n	   splice @pdb_s\
eq, $delete_start, $delete_end-$delete_start+1;\n	\
   $l=$#pdb_seq;\n}\n	\n	$new_fasta_name=\"$pdb_id\
$c\";\n	if ( $coor_set)\n{\n	   if ( $n_pdb_chains\
==0){$new_fasta_name=\"$new_fasta_name$c\";}\n	   \
$new_fasta_name= $new_fasta_name.\"\\_$start\\_$en\
d\";\n}\n	   \n	if ( $MODE eq \"pdb\")\n{\n	   $nl\
=1;\n	   $n=0;\n	   \n	   foreach $res ( @pdb_seq)\
\n		{\n		if ( !$n)\n		{\n		\n		 printf \"SEQRES %3\
d %1s %4d  \", $nl,$c, $l;\n		 $nl++;\n	}\n	     $\
res=~s/\\s//g;\n	     \n	     if ($code==1){ print\
f \"%3s \",$onelett{$molecule_type{$c}}->{$res};}\\
n	     elsif  ($code==3){ printf \"%3s \",$res};\n\
	     \n	     $n++;		  \n	     if ( $n==13){$n=0;p\
rint \"\\n\";}\n}\n	  if ( $n!=0){print \"\\n\"; $\
n=0;}\n}\n	elsif ( $MODE eq \"simple\")\n{\n	  pri\
nt \"# SIMPLE_PDB_FORMAT\\n\";\n	  if ( $new_fasta\
_name eq \" \"){$new_fasta_name=\"dummy_name\";}\n\
	  print \">$new_fasta_name\\n\";\n\n	  foreach $r\
es ( @pdb_seq)\n{\n	      print \"$onelett{$molecu\
le_type{$c}}->{$res}\";\n}\n	  print \"\\n\";\n}\n\
	elsif ( $MODE eq \"fasta\")\n{\n	  $n=0;\n	  prin\
t \">$new_fasta_name\\n\";\n	  \n	  foreach $res (\
 @pdb_seq)\n{\n\n	      print \"$onelett{$molecule\
_type{$c}}->{$res}\";\n              $n++;\n	     \
 if ( $n==60){print \"\\n\"; $n=0;}\n}\n	  print \\
"\\n\"; \n}\n}\n\nif ( $MODE eq \"fasta\")\n{\n   \
  &myexit($EXIT_SUCCESS);\n  \n}\n\n  \n  $charcou\
nt=0;\n  $inchain=\"BEGIN\";\n  $n=0;\n  while (<$\
INFILE>) \n{\n    $line=$_;\n     \n    if ($line \
=~/^ATOM/  ||  ($line=~/^HETATM/))\n{\n	$line_head\
er=\"UNKNWN\";\n	$RES_ID=substr($line,17,3);\n	$ch\
ain = substr($line,21,1);\n\n	if ($line =~/^ATOM/)\
\n{\n	    $line_header=\"ATOM\";\n	    $RES_ID=(&i\
s_aa($RES_ID,$chain))?&is_aa($RES_ID,$chain):$RES_\
ID;\n}\n	elsif ($line=~/^HETATM/ && ($ligand_list \
{$RES_ID} ||$ligand_list {'ALL'} || !&is_aa($RES_I\
D,$chain)))\n{\n	    $line_header=\"HETATM\";\n}\n\
	elsif ($line=~/^HETATM/ && (&is_aa($RES_ID,$chain\
) && !$no_hetatm))\n{\n	    $line_header=\"ATOM\";\
\n	    $RES_ID=&is_aa($RES_ID,$chain);\n}\n	else\n\
{\n	    next;\n}\n\n	\n\n	$X=substr($line,30,8);  \
   \n	$Y=substr($line,38,8);\n	$Z=substr($line,46,\
8);\n	$TEMP=substr($line,60,6);\n	\n	$RAW_AT_ID=$A\
T_ID=substr($line,12,4);\n	$CHAIN=substr($line,21,\
1);\n	$RES_NO=substr($line,22,4);\n	$HOM_CODE=subs\
tr ($line, 26, 1);\n	\n	$X=~s/\\s//g;\n	$Y=~s/\\s/\
/g;\n	$Z=~s/\\s//g;\n	$TEMP=~s/\\s//g;\n	\n	$AT_ID\
=~s/\\s//g;\n	$RES_ID=~s/\\s//g;\n	$RES_NO=~s/\\s/\
/g;\n\n	\n	if ( $HOM_CODE ne $MAIN_HOM_CODE){next;\
}\n	elsif ( $already_read{$CHAIN}{$RES_ID}{$AT_ID}\
{$RES_NO}){next;}\n	else{$already_read{$CHAIN}{$RE\
S_ID}{$AT_ID}{$RES_NO}=1;}\n	\n	$KEY=\"ALL\";\n\n \
     	if ( $RES_NO ==0){$start_at_zero=1;}\n\n	$RE\
S_NO+=$start_at_zero;    \n	\n	if ( $current_chain\
 ne $CHAIN)\n{\n	    $current_chain=$CHAIN;\n	    \
$pos=$current_residue=0;\n	    $offset=($coor_set)\
?($real_start{$CHAIN}-1):0;\n	    if    ( $seq_fie\
ld eq \"SEQRES\"){@ref_seq=@{$complete_seq{$CHAIN}\
};}\n	    elsif ( $seq_field eq \"ATOM\")  {@ref_s\
eq=@{$atom_seq{$CHAIN}};}\n}\n	\n	if ($current_res\
idue != $RES_NO)\n{\n	    $current_residue=$RES_NO\
;\n	    if    ( $seq_field eq \"SEQRES\"){$pos=$cu\
rrent_residue;}\n	    elsif ( $seq_field eq \"ATOM\
\"){$pos++;}\n}\n	\n	\n	if ($n_atom==0 || $atom_li\
st{$AT_ID}==1 || $atom_list{$KEY}==1)\n{ 	\n	    \\
n	    $do_it=(!@c_chain || $hc_chain{$CHAIN} ||$hc\
_chain{'LIGAND'} );\n	    \n	    $do_it= ($do_it==\
1) && ($coor_set==0 ||($pos>=$real_start{$CHAIN} &\
& $pos<=$real_end{$CHAIN}));\n	    $do_it= ($do_it\
==1) && ($delete_set==0 || $pos<$delete_start ||$p\
os>$delete_end );\n	    if ($ligand==0 && $line_he\
ader eq \"HETATM\" ){$do_it=0;}\n	    if ($ligand_\
only==1 && $line_header eq \"ATOM\" ){$do_it=0;}\n\
	    if ($ligand==1 && $line_header eq \"HETATM\" \
&& $ligand_list{$RES_ID}==0 && $ligand_list{\"ALL\\
"}==0){$do_it=0;} \n	    \n	    \n	    if ( $do_it\
)\n{\n		$n++;\n		$out_pos=$pos;\n		\n	       if ( \
$delete_set)\n{\n		  if ( $out_pos< $delete_start)\
{;}\n		  else {$offset=$delete_end-$delete_start;}\
\n}       \n	       \n	       if ( $numbering_out \
eq \"new\"){$out_pos-=$offset;}\n	       elsif ( $\
numbering_out eq \"old\"){$out_pos=$RES_NO;}\n	   \
    \n       \n	       \n	       if ( $code==1){$R\
ES_ID=$onelett{$molecule_type{$c}}->{$RES_ID};}\n	\
    \n	       if ($unfold)\n{\n		   $unfolded_x+=5\
;\n		   $X=$unfolded_x;\n		   $Y=0;\n		   $Z=0;\n	\
	   $float=1;\n}\n	       else\n{\n		   $float=3;\\
n}\n\n	       if ( $MODE eq \"pdb\")\n{\n		   prin\
tf \"%-6s%5d %-4s %3s %s%4d    %8.3f%8.3f%8.3f  1.\
00 %5.2f\\n\",$line_header, $n, $RAW_AT_ID,$RES_ID\
,$CHAIN,$out_pos, $X, $Y, $Z,$TEMP;		  \n}\n	     \
  elsif ( $MODE eq \"simple\")\n{\n		    if ( $RES\
_ID eq \"\"){$RES_ID=\"X\";}\n		  printf \"%-6s %5\
s %s %2s %4d    %8.3f %8.3f %8.3f\\n\",$line_heade\
r, $AT_ID, $RES_ID,($CHAIN eq\"\" || $CHAIN eq \" \
\")?\"A\":$CHAIN,$out_pos, $X, $Y, $Z,$TEMP;\n}\n\\
n}\n}\n}\n}\nprint \"\\n\";\nclose($INFILE);\n\n\n\
if ( $error ne \"\") \n{$error=$error.\"\\nDiagnos\
tic:    SEQRES and the residues in ATOM are probab\
ly Incompatible\\n\";\n    $error=$error.  \"Recom\
endation: Rerun with '-fix 1' in order to ignore t\
he SEQRES sequences\\n\";\n}\nif (!$nodiagnostic){\
print STDERR $error;}\n&myexit ( $EXIT_SUCCESS);\n\
\nsub get_pdb_entry_type_file\n  {\n    my $cache_\
file=\"$cache/pdb_entry_type.txt\";\n    my $env_f\
ile  = $ENV{\"PDB_ENTRY_TYPE_FILE\"};\n    my $pdb\
_file  =\"$ENV{'PDB_DIR'}/derived_data/pdb_entry_t\
ype.txt\";\n    \n    \n    if (-z $cache_file){un\
link ($cache_file);}#will get updated\n    if (-z \
$env_file){$env_file=\"\";}    #cannot update\n   \
 if (-z $pdb_file){$pdb_file=\"\";}    #cannot upd\
ate\n    \n    if    (-e $env_file){return $env_fi\
le;} #env wins: user decides\n    elsif (-e $pdb_f\
ile){return $pdb_file;} #local database wins: netw\
ork file may be out of sync\n    elsif ($no_remote\
_pdb_dir==1)\n      {\n	if (-e $cache_file){return\
 $cache_file;}\n	else\n	  {add_warning($$,$$,\"PDB\
_ENTRY_TYPE_FILE must be set to the location of <p\
db>/derived_data/pdb_entry_type.txt when using NO_\
REMOTE_PDB_DIR=1\");\n	   return \"\";\n	 }\n     \
 }\n    else #update can only take place if the fi\
le lives in cache\n      {\n	my $new_file;\n	if (!\
-e $cache_file || (-M $cache_file)>1)\n	  {\n	    \
$new_file=vtmpnam();\n	    &url2file(\"ftp://ftp.w\
wpdb.org/pub/pdb/derived_data/pdb_entry_type.txt\"\
, $new_file);\n	    if ( !-z $new_file){system (\"\
mv $new_file $cache_file\"); unlink ($new_file); $\
new_file=$cache_file;}\n	    else {unlink($new_fil\
e);}\n	  }\n	else\n	  {\n	    $new_file=$cache_fil\
e;\n	  }\n	\n	if (!-e $cache_file && !-e $new_file\
)\n	  {\n	    add_warning($$,$$,\"Could not downlo\
ad ftp://ftp.wwpdb.org/pub/pdb/derived_data/pdb_en\
try_type.txt\");\n	    return \"\";\n	  }\n	elsif \
(-e $cache_file && !-e $new_file)\n	  {\n	    my $\
m=(-M $cache_file);\n	    add_warning($$,$$,\"Coul\
d not update file ftp://ftp.wwpdb.org/pub/pdb/deri\
ved_data/pdb_entry_type.txt. Older Version [$cache\
_file]($m Month(s) old) will be used instead\");\n\
	    return $cache_file;\n	  }\n	else\n	  {\n	    \
return $new_file;\n	  }\n      }\n  }\n\n\n\nsub g\
et_unrealeased_file\n  {\n    my $cache_file=\"$ca\
che/unrealeased.xml\";\n    my $env_file  = $ENV{\\
"PDB_UNREALEASED_FILE\"};\n    my $pdb_file  =\"$E\
NV{'PDB_DIR'}/derived_data/unrealeased.xml\";\n   \
 \n    \n    if ($env_file eq \"NO\" || $env_file \
eq \"No\" || $env_file eq \"no\" || $env_file eq \\
"0\"){return \"NO\";}\n\n    if (-z $cache_file){u\
nlink ($cache_file);}#will get updated\n    if (-z\
 $env_file){unlink($env_file);}     #will update\n\
    if (-z $pdb_file){$pdb_file=\"\";}          #c\
annot update\n    \n    if    (-e $env_file){retur\
n $env_file;} #env wins: user decides\n    elsif (\
-e $pdb_file){return $pdb_file;} #local database w\
ins: network file may be out of sync\n    elsif ($\
no_remote_pdb_dir==1)        \n      {\n	if (-e $c\
ache_file){return $cache_file;}\n	elsif ( $env_fil\
e && ! -e $env_file)\n	  {\n	    &url2file(\"http:\
//www.rcsb.org/pdb/rest/getUnreleased\",$env_file)\
;\n	    if ( -e $env_file && !-z $env_file){return\
 $env_file;}\n	  }\n	else\n	  {\n	    add_warning(\
$$,$$,\"UNREALEASED_FILE must be set to the locati\
on of your unrealeased.xml file as downloaded from\
 http://www.rcsb.org/pdb/rest/getUnreleased when u\
sing NO_REMOTE_PDB_DIR=1\");\n	    return \"\";\n	\
  }\n      }\n    else #update can only take place\
 if the file lives in cache\n      {\n	my $new_fil\
e=vtmpnam ();\n	if (!-e $cache_file || (-M $cache_\
file)>1)\n	  {\n	    &url2file(\"http://www.rcsb.o\
rg/pdb/rest/getUnreleased\",$new_file);\n	    if (\
 !-z $new_file){system (\"mv $new_file $cache_file\
\"); unlink ($new_file); $new_file=$cache_file;}\n\
	    else {unlink($new_file);}\n	  }\n	else\n	  {\\
n	    $new_file=$cache_file;\n	  }\n	\n	if (!-e $c\
ache_file && !-e $new_file)\n	  {\n	    add_warnin\
g($$,$$,\"Could not download http://www.rcsb.org/p\
db/rest/getUnreleased\");\n	    return \"\";\n	  }\
\n	elsif (-e $cache_file && !-e $new_file)\n	  {\n\
	    my $m=(-M $cache_file);\n	    add_warning($$,\
$$,\"Could not update file http://www.rcsb.org/pdb\
/rest/getUnreleased. Older Version [$cache_file]($\
m Month(s) ) will be used\");\n	    return $cache_\
file;\n	  }\n	else\n	  {\n	    return $new_file;\n\
	  }\n      }\n  }\n\nsub is_released \n  {\n    m\
y ($r);\n    my $in=@_[0];\n    my $name=&remote_i\
s_pdb_name ($in);\n    my $hold=&remote_is_on_hold\
($in);\n    \n    $r=($name && !$hold)?1:0;\n    r\
eturn $r;\n  }\n\nsub remote_is_pdb_name \n  {\n  \
  my $in=@_[0];\n    my ($pdb);\n    my ($value,$v\
alue1,$value2);\n    my $max=2;\n    \n    \n    \\
n    my $ref_file=&get_pdb_entry_type_file();\n   \
 \n    if ( $in=~/[^\\w\\d\\:\\_]/){return 0;}\n  \
  elsif (!-e $ref_file)\n      {\n	add_warning ($$\
,$$,\"Cannot find pdb_entry_type.txt;  $in is assu\
med to be valid; add ftp://ftp.wwpdb.org/pub/pdb/d\
erived_data/pdb_entry_type.txt in $cache to automa\
tically check name status\");\n	return 1;\n      }\
\n    else\n      {\n	$pdb=substr ($in,0, 4);\n	ch\
omp(($value1=`grep -c $pdb $ref_file`));\n	$pdb=lc\
($pdb);\n	chomp(($value2=`grep -c $pdb $ref_file`)\
);\n	$value=($value1 || $value2)?1:0;\n	$value=($v\
alue>0)?1:0;\n	\n	return $value;\n      }\n  }\n\n\
\n\nsub pdb2model_type\n{\n    my $in=@_[0];\n    \
my ($ref_file, $pdb);\n    my ($value, $ret);\n\n \
   if ( $in=~/[^\\w\\d\\:\\_]/){return 0;}\n    $r\
ef_file=&get_pdb_entry_type_file();\n    if (!-e $\
ref_file)\n      {\n	add_warning ($$,$$,\"Cannot f\
ind pdb_entry_type.txt;  $in is assumed to be diff\
raction; add ftp://ftp.wwpdb.org/pub/pdb/derived_d\
ata/pdb_entry_type.txt in $cache to check name sta\
tus\");\n	return \"diffraction\";\n      }\n    el\
se\n      {\n	$pdb=substr ($in,0, 4);\n	$pdb=lc($p\
db);\n	\n	chomp(($value=`grep $pdb $ref_file`));\n\
	\n	$value=~/^\\S+\\s+\\S+\\s+(\\S+)/;\n	$ret=$1;\\
n	if ( $ret eq\"\"){return \"UNKNOWN\";}\n	\n	retu\
rn $ret;\n      }\n  }\nsub remote_is_on_hold\n  {\
\n    my $in=@_[0];\n    my ($ref_file, $pdb);\n  \
  my ($value1, $value2,$value);\n    \n\n\n    \n \
   $ref_file=&get_unrealeased_file();\n    if ($re\
f_file eq \"NO\"){return 0;}\n\n\n    if ($no_remo\
te_pdb==1){return 0;}\n    if ( $in=~/[^\\w\\d\\:\\
\_]/){return 0;}\n    \n    $ref_file=&get_unreale\
ased_file();\n    if (!-e $ref_file)\n      {\n	ad\
d_warning ($$,$$,\"Cannot find unrealeased.xml;  $\
in is assumed to be released;\");\n	return 1;\n   \
   }\n    \n    $pdb=substr ($in,0, 4);\n    chomp\
(($value1=`grep -c $pdb $ref_file`));\n    $pdb=lc\
($pdb);\n    chomp(($value2=`grep -c $pdb $ref_fil\
e`));\n    $value=($value1 || $value2)?1:0;\n    $\
value=($value>0)?1:0;\n    return $value;\n  }\n\n\
sub is_pdb_file\n  {\n    my @arg=@_;\n    \n    i\
f ( !-e $arg[0]){return 0;}\n    \n    $F=vfopen (\
$arg[0], \"r\");\n    while ( <$F>)\n      {\n	if \
(/^HEADER/)\n	  {\n	    close $F;\n	    return 1;\\
n	  }\n	elsif ( /^SEQRES/)\n	  {\n	    close $F;\n\
	    return 1;\n	  }\n	elsif ( /^ATOM/)\n	  {\n	  \
  close $F;\n	    return 1;\n	  }\n      }\n    re\
turn 0;\n  }\nsub get_pdb_id\n{\n    my $header_fi\
le=@_[0];\n    my $id;\n    my $F= new FileHandle;\
\n    \n    \n    $F=vfopen (\"$header_file\", \"r\
\");\n\n    while ( <$F>)\n      {\n	if ( /HEADER/\
)\n	  {\n	    if ($debug){print \"$_\";}\n	    $id\
=substr($_,62,4 );\n	    return $id;\n	  }\n      \
}\n    close ($F);\n    \n    return \"\";\n}\n\ns\
ub get_ligand_list\n{\n    my $pdb_file=@_[0];\n  \
  my $chain;\n    my $ligand;\n    my %complete_li\
gand_list;\n    \n\n    $F=vfopen ($pdb_file, \"r\\
");\n    while ( <$F>)\n{\n	if ( /^HETATM/)\n{\n	 \
   $line=$_;\n	    $chain=substr($line,21,1);\n	  \
  $ligand=substr($line,17,3);\n	    \n	    if (!$c\
omplete_ligand_list{$chain}{$ligand})\n{\n		\n		$c\
omplete_ligand_list{\"result\"}.=\"CHAIN $chain LI\
GAND $ligand\\n\";\n		$complete_ligand_list{$chain\
}{$ligand}=1;\n}\n}\n}\n    close ($F);\n    retur\
n %complete_ligand_list;\n}\n\nsub get_chain_list \
\n{\n    my $header_file;\n    my @chain_list;\n  \
  my @list;\n    my $n_chains;\n    my %chain_hasc\
h;\n    my $pdb_file=@_[0];\n    my $c;\n    my %h\
asch;\n    my $chain;\n  \n    \n    $F=vfopen ($p\
db_file, \"r\");\n    while ( <$F>)\n{\n\n\n	if (/\
SEQRES\\s+\\d+\\s+(\\S+)/)\n	  {\n	    $chain = su\
bstr($_,11,1);$chain=~s/\\s//g;if ( $chain eq \"\"\
){$chain=\" \";}\n	    if (!$hasch{$chain}){$hasch\
{$chain}=1;push @chain_list, $chain;}\n	  }\n	if (\
/^ATOM/ || /^HETATM/)\n	  {\n	    $chain = substr(\
$_,21,1); $chain=~s/\\s//g;if ( $chain eq \"\"){$c\
hain=\" \";}\n	    if (!$hasch{$chain}){$hasch{$ch\
ain}=1;push @chain_list, $chain;}\n	  }\n      }\n\
\n\nclose ($F);\nif (!@chain_list)\n  {\n    @chai\
n_list=(\"A\");\n  }\n\n\nreturn @chain_list;\n}\n\
\nsub token_is_in_list\n{\n\n    my @list=@_;\n   \
 my $a;\n    \n    for ($a=1; $a<=$#list; $a++)\n{\
\n	if ( $list[$a] eq $list[0]){return $a;}\n}\n}\n\
\nsub pdb_name2name_and_chain \n{\n    my $pdb_fil\
e=@_[0];\n    my $pdb_file_in;\n    my @array;\n  \
  my $chain;\n    my $c;\n\n    $pdb_file_in=$pdb_\
file;\n\n    $pdb_file=~/^(.{4})/;$pdb_id=$1;\n   \
 @array=($pdb_file=~/([\\w])/g);\n  \n  \n    $cha\
in=uc ($array[4]);\n    $chain=($chain eq \"\")?\"\
FIRST\":$chain;\n    \n    return ( $pdb_id, $chai\
n);\n\n    if ( $#array==3){return ($pdb_id, \"FIR\
ST\");}\n    elsif ( $#array<4){ return ($pdb_id, \
\"\");}\n    else {return ( $pdb_id, $chain);}\n  \
    \n    \n    \n}\nsub get_main_hom_code \n{\n  \
  my $pdb_file=@_[0];\n    my %hom, $n, $best, $be\
st_h;\n    open (F, $pdb_file);\n    while (<F>)\n\
{\n	if ( $_=~/^ATOM/)\n{\n	    $h=substr ($_,26, 1\
);\n	    $n=++$hom{$h};\n	    if ($n>$best)\n{\n		\
$best=$n;\n		$best_h=$h;\n}\n}\n}\n    close (F);\\
n    return $best_h;\n}\n\n\nsub get_pdb_file \n{\\
n    my ($pdb_file_in)=(@_);\n    my $result;\n   \
 my @letter;\n    my @chain;\n    my $v;\n    my $\
pdb_file=$pdb_file_in;\n\n    $pdb_file=($pdb_file\
_in=~/\\S+_S_(\\S+)/)?$1:$pdb_file_in;\n    \n    \
if ($no_remote_pdb_dir==0)\n      {\n	$no_remote_p\
db_dir=1;\n	$result=get_pdb_file3 ($pdb_file);\n	$\
no_remote_pdb_dir=0;\n	if ( $result){return $resul\
t;}\n	else\n	  {\n	    \n	    lc ($pdb_file);\n	  \
  $result=get_pdb_file3($pdb_file);\n	    return  \
$result;\n	  }\n      }\n    else\n      {\n	retur\
n get_pdb_file3 ($pdb_file);\n      }\n    \n  }\n\
\nsub get_pdb_file3 \n{\n    my $pdb_file_in=@_[0]\
;\n    my $result;\n    my @letter;\n    my @chain\
;\n    my $lcfile;\n    my $ucfile;\n    my $pdb_f\
ile=$pdb_file_in;\n    \n    $lcfile=lc $pdb_file;\
\n    $ucfile=uc $pdb_file;\n\n    if ( ($result=g\
et_pdb_file2 ($pdb_file))){return $result;}\n    \\
n\n    if ($lcfile ne $pdb_file && ($result=get_pd\
b_file2 ($lcfile))){return $result;}\n    if ($ucf\
ile ne $pdb_file && ($result=get_pdb_file2 ($ucfil\
e))){return $result;}\n    \n   \n    \n    return\
 \"\";\n}\nsub get_pdb_file2\n{\n    my $pdb_file=\
@_[0];\n    my $return_value;\n    \n    $return_v\
alue=\"\";\n    \n    if ( ($result=get_pdb_file1 \
($pdb_file))){$return_value=$result;}\n    elsif (\
 !($pdb_file=~/\\.pdb/) && !($pdb_file=~/\\.PDB/))\
\n{\n	if ( ($result=get_pdb_file1 (\"$pdb_file.pdb\
\"))){$return_value=$result;}\n	elsif ( ($result=g\
et_pdb_file1 (\"$pdb_file.PDB\"))){$return_value=$\
result;}\n\n	elsif ( ($result=get_pdb_file1 (\"pdb\
$pdb_file.pdb\"))){$return_value=$result;}	\n	elsi\
f ( ($result=get_pdb_file1 (\"pdb$pdb_file.PDB\"))\
){$return_value=$result;}\n	elsif ( ($result=get_p\
db_file1 (\"PDB$pdb_file.PDB\"))){$return_value=$r\
esult;}\n	elsif ( ($result=get_pdb_file1 (\"PDB$pd\
b_file.pdb\"))){$return_value=$result;}\n	\n	\n	el\
sif ( ($result=get_pdb_file1 (\"$pdb_file.ent\")))\
{$return_value=$result;}\n	elsif ( ($result=get_pd\
b_file1 (\"pdb$pdb_file.ent\"))){$return_value=$re\
sult;}\n	elsif ( ($result=get_pdb_file1 (\"PDB$pdb\
_file.ent\"))){$return_value=$result;}\n\n	elsif (\
 ($result=get_pdb_file1 (\"$pdb_file.ENT\"))){$ret\
urn_value=$result;}\n	elsif ( ($result=get_pdb_fil\
e1 (\"pdb$pdb_file.ENT\"))){$return_value=$result;\
}\n	elsif ( ($result=get_pdb_file1 (\"PDB$pdb_file\
.ENT\"))){$return_value=$result;}\n	\n	\n	\n}\n   \
 return $return_value;\n}\n    \nsub get_pdb_file1\
\n{\n    my ($pdb_file)=(@_);\n    my $return_valu\
e;\n    \n\n    $return_value=\"\";\n    if ( ($re\
sult=get_pdb_file0 ($pdb_file))){$return_value=$re\
sult;}\n    elsif ( ($result=get_pdb_file0 (\"$pdb\
_file.Z\"))){$return_value=$result;}\n    elsif ( \
($result=get_pdb_file0 (\"$pdb_file.gz\"))){$retur\
n_value=$result;}\n    elsif ( ($result=get_pdb_fi\
le0 (\"$pdb_file.GZ\"))){$return_value=$result;}\n\
    return $return_value;\n}\nsub get_pdb_file0 \n\
{ \n    my ($pdb_file, $attempt)=(@_);\n    my $pd\
b_file=@_[0];\n    my $tmp_pdb_file;    \n    my $\
return_value;\n\n    if ( !$attempt){$attempt=1;}\\
n    \n    $local_pdb_file=\"$pdb_file\";\n    if \
( $local_pdb_file eq \"\")\n{\n	$tmp_pdb_file=vtmp\
nam();\n	open F, \">$tmp_pdb_file\";\n	\n	while (<\
STDIN>){print F \"$_\";}\n	close (F);\n	\n	if (-e \
$tmp_pdb_file && &is_pdb_file ( $local_pdb_file))\\
n{return $tmp_pdb_file;}\n}\n\n    $local_pdb_file\
=\"$pdb_file\";\n    &debug_print (\"\\nTry access\
 local file: $local_pdb_file\");\n    \n    $local\
_pdb_file=&check_pdb_file4compression ($local_pdb_\
file);\n    if ( -e $local_pdb_file && (&is_pdb_fi\
le ($local_pdb_file) || $force_pdb))\n{\n	&debug_p\
rint ( \"\\n\\tIs in Current Dir\");\n	$tmp_pdb_fi\
le=vtmpnam();\n	`cp $local_pdb_file $tmp_pdb_file`\
;\n	return $tmp_pdb_file;\n}\n    else\n{\n	&debug\
_print (\"\\n\\tFile Not in Current Dir\");\n}\n\n\
    if ($pdb_file=~/^pdb/||$pdb_file=~/^PDB/){$pdb\
_div=substr ($pdb_file, 4, 2);}\n    else\n{\n	  $\
pdb_div=substr ($pdb_file, 1, 2);\n}\n    $local_p\
db_file=\"$pdb_dir/$pdb_div/$pdb_file\";\n    $loc\
al_pdb_file=&check_pdb_file4compression ( $local_p\
db_file);\n    &debug_print (\"\\nTry access file \
From PDB_DIR: $local_pdb_file\");\n    if ($pdb_di\
r && -e $local_pdb_file && &is_pdb_file ($local_pd\
b_file))\n{\n	&debug_print ( \"\\n\\tIs in Local P\
DB DIR\");\n	$tmp_pdb_file=vtmpnam();\n	`cp $local\
_pdb_file $tmp_pdb_file`;\n	return $tmp_pdb_file;\\
n}\n\n    $local_pdb_file=\"$pdb_dir/$pdb_file\";\\
n    $local_pdb_file=&check_pdb_file4compression (\
 $local_pdb_file);\n    &debug_print (\"\\nTry acc\
ess file From PDB_DIR: local_pdb_file\");\n    if \
($pdb_dir && -e $local_pdb_file && &is_pdb_file ($\
local_pdb_file))\n{\n	&debug_print ( \"\\n\\tIs in\
 Local PDB DIR\");\n	$tmp_pdb_file=vtmpnam();\n	`c\
p $local_pdb_file $tmp_pdb_file`;\n	return $tmp_pd\
b_file;\n}\n\n    $local_pdb_file=\"$pdb_dir$pdb_f\
ile\";\n    $local_pdb_file=&check_pdb_file4compre\
ssion ( $local_pdb_file);\n    &debug_print (\"\\n\
Try access file From PDB_DIR: $local_pdb_file\");\\
n    if ($pdb_dir && -e $local_pdb_file && &is_pdb\
_file ($local_pdb_file))\n{\n	&debug_print ( \"\\n\
\\tIs in Local PDB DIR\");\n	$tmp_pdb_file=vtmpnam\
();\n	`cp $local_pdb_file $tmp_pdb_file`;\n	return\
 $tmp_pdb_file;\n}\n    else\n{&debug_print ( \"\\\
n\\tNot In Local Pdb Dir\");}\n\n    if ($cache ne\
 \"NO\" && $cache ne \"no\")\n{\n\n	$local_pdb_fil\
e=\"$cache/$pdb_file\";\n	$local_pdb_file=&check_p\
db_file4compression ( $local_pdb_file);\n	&debug_p\
rint(\"\\nTry access file From Cache: $local_pdb_f\
ile\");\n	if (-e $local_pdb_file && &is_pdb_file (\
$local_pdb_file))\n{\n	    &debug_print ( \"\\n\\t\
Is in T-Coffee Cache\");\n	    $tmp_pdb_file=vtmpn\
am();\n	    `cp $local_pdb_file $tmp_pdb_file`;\n	\
    return $tmp_pdb_file;\n}\n	else{&debug_print (\
 \"\\n\\tNot in Cache Dir\");}\n}\n\nif (!$no_remo\
te_pdb_dir) \n  {\n    my $value=&is_released ($pd\
b_file);\n    my $return_value=\"\";\n    if ($val\
ue==1)\n      {\n	\n	&debug_print (\"\\n**********\
*******************************************\\nTry \
Remote Access for $pdb_file\");\n	$tmp_pdb_file=vt\
mpnam();\n	$netcommand=$netaddress;\n	$netcommand=\
~s/%%/$pdb_file/g;\n	&url2file(\"$netcommand\", \"\
$tmp_pdb_file.$netcompression\");\n	&debug_print(\\
"\\nREMOTE: $netcommand\\n\");\n	\n	$compressed_tm\
p_file_name=\"$tmp_pdb_file.$netcompression\";\n	\\
n	if ($netcompression && -B $compressed_tmp_file_n\
ame && $attempt<5)\n	  {\n	    my $r;\n	    &debug\
_print (\"\\n\\tFile Found Remotely\");\n	    if (\
($r=safe_system ( \"$netcompression_pg $compressed\
_tmp_file_name\")!=$EXIT_SUCCESS) && $attempts<5)\\
n	      {\n		&debug_print (\"\\n\\tProper Download\
 Failed Try again\");\n		unlink $compressed_tmp_fi\
le_name;\n		print \"\\nFailed to Download $compres\
sed_tmp_file_name. New Attempt $attempt/5\\n\";\n	\
	return &get_pdb_file0($pdb_file, $attempt+1);\n	 \
     }\n	    elsif ($r== $EXIT_SUCCESS)\n	      {\\
n		&debug_print (\"\\n\\tProper Download Succeeded\
 \");\n		$return_value=$tmp_pdb_file;\n	      }\n	\
    else\n	      {\n		&debug_print (\"\\n\\tProper\
 Download Failed \");\n		&debug_print (\"\\nFile N\
ot Found Remotely\");\n		unlink $compressed_tmp_fi\
le_name;\n	      }\n	  }\n	else\n	  {\n\n	    &deb\
ug_print (\"\\nFile Not Found Remotely\");\n	    u\
nlink $compressed_tmp_file_name;\n	  }\n	#Update c\
ache if required\n	if ($cache ne \"no\" && $cache \
ne \"update\" && -e $return_value)\n	  {\n	    `cp\
 $return_value $cache/$pdb_file.pdb`;\n	    #`t_co\
ffee -other_pg clean_cache.pl -file $pdb_file.pdb \
-dir $cache`;\n	  }\n      }\n    &debug_print (\"\
\\nRemote Download Finished\");\n    return $retur\
n_value;\n  }\nreturn \"\";\n}\n\nsub check_pdb_fi\
le4compression \n{\n    my $file=@_[0];\n    my $t\
mp;\n    my $r;\n    \n    $tmp=&vtmpnam();\n    i\
f (-e $tmp){unlink $tmp;}\n    \n    $file=~s/\\/\\
\//\\//g;\n    if    (-B $file && ($file=~/\\.Z/))\
 {`cp $file $tmp.Z`;`rm $tmp`;`gunzip $tmp.Z $SILE\
NT`;$r=$tmp;}\n    elsif (-B $file && ($file=~/\\.\
gz/)){`cp $file $tmp.gz`;`gunzip $tmp.gz $SILENT`;\
return $r=$tmp;}\n    elsif (-B $file ){`cp $file \
$tmp.gz`;`gunzip $tmp.gz $SILENT`;$r=$tmp;}\n    e\
lsif ( -e $file ) {$r= $file;}\n    elsif ( -e \"$\
file.gz\" ){ `cp $file.gz $tmp.gz`;`gunzip     $tm\
p.gz $SILENT`;$r=$tmp;}    \n    elsif ( -e \"$fil\
e.Z\") {`cp $file.Z  $tmp.Z`; `gunzip $tmp.Z $SILE\
NT`;$r=$tmp;}\n    else  {$r= $file;}\n\n    if ( \
-e \"$tmp.Z\"){unlink \"$tmp.Z\";}\n    if ( -e \"\
$tmp.gz\"){unlink \"$tmp.gz\";}\n    \n    return \
$r;\n    \n}\n\n\n\n\n\n    \n\n\n\n\n\n\n\nsub vf\
open \n{\n    my $file=@_[0];\n    my $mode=@_[1];\
\n    my $tmp;\n    my $F = new FileHandle;\n    \\
n    \n    $tmp=$file;\n	\n    \n    if ( $mode eq\
 \"r\" && !-e $file){ myexit(flush_error (\"Cannot\
 open file $file\"));}\n    elsif ($mode eq \"w\")\
{$tmp=\">$file\";}\n    elsif ($mode eq \"a\"){$tm\
p=\">>$file\";}\n    \n    \n    open ($F,$tmp);\n\
    return $F;\n}\nsub debug_print\n{\n    my $mes\
sage =@_[0];\n    if ($debug){print STDERR \"NO_RE\
MOTE_PDB_DIR: $no_remote_pdb_dir - $message [DEBUG\
:extract_from_pdb]\";}\n    return;\n}\nsub is_aa \
\n{\n    my ($aa, $chain) =@_;\n\n    my $one;\n  \
  my $trhee;\n    \n    if ( $onelett{$molecule_ty\
pe{$chain}}->{$aa} eq 'X' || !$onelett{$molecule_t\
ype{$chain}}->{$aa} ){return '';}\n    else\n     \
 {\n	$one=$onelett{$molecule_type{$chain}}->{$aa};\
\n\n	$three=$threelett{$molecule_type{$chain}}->{$\
one};\n	\n\n	return $three;\n      }\n  }\n\n\n\n\\
n\nsub url2file\n{\n    my ($address, $out, $wget_\
arg, $curl_arg)=(@_);\n    my ($pg, $flag, $r, $ar\
g, $count);\n    \n    if (!$CONFIGURATION){&check\
_configuration (\"wget\", \"INTERNET\", \"gzip\");\
$CONFIGURATION=1;}\n    \n    if (&pg_is_installed\
 (\"wget\"))   {$pg=\"wget\"; $flag=\"-O\";$arg=$w\
get_arg;}\n    elsif (&pg_is_installed (\"curl\"))\
{$pg=\"curl\"; $flag=\"-o\";$arg=$curl_arg;}\n    \
return safe_system (\"$pg $flag$out $address >/dev\
/null 2>/dev/null\");\n\n}\n\n\n\n\nsub pdbfile2ch\
aintype\n  {\n    my $file=@_[0];\n    my %ct;\n  \
  my $F;\n    \n    $F=vfopen ($file, \"r\");\n   \
 while (<$F>)\n      {\n	my $line=$_;\n	if ($line \
=~/^ATOM/)\n	  {\n	    my $C=substr($line,21,1);\n\
	    if (!$ct{$C})\n	      {	\n		my $r=substr($lin\
e,17,3);\n		$r=~s/\\s+//;\n		if (length ($r)==1){$\
ct{$C}=\"R\";}\n		elsif (length ($r)==2){$ct{$C}=\\
"D\";}\n		elsif (length ($r)==3){$ct{$C}=\"P\";}\n\
		else \n		  {\n		    myexit(flush_error(\"ERROR: \
Could not read RES_ID field in file $file\"));\n		\
  }\n	      }\n	  }\n      }\n    close ($F);\n   \
 return %ct;\n  }\n   \n    \n\n\n\nsub fill_three\
lett_RNA\n{\n\n	my %threelett=(\n	'A', '  A',\n	'T\
', '  T',\n	'U', '  U',\n	'C', '  C',\n	'G', '  G'\
,\n	'I', '  I', #Inosine\n	);\n	\n	return %threele\
tt;\n\n}\n\n\nsub fill_onelett_RNA\n{\n	my   %onel\
ett=(\n	'  A' => 'A',\n	'  T' => 'T',\n	'  U' => '\
U',\n	'  C' => 'C',\n	'  G' => 'G',\n	'CSL' => 'X'\
,\n	'UMS' => 'X',\n	'  I' => 'I',\n	'A' => 'A',\n	\
'T' => 'T',\n	'U' => 'U',\n	'C' => 'C',\n	'G' => '\
G',\n	'I' => 'I',\n	);\n\n	return %onelett;\n\n}\n\
\n\nsub fill_onelett_DNA\n{\n	my   %onelett=(\n	' \
DA', 'A',\n	' DT', 'T',\n	' DC', 'C',\n	' DG', 'G'\
,\n	'DA', 'A',\n	'DT', 'T',\n	'DC', 'C',\n	'DG', '\
G',\n	);\n\n	return %onelett;\n\n}\n\nsub fill_thr\
eelett_DNA\n{\n\n	my %threelett=(\n	'A', ' DA',\n	\
'T', ' DT',\n	'C', ' DC',\n	'G', ' DG',\n	);\n\n	r\
eturn %threelett;\n\n}\n\n\n\n\nsub fill_threelett\
_prot\n{  \n  my %threelett;\n\n  %threelett=(\n'A\
', 'ALA',\n'C', 'CYS',\n'D', 'ASP',\n'E', 'GLU',\n\
'F', 'PHE',\n'G', 'GLY',\n'H', 'HIS',\n'I', 'ILE',\
\n'K', 'LYS',\n'L', 'LEU',\n'N', 'ASN',\n'M', 'MET\
',\n'P', 'PRO',\n'Q', 'GLN',\n'R', 'ARG',\n'S', 'S\
ER',\n'T', 'THR',\n'V', 'VAL',\n'W', 'TRP',\n'Y', \
'TYR',\n);\n\nreturn %threelett;\n\n\n}\n\nsub fil\
l_onelett_prot\n{\n    my %onelett;\n    \n    %on\
elett=(\n\n'10A', 'X',\n'11O', 'X',\n'12A', 'X',\n\
'13P', 'X',\n'13R', 'X',\n'13S', 'X',\n'14W', 'X',\
\n'15P', 'X',\n'16A', 'X',\n'16G', 'X',\n'1AN', 'X\
',\n'1AP', 'X',\n'1AR', 'X',\n'1BH', 'X',\n'1BO', \
'X',\n'1C5', 'X',\n'1CU', 'X',\n'1DA', 'X',\n'1GL'\
, 'X',\n'1GN', 'X',\n'1IN', 'X',\n'1LU', 'L',\n'1M\
A', 'X',\n'1MC', 'X',\n'1MG', 'X',\n'1MZ', 'X',\n'\
1NA', 'X',\n'1NB', 'X',\n'1NI', 'X',\n'1PA', 'A',\\
n'1PC', 'X',\n'1PE', 'X',\n'1PG', 'X',\n'1PI', 'A'\
,\n'1PM', 'X',\n'1PN', 'X',\n'1PU', 'X',\n'1PY', '\
X',\n'1UN', 'X',\n'24T', 'X',\n'25T', 'X',\n'26P',\
 'X',\n'2AB', 'X',\n'2AM', 'X',\n'2AN', 'X',\n'2AP\
', 'X',\n'2AR', 'X',\n'2AS', 'D',\n'2BL', 'X',\n'2\
BM', 'X',\n'2CP', 'X',\n'2DA', 'X',\n'2DG', 'X',\n\
'2DP', 'X',\n'2DT', 'X',\n'2EP', 'X',\n'2EZ', 'X',\
\n'2FG', 'X',\n'2FL', 'X',\n'2FP', 'X',\n'2FU', 'X\
',\n'2GL', 'X',\n'2GP', 'X',\n'2HP', 'X',\n'2IB', \
'X',\n'2IP', 'X',\n'2LU', 'L',\n'2MA', 'X',\n'2MD'\
, 'X',\n'2ME', 'X',\n'2MG', 'X',\n'2ML', 'L',\n'2M\
O', 'X',\n'2MR', 'R',\n'2MU', 'X',\n'2MZ', 'X',\n'\
2NO', 'X',\n'2NP', 'X',\n'2OG', 'X',\n'2PA', 'X',\\
n'2PC', 'X',\n'2PE', 'X',\n'2PG', 'X',\n'2PH', 'X'\
,\n'2PI', 'X',\n'2PL', 'X',\n'2PP', 'X',\n'2PU', '\
X',\n'2SI', 'X',\n'2TB', 'X',\n'34C', 'X',\n'35G',\
 'X',\n'3AA', 'X',\n'3AD', 'X',\n'3AH', 'H',\n'3AN\
', 'X',\n'3AP', 'X',\n'3AT', 'X',\n'3BT', 'X',\n'3\
CH', 'X',\n'3CN', 'X',\n'3CO', 'X',\n'3CP', 'X',\n\
'3DR', 'X',\n'3EP', 'X',\n'3FM', 'X',\n'3GA', 'X',\
\n'3GP', 'X',\n'3HB', 'X',\n'3HC', 'X',\n'3HP', 'X\
',\n'3IB', 'X',\n'3ID', 'X',\n'3IN', 'X',\n'3MA', \
'X',\n'3MB', 'X',\n'3MC', 'X',\n'3MD', 'D',\n'3MF'\
, 'X',\n'3MP', 'X',\n'3MT', 'X',\n'3OL', 'X',\n'3P\
A', 'X',\n'3PG', 'X',\n'3PO', 'X',\n'3PP', 'X',\n'\
3PY', 'X',\n'49A', 'X',\n'4AB', 'X',\n'4AM', 'X',\\
n'4AN', 'X',\n'4AP', 'X',\n'4BA', 'X',\n'4BT', 'X'\
,\n'4CA', 'X',\n'4CO', 'X',\n'4HP', 'X',\n'4IP', '\
X',\n'4MO', 'X',\n'4MV', 'X',\n'4MZ', 'X',\n'4NC',\
 'X',\n'4NP', 'X',\n'4OX', 'X',\n'4PB', 'X',\n'4PN\
', 'X',\n'4PP', 'X',\n'4SC', 'X',\n'4SU', 'X',\n'4\
TB', 'X',\n'55C', 'X',\n'5AD', 'X',\n'5AN', 'X',\n\
'5AT', 'X',\n'5CM', 'X',\n'5GP', 'X',\n'5HP', 'E',\
\n'5HT', 'X',\n'5IT', 'X',\n'5IU', 'X',\n'5MB', 'X\
',\n'5MC', 'X',\n'5MD', 'X',\n'5MP', 'X',\n'5MU', \
'X',\n'5NC', 'X',\n'5OB', 'X',\n'5PA', 'X',\n'5PV'\
, 'X',\n'6AB', 'X',\n'6CT', 'X',\n'6HA', 'X',\n'6H\
C', 'X',\n'6HG', 'X',\n'6HT', 'X',\n'6IN', 'X',\n'\
6MO', 'X',\n'6MP', 'X',\n'6PG', 'X',\n'6WO', 'X',\\
n'70U', 'X',\n'7DG', 'X',\n'7HP', 'X',\n'7I2', 'X'\
,\n'7MG', 'X',\n'7MQ', 'X',\n'7NI', 'X',\n'87Y', '\
X',\n'8AD', 'X',\n'8BR', 'X',\n'8IG', 'X',\n'8IN',\
 'X',\n'8OG', 'X',\n'95A', 'X',\n'9AD', 'X',\n'9AM\
', 'X',\n'9AP', 'X',\n'9DG', 'X',\n'9DI', 'X',\n'9\
HX', 'X',\n'9OH', 'X',\n'9TA', 'X',\n'A12', 'X',\n\
'A15', 'X',\n'A23', 'X',\n'A24', 'X',\n'A26', 'X',\
\n'A2G', 'X',\n'A2P', 'X',\n'A32', 'X',\n'A3P', 'X\
',\n'A4P', 'X',\n'A5P', 'X',\n'A70', 'X',\n'A76', \
'X',\n'A77', 'X',\n'A78', 'X',\n'A79', 'X',\n'A80'\
, 'X',\n'A85', 'X',\n'A88', 'X',\n'A9A', 'X',\n'AA\
3', 'X',\n'AA4', 'X',\n'AA6', 'X',\n'AAA', 'X',\n'\
AAB', 'X',\n'AAC', 'X',\n'AAE', 'X',\n'AAG', 'R',\\
n'AAH', 'X',\n'AAM', 'X',\n'AAN', 'X',\n'AAP', 'X'\
,\n'AAR', 'R',\n'AAS', 'X',\n'AAT', 'X',\n'ABA', '\
X',\n'ABC', 'X',\n'ABD', 'X',\n'ABE', 'X',\n'ABH',\
 'X',\n'ABI', 'X',\n'ABK', 'X',\n'ABM', 'X',\n'ABN\
', 'X',\n'ABP', 'X',\n'ABR', 'X',\n'ABS', 'X',\n'A\
BU', 'X',\n'AC1', 'X',\n'AC2', 'X',\n'ACA', 'X',\n\
'ACB', 'D',\n'ACC', 'C',\n'ACD', 'X',\n'ACE', 'X',\
\n'ACH', 'X',\n'ACI', 'X',\n'ACL', 'R',\n'ACM', 'X\
',\n'ACN', 'X',\n'ACO', 'X',\n'ACP', 'X',\n'ACQ', \
'X',\n'ACR', 'X',\n'ACS', 'X',\n'ACT', 'X',\n'ACV'\
, 'V',\n'ACX', 'X',\n'ACY', 'X',\n'AD2', 'X',\n'AD\
3', 'X',\n'ADC', 'X',\n'ADD', 'X',\n'ADE', 'X',\n'\
ADH', 'X',\n'ADI', 'X',\n'ADM', 'X',\n'ADN', 'X',\\
n'ADP', 'X',\n'ADQ', 'X',\n'ADR', 'X',\n'ADS', 'X'\
,\n'ADT', 'X',\n'ADU', 'X',\n'ADW', 'X',\n'ADX', '\
X',\n'AE2', 'X',\n'AEA', 'X',\n'AEB', 'X',\n'AEI',\
 'D',\n'AEN', 'X',\n'AET', 'T',\n'AF1', 'X',\n'AF3\
', 'X',\n'AFA', 'D',\n'AFP', 'X',\n'AG7', 'X',\n'A\
GB', 'X',\n'AGF', 'X',\n'AGL', 'X',\n'AGM', 'R',\n\
'AGN', 'X',\n'AGP', 'X',\n'AGS', 'X',\n'AGU', 'X',\
\n'AH0', 'X',\n'AH1', 'X',\n'AHA', 'X',\n'AHB', 'D\
',\n'AHC', 'X',\n'AHF', 'X',\n'AHG', 'X',\n'AHH', \
'X',\n'AHM', 'X',\n'AHO', 'X',\n'AHP', 'X',\n'AHS'\
, 'X',\n'AHT', 'Y',\n'AHU', 'X',\n'AHX', 'X',\n'AI\
1', 'X',\n'AI2', 'X',\n'AIB', 'X',\n'AIC', 'X',\n'\
AIM', 'X',\n'AIP', 'X',\n'AIQ', 'X',\n'AIR', 'X',\\
n'AJ3', 'X',\n'AKB', 'X',\n'AKG', 'X',\n'AKR', 'X'\
,\n'AL1', 'X',\n'AL2', 'X',\n'AL3', 'X',\n'AL4', '\
X',\n'AL5', 'X',\n'AL6', 'X',\n'AL7', 'X',\n'AL8',\
 'X',\n'AL9', 'X',\n'ALA', 'A',\n'ALB', 'X',\n'ALC\
', 'X',\n'ALD', 'L',\n'ALE', 'X',\n'ALF', 'X',\n'A\
LG', 'X',\n'ALL', 'X',\n'ALM', 'A',\n'ALN', 'A',\n\
'ALO', 'T',\n'ALP', 'X',\n'ALQ', 'X',\n'ALR', 'X',\
\n'ALS', 'X',\n'ALT', 'A',\n'ALY', 'K',\n'ALZ', 'X\
',\n'AMA', 'X',\n'AMB', 'X',\n'AMC', 'X',\n'AMD', \
'X',\n'AMG', 'X',\n'AMH', 'X',\n'AMI', 'X',\n'AML'\
, 'X',\n'AMN', 'X',\n'AMO', 'X',\n'AMP', 'X',\n'AM\
Q', 'X',\n'AMR', 'X',\n'AMS', 'X',\n'AMT', 'X',\n'\
AMU', 'X',\n'AMW', 'X',\n'AMX', 'X',\n'AMY', 'X',\\
n'ANA', 'X',\n'ANB', 'X',\n'ANC', 'X',\n'AND', 'X'\
,\n'ANE', 'X',\n'ANI', 'X',\n'ANL', 'X',\n'ANO', '\
X',\n'ANP', 'X',\n'ANS', 'X',\n'ANT', 'X',\n'AOE',\
 'X',\n'AOP', 'X',\n'AP1', 'X',\n'AP2', 'X',\n'AP3\
', 'X',\n'AP4', 'X',\n'AP5', 'X',\n'AP6', 'X',\n'A\
PA', 'X',\n'APB', 'X',\n'APC', 'X',\n'APE', 'F',\n\
'APF', 'X',\n'APG', 'X',\n'APH', 'A',\n'API', 'X',\
\n'APL', 'X',\n'APM', 'X',\n'APN', 'G',\n'APP', 'X\
',\n'APQ', 'X',\n'APR', 'X',\n'APS', 'X',\n'APT', \
'X',\n'APU', 'X',\n'APX', 'X',\n'APY', 'X',\n'APZ'\
, 'X',\n'AQS', 'X',\n'AR1', 'X',\n'AR2', 'X',\n'AR\
A', 'X',\n'ARB', 'X',\n'ARC', 'X',\n'ARD', 'X',\n'\
ARG', 'R',\n'ARH', 'X',\n'ARI', 'X',\n'ARM', 'R',\\
n'ARN', 'X',\n'ARO', 'R',\n'ARP', 'X',\n'ARQ', 'X'\
,\n'ARS', 'X',\n'AS1', 'R',\n'AS2', 'X',\n'ASA', '\
D',\n'ASB', 'D',\n'ASC', 'X',\n'ASD', 'X',\n'ASE',\
 'X',\n'ASF', 'X',\n'ASI', 'X',\n'ASK', 'D',\n'ASL\
', 'X',\n'ASM', 'N',\n'ASO', 'X',\n'ASP', 'D',\n'A\
SQ', 'X',\n'ASU', 'X',\n'ATA', 'X',\n'ATC', 'X',\n\
'ATD', 'X',\n'ATF', 'X',\n'ATG', 'X',\n'ATH', 'X',\
\n'ATM', 'X',\n'ATO', 'X',\n'ATP', 'X',\n'ATQ', 'X\
',\n'ATR', 'X',\n'ATT', 'X',\n'ATY', 'X',\n'ATZ', \
'X',\n'AUC', 'X',\n'AUR', 'X',\n'AVG', 'X',\n'AXP'\
, 'X',\n'AYA', 'A',\n'AZ2', 'X',\n'AZA', 'X',\n'AZ\
C', 'X',\n'AZD', 'X',\n'AZE', 'X',\n'AZI', 'X',\n'\
AZL', 'X',\n'AZM', 'X',\n'AZR', 'X',\n'AZT', 'X',\\
n'B12', 'X',\n'B1F', 'F',\n'B2A', 'A',\n'B2F', 'F'\
,\n'B2I', 'I',\n'B2V', 'V',\n'B3I', 'X',\n'B3P', '\
X',\n'B7G', 'X',\n'B96', 'X',\n'B9A', 'X',\n'BA1',\
 'X',\n'BAA', 'X',\n'BAB', 'X',\n'BAC', 'X',\n'BAF\
', 'X',\n'BAH', 'X',\n'BAI', 'X',\n'BAK', 'X',\n'B\
AL', 'A',\n'BAM', 'X',\n'BAO', 'X',\n'BAP', 'X',\n\
'BAR', 'X',\n'BAS', 'X',\n'BAT', 'F',\n'BAY', 'X',\
\n'BAZ', 'X',\n'BB1', 'X',\n'BB2', 'X',\n'BBA', 'X\
',\n'BBH', 'X',\n'BBS', 'X',\n'BBT', 'X',\n'BBZ', \
'X',\n'BCA', 'X',\n'BCB', 'X',\n'BCC', 'X',\n'BCD'\
, 'X',\n'BCL', 'X',\n'BCN', 'X',\n'BCR', 'X',\n'BC\
S', 'C',\n'BCT', 'X',\n'BCY', 'X',\n'BCZ', 'X',\n'\
BDA', 'X',\n'BDG', 'X',\n'BDK', 'X',\n'BDM', 'X',\\
n'BDN', 'X',\n'BDS', 'X',\n'BE1', 'X',\n'BE2', 'X'\
,\n'BEA', 'X',\n'BEF', 'X',\n'BEN', 'X',\n'BEO', '\
X',\n'BEP', 'X',\n'BER', 'X',\n'BES', 'X',\n'BET',\
 'X',\n'BEZ', 'X',\n'BF2', 'X',\n'BFA', 'X',\n'BFD\
', 'X',\n'BFP', 'X',\n'BFS', 'X',\n'BFU', 'X',\n'B\
G6', 'X',\n'BGF', 'X',\n'BGG', 'X',\n'BGL', 'X',\n\
'BGN', 'X',\n'BGP', 'X',\n'BGX', 'X',\n'BH4', 'X',\
\n'BHA', 'X',\n'BHC', 'X',\n'BHD', 'D',\n'BHO', 'X\
',\n'BHS', 'X',\n'BIC', 'X',\n'BIN', 'X',\n'BIO', \
'X',\n'BIP', 'X',\n'BIS', 'X',\n'BIZ', 'X',\n'BJH'\
, 'X',\n'BJI', 'X',\n'BJP', 'X',\n'BLA', 'X',\n'BL\
B', 'X',\n'BLE', 'L',\n'BLG', 'P',\n'BLI', 'X',\n'\
BLM', 'X',\n'BLV', 'X',\n'BLY', 'K',\n'BM1', 'X',\\
n'BM2', 'X',\n'BM5', 'X',\n'BM9', 'X',\n'BMA', 'X'\
,\n'BMD', 'X',\n'BME', 'X',\n'BMP', 'X',\n'BMQ', '\
X',\n'BMS', 'X',\n'BMT', 'T',\n'BMU', 'X',\n'BMY',\
 'X',\n'BMZ', 'X',\n'BNA', 'X',\n'BNG', 'X',\n'BNI\
', 'X',\n'BNN', 'F',\n'BNO', 'L',\n'BNS', 'X',\n'B\
NZ', 'X',\n'BO3', 'X',\n'BO4', 'X',\n'BOC', 'X',\n\
'BOG', 'X',\n'BOM', 'X',\n'BOT', 'X',\n'BOX', 'X',\
\n'BOZ', 'X',\n'BPA', 'X',\n'BPB', 'X',\n'BPD', 'X\
',\n'BPG', 'X',\n'BPH', 'X',\n'BPI', 'X',\n'BPJ', \
'X',\n'BPM', 'X',\n'BPN', 'X',\n'BPO', 'X',\n'BPP'\
, 'X',\n'BPT', 'X',\n'BPY', 'X',\n'BRB', 'X',\n'BR\
C', 'X',\n'BRE', 'X',\n'BRI', 'X',\n'BRL', 'X',\n'\
BRM', 'X',\n'BRN', 'X',\n'BRO', 'X',\n'BRS', 'X',\\
n'BRU', 'X',\n'BRZ', 'X',\n'BSB', 'X',\n'BSI', 'X'\
,\n'BSP', 'X',\n'BT1', 'X',\n'BT2', 'X',\n'BT3', '\
X',\n'BTA', 'L',\n'BTB', 'X',\n'BTC', 'C',\n'BTD',\
 'X',\n'BTN', 'X',\n'BTP', 'X',\n'BTR', 'W',\n'BU1\
', 'X',\n'BUA', 'X',\n'BUB', 'X',\n'BUC', 'X',\n'B\
UG', 'X',\n'BUL', 'X',\n'BUM', 'X',\n'BUQ', 'X',\n\
'BUT', 'X',\n'BVD', 'X',\n'BX3', 'X',\n'BYS', 'X',\
\n'BZ1', 'X',\n'BZA', 'X',\n'BZB', 'X',\n'BZC', 'X\
',\n'BZD', 'X',\n'BZF', 'X',\n'BZI', 'X',\n'BZM', \
'X',\n'BZO', 'X',\n'BZP', 'X',\n'BZQ', 'X',\n'BZS'\
, 'X',\n'BZT', 'X',\n'C02', 'X',\n'C11', 'X',\n'C1\
O', 'X',\n'C20', 'X',\n'C24', 'X',\n'C2F', 'X',\n'\
C2O', 'X',\n'C2P', 'X',\n'C3M', 'X',\n'C3P', 'X',\\
n'C3X', 'X',\n'C48', 'X',\n'C4M', 'X',\n'C4X', 'X'\
,\n'C5C', 'X',\n'C5M', 'X',\n'C5P', 'X',\n'C5X', '\
X',\n'C60', 'X',\n'C6C', 'X',\n'C6M', 'X',\n'C78',\
 'X',\n'C8E', 'X',\n'CA3', 'X',\n'CA5', 'X',\n'CAA\
', 'X',\n'CAB', 'X',\n'CAC', 'X',\n'CAD', 'X',\n'C\
AF', 'C',\n'CAG', 'X',\n'CAH', 'X',\n'CAL', 'X',\n\
'CAM', 'X',\n'CAN', 'X',\n'CAO', 'X',\n'CAP', 'X',\
\n'CAQ', 'X',\n'CAR', 'X',\n'CAS', 'C',\n'CAT', 'X\
',\n'CAV', 'X',\n'CAY', 'C',\n'CAZ', 'X',\n'CB3', \
'X',\n'CB4', 'X',\n'CBA', 'X',\n'CBD', 'X',\n'CBG'\
, 'X',\n'CBI', 'X',\n'CBL', 'X',\n'CBM', 'X',\n'CB\
N', 'X',\n'CBO', 'X',\n'CBP', 'X',\n'CBS', 'X',\n'\
CBX', 'X',\n'CBZ', 'X',\n'CC0', 'X',\n'CC1', 'X',\\
n'CCC', 'X',\n'CCH', 'X',\n'CCI', 'X',\n'CCM', 'X'\
,\n'CCN', 'X',\n'CCO', 'X',\n'CCP', 'X',\n'CCR', '\
X',\n'CCS', 'C',\n'CCV', 'X',\n'CCY', 'X',\n'CD1',\
 'X',\n'CDC', 'X',\n'CDE', 'X',\n'CDF', 'X',\n'CDI\
', 'X',\n'CDL', 'X',\n'CDM', 'X',\n'CDP', 'X',\n'C\
DR', 'X',\n'CDU', 'X',\n'CE1', 'X',\n'CEA', 'C',\n\
'CEB', 'X',\n'CEC', 'X',\n'CED', 'X',\n'CEF', 'X',\
\n'CEH', 'X',\n'CEM', 'X',\n'CEO', 'X',\n'CEP', 'X\
',\n'CEQ', 'X',\n'CER', 'X',\n'CES', 'G',\n'CET', \
'X',\n'CFC', 'X',\n'CFF', 'X',\n'CFM', 'X',\n'CFO'\
, 'X',\n'CFP', 'X',\n'CFS', 'X',\n'CFX', 'X',\n'CG\
N', 'X',\n'CGP', 'X',\n'CGS', 'X',\n'CGU', 'E',\n'\
CH2', 'X',\n'CH3', 'X',\n'CHA', 'X',\n'CHB', 'X',\\
n'CHD', 'X',\n'CHF', 'X',\n'CHG', 'G',\n'CHI', 'X'\
,\n'CHN', 'X',\n'CHO', 'X',\n'CHP', 'G',\n'CHR', '\
X',\n'CHS', 'F',\n'CHT', 'X',\n'CHX', 'X',\n'CIC',\
 'X',\n'CIN', 'X',\n'CIP', 'X',\n'CIR', 'X',\n'CIT\
', 'X',\n'CIU', 'X',\n'CKI', 'X',\n'CL1', 'X',\n'C\
L2', 'X',\n'CLA', 'X',\n'CLB', 'A',\n'CLC', 'S',\n\
'CLD', 'A',\n'CLE', 'L',\n'CLF', 'X',\n'CLK', 'S',\
\n'CLL', 'X',\n'CLM', 'X',\n'CLN', 'X',\n'CLO', 'X\
',\n'CLP', 'X',\n'CLQ', 'X',\n'CLR', 'X',\n'CLS', \
'X',\n'CLT', 'X',\n'CLX', 'X',\n'CLY', 'X',\n'CMA'\
, 'R',\n'CMC', 'X',\n'CMD', 'X',\n'CME', 'C',\n'CM\
G', 'X',\n'CMK', 'X',\n'CMN', 'X',\n'CMO', 'X',\n'\
CMP', 'X',\n'CMR', 'X',\n'CMS', 'X',\n'CMT', 'C',\\
n'CMX', 'X',\n'CNA', 'X',\n'CNC', 'X',\n'CND', 'X'\
,\n'CNH', 'X',\n'CNM', 'X',\n'CNN', 'X',\n'CNO', '\
X',\n'CNP', 'X',\n'CO2', 'X',\n'CO3', 'X',\n'CO5',\
 'X',\n'CO8', 'X',\n'COA', 'X',\n'COB', 'X',\n'COC\
', 'X',\n'COD', 'X',\n'COE', 'X',\n'COF', 'X',\n'C\
OH', 'X',\n'COI', 'X',\n'COJ', 'X',\n'COL', 'X',\n\
'COM', 'X',\n'CON', 'X',\n'COP', 'X',\n'COR', 'X',\
\n'COS', 'X',\n'COT', 'X',\n'COY', 'X',\n'CP1', 'G\
',\n'CP2', 'X',\n'CP4', 'X',\n'CPA', 'X',\n'CPB', \
'X',\n'CPC', 'X',\n'CPD', 'X',\n'CPG', 'X',\n'CPH'\
, 'X',\n'CPI', 'X',\n'CPM', 'X',\n'CPN', 'G',\n'CP\
O', 'X',\n'CPP', 'X',\n'CPQ', 'X',\n'CPR', 'X',\n'\
CPS', 'X',\n'CPT', 'X',\n'CPU', 'X',\n'CPV', 'X',\\
n'CPY', 'X',\n'CR1', 'X',\n'CR6', 'X',\n'CRA', 'X'\
,\n'CRB', 'X',\n'CRC', 'X',\n'CRG', 'X',\n'CRH', '\
X',\n'CRO', 'T',\n'CRP', 'X',\n'CRQ', 'X',\n'CRS',\
 'X',\n'CRT', 'X',\n'CRY', 'X',\n'CSA', 'C',\n'CSB\
', 'X',\n'CSD', 'C',\n'CSE', 'C',\n'CSH', 'X',\n'C\
SI', 'X',\n'CSN', 'X',\n'CSO', 'C',\n'CSP', 'C',\n\
'CSR', 'C',\n'CSS', 'C',\n'CST', 'X',\n'CSW', 'C',\
\n'CSX', 'C',\n'CSY', 'X',\n'CSZ', 'C',\n'CT3', 'X\
',\n'CTA', 'X',\n'CTB', 'X',\n'CTC', 'X',\n'CTD', \
'X',\n'CTH', 'T',\n'CTO', 'X',\n'CTP', 'X',\n'CTR'\
, 'X',\n'CTS', 'X',\n'CTT', 'X',\n'CTY', 'X',\n'CT\
Z', 'X',\n'CU1', 'X',\n'CUA', 'X',\n'CUC', 'X',\n'\
CUL', 'X',\n'CUO', 'X',\n'CUZ', 'X',\n'CVI', 'X',\\
n'CXF', 'X',\n'CXL', 'X',\n'CXM', 'M',\n'CXN', 'X'\
,\n'CXP', 'X',\n'CXS', 'X',\n'CY1', 'C',\n'CY3', '\
X',\n'CYB', 'X',\n'CYC', 'X',\n'CYF', 'C',\n'CYG',\
 'C',\n'CYH', 'X',\n'CYL', 'X',\n'CYM', 'C',\n'CYN\
', 'X',\n'CYO', 'X',\n'CYP', 'X',\n'CYQ', 'C',\n'C\
YS', 'C',\n'CYU', 'X',\n'CYY', 'X',\n'CYZ', 'X',\n\
'CZH', 'X',\n'CZZ', 'C',\n'D12', 'X',\n'D13', 'X',\
\n'D16', 'X',\n'D18', 'X',\n'D19', 'X',\n'D1P', 'X\
',\n'D24', 'X',\n'D34', 'X',\n'D35', 'X',\n'D4D', \
'X',\n'D4T', 'X',\n'D6G', 'X',\n'DA2', 'R',\n'DA3'\
, 'X',\n'DA6', 'X',\n'DA7', 'X',\n'DAA', 'X',\n'DA\
B', 'X',\n'DAC', 'X',\n'DAD', 'X',\n'DAE', 'X',\n'\
DAF', 'X',\n'DAG', 'X',\n'DAH', 'A',\n'DAJ', 'X',\\
n'DAK', 'X',\n'DAL', 'A',\n'DAM', 'A',\n'DAN', 'X'\
,\n'DAO', 'X',\n'DAP', 'X',\n'DAQ', 'X',\n'DAR', '\
R',\n'DAS', 'D',\n'DAT', 'X',\n'DAU', 'X',\n'DAV',\
 'X',\n'DBA', 'X',\n'DBD', 'X',\n'DBF', 'X',\n'DBG\
', 'X',\n'DBI', 'X',\n'DBV', 'X',\n'DBY', 'Y',\n'D\
CA', 'X',\n'DCB', 'X',\n'DCE', 'X',\n'DCF', 'X',\n\
'DCG', 'X',\n'DCH', 'X',\n'DCI', 'I',\n'DCL', 'X',\
\n'DCM', 'X',\n'DCP', 'X',\n'DCS', 'X',\n'DCT', 'X\
',\n'DCY', 'C',\n'DCZ', 'X',\n'DDA', 'X',\n'DDB', \
'X',\n'DDC', 'X',\n'DDF', 'X',\n'DDG', 'X',\n'DDH'\
, 'X',\n'DDL', 'X',\n'DDM', 'X',\n'DDO', 'L',\n'DD\
P', 'X',\n'DDQ', 'X',\n'DDT', 'Y',\n'DDU', 'X',\n'\
DEA', 'X',\n'DEB', 'X',\n'DEC', 'X',\n'DEF', 'X',\\
n'DEL', 'X',\n'DEM', 'X',\n'DEN', 'X',\n'DEP', 'X'\
,\n'DEQ', 'X',\n'DES', 'X',\n'DET', 'X',\n'DFC', '\
X',\n'DFG', 'X',\n'DFI', 'X',\n'DFL', 'X',\n'DFO',\
 'X',\n'DFP', 'X',\n'DFR', 'X',\n'DFT', 'X',\n'DFV\
', 'X',\n'DFX', 'X',\n'DG2', 'X',\n'DG3', 'X',\n'D\
G6', 'X',\n'DGA', 'X',\n'DGD', 'X',\n'DGG', 'X',\n\
'DGL', 'E',\n'DGN', 'Q',\n'DGP', 'X',\n'DGT', 'X',\
\n'DGX', 'X',\n'DH2', 'X',\n'DHA', 'A',\n'DHB', 'X\
',\n'DHC', 'X',\n'DHD', 'X',\n'DHE', 'X',\n'DHF', \
'X',\n'DHG', 'X',\n'DHI', 'H',\n'DHL', 'X',\n'DHM'\
, 'X',\n'DHN', 'V',\n'DHP', 'X',\n'DHQ', 'X',\n'DH\
R', 'X',\n'DHS', 'X',\n'DHT', 'X',\n'DHU', 'X',\n'\
DHY', 'X',\n'DHZ', 'X',\n'DI2', 'X',\n'DI3', 'G',\\
n'DI4', 'X',\n'DI5', 'X',\n'DIA', 'X',\n'DIC', 'X'\
,\n'DIF', 'X',\n'DIG', 'X',\n'DII', 'X',\n'DIL', '\
I',\n'DIM', 'X',\n'DIO', 'X',\n'DIP', 'X',\n'DIQ',\
 'X',\n'DIS', 'X',\n'DIT', 'X',\n'DIV', 'V',\n'DIX\
', 'X',\n'DIY', 'X',\n'DKA', 'X',\n'DLA', 'X',\n'D\
LE', 'L',\n'DLF', 'X',\n'DLS', 'K',\n'DLY', 'K',\n\
'DM1', 'X',\n'DM2', 'X',\n'DM3', 'X',\n'DM4', 'X',\
\n'DM5', 'X',\n'DM6', 'X',\n'DM7', 'X',\n'DM8', 'X\
',\n'DM9', 'X',\n'DMA', 'X',\n'DMB', 'X',\n'DMC', \
'X',\n'DMD', 'X',\n'DME', 'X',\n'DMF', 'X',\n'DMG'\
, 'G',\n'DMH', 'N',\n'DMI', 'X',\n'DMJ', 'X',\n'DM\
L', 'X',\n'DMM', 'X',\n'DMN', 'X',\n'DMO', 'X',\n'\
DMP', 'X',\n'DMQ', 'X',\n'DMR', 'X',\n'DMS', 'X',\\
n'DMT', 'X',\n'DMV', 'X',\n'DMY', 'X',\n'DNC', 'X'\
,\n'DND', 'X',\n'DNH', 'X',\n'DNJ', 'X',\n'DNN', '\
X',\n'DNP', 'X',\n'DNQ', 'X',\n'DNR', 'X',\n'DO2',\
 'X',\n'DO3', 'X',\n'DOA', 'X',\n'DOB', 'X',\n'DOC\
', 'X',\n'DOH', 'D',\n'DOM', 'X',\n'DOS', 'X',\n'D\
OX', 'X',\n'DP5', 'X',\n'DP7', 'X',\n'DPA', 'X',\n\
'DPC', 'X',\n'DPD', 'X',\n'DPE', 'X',\n'DPG', 'X',\
\n'DPH', 'F',\n'DPM', 'X',\n'DPN', 'F',\n'DPO', 'X\
',\n'DPP', 'X',\n'DPR', 'P',\n'DPS', 'X',\n'DPT', \
'X',\n'DPX', 'X',\n'DPY', 'X',\n'DPZ', 'X',\n'DQH'\
, 'X',\n'DQN', 'X',\n'DR1', 'X',\n'DRB', 'X',\n'DR\
C', 'X',\n'DRI', 'X',\n'DRP', 'X',\n'DRT', 'X',\n'\
DRU', 'X',\n'DSA', 'X',\n'DSB', 'X',\n'DSC', 'X',\\
n'DSD', 'X',\n'DSE', 'S',\n'DSI', 'X',\n'DSN', 'S'\
,\n'DSP', 'D',\n'DSR', 'X',\n'DSS', 'X',\n'DSX', '\
X',\n'DSY', 'X',\n'DTB', 'X',\n'DTD', 'X',\n'DTH',\
 'T',\n'DTN', 'X',\n'DTO', 'X',\n'DTP', 'X',\n'DTQ\
', 'X',\n'DTR', 'W',\n'DTT', 'X',\n'DTY', 'Y',\n'D\
UD', 'X',\n'DUO', 'X',\n'DUR', 'X',\n'DUT', 'X',\n\
'DVA', 'V',\n'DVR', 'X',\n'DX9', 'X',\n'DXA', 'X',\
\n'DXB', 'X',\n'DXC', 'X',\n'DXG', 'X',\n'DXX', 'X\
',\n'DZF', 'X',\n'E09', 'X',\n'E20', 'X',\n'E2P', \
'X',\n'E3G', 'X',\n'E4N', 'X',\n'E4P', 'X',\n'E64'\
, 'X',\n'E6C', 'X',\n'E96', 'X',\n'E97', 'X',\n'EA\
2', 'X',\n'EAA', 'X',\n'EAP', 'X',\n'EBP', 'X',\n'\
EBW', 'X',\n'ECO', 'X',\n'EDA', 'X',\n'EDC', 'X',\\
n'EDE', 'X',\n'EDO', 'X',\n'EDR', 'X',\n'EEB', 'X'\
,\n'EEE', 'X',\n'EFC', 'X',\n'EFZ', 'X',\n'EG1', '\
X',\n'EG2', 'X',\n'EG3', 'X',\n'EGC', 'X',\n'EGL',\
 'X',\n'EHP', 'A',\n'EIC', 'X',\n'EJT', 'X',\n'ELA\
', 'X',\n'EMB', 'X',\n'EMC', 'X',\n'EMD', 'X',\n'E\
MM', 'X',\n'EMO', 'X',\n'EMP', 'X',\n'EMR', 'X',\n\
'ENA', 'X',\n'ENC', 'X',\n'ENH', 'X',\n'ENO', 'X',\
\n'ENP', 'X',\n'EOA', 'X',\n'EOH', 'X',\n'EOT', 'X\
',\n'EOX', 'X',\n'EPA', 'X',\n'EPE', 'X',\n'EPH', \
'X',\n'EPI', 'X',\n'EPN', 'X',\n'EPO', 'X',\n'EPT'\
, 'X',\n'EPU', 'X',\n'EPX', 'X',\n'EPY', 'X',\n'EQ\
I', 'X',\n'EQP', 'X',\n'EQU', 'X',\n'ERG', 'X',\n'\
ERI', 'X',\n'ERY', 'X',\n'ESC', 'X',\n'ESD', 'X',\\
n'ESI', 'X',\n'ESO', 'X',\n'ESP', 'X',\n'EST', 'X'\
,\n'ESX', 'X',\n'ETA', 'X',\n'ETC', 'X',\n'ETD', '\
X',\n'ETF', 'X',\n'ETH', 'X',\n'ETI', 'X',\n'ETN',\
 'X',\n'ETO', 'X',\n'ETP', 'X',\n'ETR', 'X',\n'ETS\
', 'X',\n'ETY', 'X',\n'EU3', 'X',\n'EUG', 'X',\n'E\
YS', 'C',\n'F09', 'X',\n'F2B', 'X',\n'F3S', 'X',\n\
'F42', 'X',\n'F43', 'X',\n'F4S', 'X',\n'F6B', 'X',\
\n'F6P', 'X',\n'F89', 'X',\n'FA1', 'X',\n'FA5', 'F\
',\n'FAA', 'X',\n'FAB', 'X',\n'FAC', 'X',\n'FAD', \
'X',\n'FAF', 'X',\n'FAG', 'X',\n'FAM', 'X',\n'FAR'\
, 'X',\n'FAS', 'X',\n'FAT', 'X',\n'FBA', 'X',\n'FB\
E', 'X',\n'FBI', 'X',\n'FBP', 'X',\n'FBQ', 'X',\n'\
FBS', 'X',\n'FBT', 'X',\n'FBU', 'X',\n'FCA', 'X',\\
n'FCB', 'X',\n'FCI', 'X',\n'FCN', 'X',\n'FCO', 'X'\
,\n'FCR', 'X',\n'FCT', 'X',\n'FCX', 'X',\n'FCY', '\
C',\n'FD1', 'F',\n'FD2', 'F',\n'FD3', 'F',\n'FD4',\
 'F',\n'FDA', 'X',\n'FDC', 'X',\n'FDI', 'X',\n'FDP\
', 'X',\n'FDS', 'X',\n'FE2', 'X',\n'FEA', 'X',\n'F\
EL', 'X',\n'FEM', 'X',\n'FEN', 'X',\n'FEO', 'X',\n\
'FEP', 'X',\n'FER', 'X',\n'FES', 'X',\n'FFB', 'X',\
\n'FFC', 'X',\n'FFF', 'X',\n'FFO', 'X',\n'FGL', 'G\
',\n'FHB', 'X',\n'FHC', 'X',\n'FHP', 'X',\n'FHU', \
'X',\n'FID', 'X',\n'FII', 'X',\n'FIP', 'X',\n'FK5'\
, 'X',\n'FKA', 'X',\n'FKI', 'X',\n'FKP', 'X',\n'FL\
2', 'X',\n'FL9', 'X',\n'FLA', 'A',\n'FLC', 'X',\n'\
FLD', 'X',\n'FLE', 'L',\n'FLF', 'X',\n'FLO', 'X',\\
n'FLP', 'X',\n'FLT', 'Y',\n'FLU', 'X',\n'FLX', 'X'\
,\n'FM1', 'X',\n'FM2', 'X',\n'FMA', 'X',\n'FMB', '\
X',\n'FMC', 'X',\n'FME', 'M',\n'FMN', 'X',\n'FMP',\
 'X',\n'FMR', 'X',\n'FMS', 'X',\n'FMT', 'X',\n'FNE\
', 'X',\n'FNP', 'X',\n'FNS', 'X',\n'FOC', 'X',\n'F\
OE', 'X',\n'FOG', 'F',\n'FOH', 'X',\n'FOK', 'X',\n\
'FOL', 'X',\n'FON', 'X',\n'FOP', 'X',\n'FOR', 'X',\
\n'FOS', 'X',\n'FPA', 'X',\n'FPC', 'X',\n'FPI', 'X\
',\n'FPO', 'X',\n'FPP', 'X',\n'FPT', 'X',\n'FQP', \
'X',\n'FRA', 'X',\n'FRD', 'F',\n'FRU', 'X',\n'FS3'\
, 'X',\n'FS4', 'X',\n'FSB', 'X',\n'FSO', 'X',\n'FS\
X', 'X',\n'FTC', 'X',\n'FTP', 'X',\n'FTR', 'W',\n'\
FTT', 'X',\n'FTY', 'Y',\n'FUA', 'X',\n'FUC', 'X',\\
n'FUM', 'X',\n'FUP', 'X',\n'FVF', 'X',\n'FXP', 'X'\
,\n'FXV', 'X',\n'FYA', 'F',\n'G16', 'X',\n'G1P', '\
X',\n'G20', 'X',\n'G21', 'X',\n'G23', 'X',\n'G26',\
 'X',\n'G28', 'X',\n'G2F', 'X',\n'G37', 'X',\n'G39\
', 'X',\n'G3H', 'X',\n'G3P', 'X',\n'G4D', 'X',\n'G\
6D', 'X',\n'G6P', 'X',\n'G6Q', 'X',\n'G7M', 'X',\n\
'GA2', 'X',\n'GAA', 'X',\n'GAB', 'X',\n'GAC', 'X',\
\n'GAI', 'X',\n'GAL', 'X',\n'GAM', 'X',\n'GAN', 'X\
',\n'GAO', 'X',\n'GAP', 'X',\n'GAR', 'G',\n'GAS', \
'X',\n'GAT', 'X',\n'GBC', 'X',\n'GBI', 'X',\n'GBP'\
, 'X',\n'GBS', 'X',\n'GBX', 'X',\n'GC4', 'X',\n'GC\
A', 'X',\n'GCD', 'X',\n'GCG', 'G',\n'GCH', 'G',\n'\
GCK', 'X',\n'GCL', 'X',\n'GCM', 'X',\n'GCN', 'X',\\
n'GCO', 'X',\n'GCP', 'X',\n'GCR', 'X',\n'GCS', 'X'\
,\n'GCU', 'X',\n'GD3', 'X',\n'GDB', 'X',\n'GDM', '\
X',\n'GDN', 'X',\n'GDP', 'X',\n'GDS', 'X',\n'GDU',\
 'X',\n'GE1', 'X',\n'GE2', 'X',\n'GE3', 'X',\n'GEA\
', 'X',\n'GEL', 'X',\n'GEM', 'X',\n'GEN', 'X',\n'G\
EP', 'X',\n'GER', 'X',\n'GFP', 'X',\n'GGB', 'X',\n\
'GGL', 'E',\n'GGP', 'X',\n'GHP', 'G',\n'GIP', 'X',\
\n'GIS', 'X',\n'GKR', 'X',\n'GL2', 'X',\n'GL3', 'G\
',\n'GL4', 'X',\n'GL5', 'X',\n'GL7', 'X',\n'GL9', \
'X',\n'GLA', 'X',\n'GLB', 'X',\n'GLC', 'X',\n'GLD'\
, 'X',\n'GLE', 'X',\n'GLF', 'X',\n'GLG', 'X',\n'GL\
H', 'Q',\n'GLI', 'X',\n'GLL', 'X',\n'GLM', 'G',\n'\
GLN', 'Q',\n'GLO', 'X',\n'GLP', 'X',\n'GLR', 'X',\\
n'GLS', 'X',\n'GLT', 'X',\n'GLU', 'E',\n'GLV', 'X'\
,\n'GLW', 'X',\n'GLY', 'G',\n'GLZ', 'X',\n'GM1', '\
X',\n'GMA', 'X',\n'GMC', 'X',\n'GMH', 'X',\n'GMP',\
 'X',\n'GMY', 'X',\n'GN7', 'X',\n'GNA', 'X',\n'GNB\
', 'X',\n'GNH', 'X',\n'GNP', 'X',\n'GNT', 'X',\n'G\
OA', 'X',\n'GOL', 'X',\n'GOX', 'X',\n'GP1', 'X',\n\
'GP3', 'X',\n'GP4', 'X',\n'GP6', 'X',\n'GP8', 'X',\
\n'GPB', 'E',\n'GPC', 'X',\n'GPE', 'X',\n'GPG', 'X\
',\n'GPI', 'X',\n'GPJ', 'X',\n'GPL', 'K',\n'GPM', \
'X',\n'GPN', 'G',\n'GPP', 'X',\n'GPR', 'X',\n'GPS'\
, 'X',\n'GPX', 'X',\n'GR1', 'X',\n'GR3', 'X',\n'GR\
4', 'X',\n'GSA', 'X',\n'GSB', 'X',\n'GSC', 'G',\n'\
GSE', 'S',\n'GSH', 'X',\n'GSP', 'X',\n'GSR', 'X',\\
n'GSS', 'X',\n'GT9', 'C',\n'GTA', 'X',\n'GTB', 'X'\
,\n'GTD', 'X',\n'GTE', 'X',\n'GTH', 'T',\n'GTN', '\
X',\n'GTO', 'X',\n'GTP', 'X',\n'GTR', 'X',\n'GTS',\
 'X',\n'GTT', 'X',\n'GTX', 'X',\n'GTZ', 'X',\n'GU7\
', 'X',\n'GUA', 'X',\n'GUD', 'X',\n'GUM', 'X',\n'G\
UN', 'X',\n'GUP', 'X',\n'GUR', 'X',\n'GW3', 'X',\n\
'GZZ', 'X',\n'H2B', 'X',\n'H2P', 'H',\n'H2S', 'X',\
\n'H2U', 'X',\n'H4B', 'X',\n'H5M', 'P',\n'H5P', 'X\
',\n'HAA', 'X',\n'HAB', 'X',\n'HAC', 'A',\n'HAD', \
'X',\n'HAE', 'X',\n'HAG', 'X',\n'HAI', 'X',\n'HAM'\
, 'X',\n'HAP', 'X',\n'HAQ', 'X',\n'HAR', 'R',\n'HA\
S', 'X',\n'HAV', 'V',\n'HAX', 'X',\n'HAZ', 'X',\n'\
HBA', 'X',\n'HBC', 'X',\n'HBD', 'X',\n'HBI', 'X',\\
n'HBO', 'X',\n'HBU', 'X',\n'HBY', 'X',\n'HC0', 'X'\
,\n'HC1', 'X',\n'HC4', 'X',\n'HCA', 'X',\n'HCC', '\
X',\n'HCI', 'X',\n'HCS', 'X',\n'HDA', 'X',\n'HDD',\
 'X',\n'HDF', 'X',\n'HDN', 'X',\n'HDS', 'X',\n'HDZ\
', 'X',\n'HE1', 'X',\n'HE6', 'X',\n'HEA', 'X',\n'H\
EB', 'X',\n'HEC', 'X',\n'HED', 'X',\n'HEE', 'X',\n\
'HEF', 'X',\n'HEG', 'X',\n'HEM', 'X',\n'HEN', 'X',\
\n'HEO', 'X',\n'HEP', 'X',\n'HEU', 'X',\n'HEV', 'X\
',\n'HEX', 'X',\n'HEZ', 'X',\n'HF1', 'X',\n'HFA', \
'X',\n'HFP', 'X',\n'HGA', 'Q',\n'HGB', 'X',\n'HGC'\
, 'X',\n'HGI', 'X',\n'HGU', 'X',\n'HHO', 'X',\n'HH\
P', 'X',\n'HIB', 'X',\n'HIC', 'H',\n'HII', 'X',\n'\
HIN', 'X',\n'HIO', 'X',\n'HIP', 'H',\n'HIS', 'H',\\
n'HLE', 'X',\n'HLT', 'X',\n'HMA', 'A',\n'HMB', 'X'\
,\n'HMC', 'X',\n'HMD', 'X',\n'HMF', 'A',\n'HMG', '\
X',\n'HMH', 'X',\n'HMI', 'L',\n'HMM', 'X',\n'HMN',\
 'X',\n'HMO', 'X',\n'HMP', 'X',\n'HMR', 'R',\n'HNI\
', 'X',\n'HNP', 'X',\n'HOA', 'X',\n'HOE', 'X',\n'H\
OH', 'X',\n'HOM', 'X',\n'HOP', 'X',\n'HOQ', 'X',\n\
'HP1', 'A',\n'HP2', 'A',\n'HP3', 'X',\n'HPA', 'X',\
\n'HPB', 'X',\n'HPC', 'X',\n'HPD', 'X',\n'HPE', 'A\
',\n'HPG', 'X',\n'HPH', 'F',\n'HPP', 'X',\n'HPQ', \
'F',\n'HPR', 'X',\n'HPT', 'X',\n'HPY', 'X',\n'HQO'\
, 'X',\n'HQQ', 'X',\n'HQU', 'X',\n'HRG', 'R',\n'HR\
I', 'X',\n'HSA', 'X',\n'HSE', 'S',\n'HSF', 'X',\n'\
HSM', 'X',\n'HSO', 'H',\n'HSP', 'X',\n'HT1', 'X',\\
n'HT2', 'X',\n'HTA', 'X',\n'HTL', 'X',\n'HTO', 'X'\
,\n'HTP', 'X',\n'HTR', 'W',\n'HUP', 'X',\n'HUX', '\
X',\n'HV5', 'A',\n'HV7', 'X',\n'HV8', 'X',\n'HXA',\
 'X',\n'HXC', 'X',\n'HXP', 'X',\n'HY1', 'X',\n'HYA\
', 'X',\n'HYB', 'X',\n'HYD', 'X',\n'HYG', 'X',\n'H\
YP', 'P',\n'I06', 'X',\n'I10', 'X',\n'I11', 'X',\n\
'I17', 'X',\n'I2P', 'X',\n'I3N', 'X',\n'I3P', 'X',\
\n'I40', 'X',\n'I48', 'X',\n'I4B', 'X',\n'I52', 'X\
',\n'I5P', 'X',\n'I84', 'G',\n'IAG', 'G',\n'IAS', \
'X',\n'IB2', 'X',\n'IBB', 'X',\n'IBP', 'X',\n'IBR'\
, 'X',\n'IBS', 'X',\n'IBZ', 'X',\n'IC1', 'X',\n'IC\
A', 'X',\n'ICI', 'X',\n'ICL', 'X',\n'ICP', 'X',\n'\
ICT', 'X',\n'ICU', 'X',\n'ID2', 'X',\n'IDC', 'X',\\
n'IDG', 'X',\n'IDH', 'X',\n'IDM', 'X',\n'IDO', 'X'\
,\n'IDP', 'X',\n'IDR', 'X',\n'IDS', 'X',\n'IDT', '\
X',\n'IDU', 'X',\n'IFG', 'X',\n'IFP', 'X',\n'IGL',\
 'X',\n'IGN', 'X',\n'IGP', 'X',\n'IGU', 'X',\n'IH1\
', 'X',\n'IH2', 'X',\n'IH3', 'X',\n'IHB', 'X',\n'I\
HN', 'X',\n'IHP', 'X',\n'IIC', 'X',\n'IIL', 'I',\n\
'IIP', 'X',\n'IK2', 'X',\n'IKT', 'X',\n'ILA', 'I',\
\n'ILE', 'I',\n'ILG', 'X',\n'ILO', 'X',\n'ILX', 'I\
',\n'IM1', 'X',\n'IM2', 'X',\n'IMC', 'X',\n'IMD', \
'X',\n'IME', 'X',\n'IMF', 'X',\n'IMG', 'X',\n'IMH'\
, 'X',\n'IMI', 'X',\n'IML', 'I',\n'IMM', 'X',\n'IM\
N', 'X',\n'IMO', 'X',\n'IMP', 'X',\n'IMR', 'X',\n'\
IMU', 'X',\n'IN0', 'D',\n'IN1', 'R',\n'IN2', 'K',\\
n'IN3', 'L',\n'IN4', 'X',\n'IN5', 'A',\n'IN6', 'L'\
,\n'IN7', 'X',\n'IN8', 'X',\n'IN9', 'X',\n'INA', '\
L',\n'INB', 'X',\n'INC', 'X',\n'IND', 'X',\n'INE',\
 'X',\n'INF', 'F',\n'ING', 'F',\n'INH', 'R',\n'INI\
', 'X',\n'INJ', 'X',\n'INK', 'X',\n'INL', 'X',\n'I\
NM', 'X',\n'INN', 'A',\n'INO', 'X',\n'INP', 'X',\n\
'INQ', 'X',\n'INR', 'X',\n'INS', 'X',\n'INT', 'V',\
\n'INU', 'X',\n'INV', 'X',\n'INW', 'X',\n'INX', 'X\
',\n'INY', 'X',\n'INZ', 'X',\n'IOA', 'X',\n'IOB', \
'X',\n'IOC', 'X',\n'IOD', 'X',\n'IOE', 'X',\n'IOF'\
, 'X',\n'IOH', 'X',\n'IOL', 'X',\n'IOP', 'X',\n'IP\
1', 'X',\n'IP2', 'X',\n'IP3', 'X',\n'IP4', 'X',\n'\
IPA', 'X',\n'IPB', 'X',\n'IPD', 'X',\n'IPG', 'G',\\
n'IPH', 'X',\n'IPL', 'X',\n'IPM', 'X',\n'IPN', 'X'\
,\n'IPO', 'F',\n'IPP', 'X',\n'IPS', 'X',\n'IPT', '\
X',\n'IPU', 'X',\n'IPY', 'A',\n'IQB', 'X',\n'IQP',\
 'X',\n'IQS', 'X',\n'IR3', 'X',\n'IRI', 'X',\n'IRP\
', 'X',\n'ISA', 'X',\n'ISF', 'X',\n'ISO', 'X',\n'I\
SP', 'X',\n'ISQ', 'X',\n'ISU', 'X',\n'ITM', 'X',\n\
'ITP', 'X',\n'ITR', 'W',\n'ITS', 'X',\n'ITU', 'X',\
\n'IU5', 'X',\n'IUM', 'X',\n'IUR', 'X',\n'IVA', 'X\
',\n'IYG', 'G',\n'IYR', 'Y',\n'J77', 'X',\n'J78', \
'X',\n'J80', 'X',\n'JE2', 'X',\n'JEN', 'X',\n'JST'\
, 'X',\n'K21', 'X',\n'KAH', 'X',\n'KAI', 'X',\n'KA\
M', 'X',\n'KAN', 'X',\n'KAP', 'X',\n'KCP', 'X',\n'\
KCX', 'K',\n'KDO', 'X',\n'KEF', 'X',\n'KET', 'X',\\
n'KGR', 'X',\n'KH1', 'X',\n'KIF', 'X',\n'KIV', 'V'\
,\n'KNI', 'X',\n'KPH', 'K',\n'KTH', 'X',\n'KTN', '\
X',\n'KTP', 'X',\n'KWT', 'X',\n'L04', 'X',\n'L1P',\
 'X',\n'L24', 'E',\n'L2P', 'X',\n'L34', 'E',\n'L37\
', 'E',\n'L3P', 'X',\n'L4P', 'X',\n'L75', 'X',\n'L\
AC', 'X',\n'LAD', 'X',\n'LAK', 'X',\n'LAM', 'X',\n\
'LAR', 'X',\n'LAT', 'X',\n'LAX', 'X',\n'LCO', 'X',\
\n'LCP', 'X',\n'LCS', 'X',\n'LDA', 'X',\n'LDO', 'L\
',\n'LDP', 'X',\n'LEA', 'X',\n'LEO', 'X',\n'LEU', \
'L',\n'LG2', 'X',\n'LG6', 'X',\n'LGC', 'X',\n'LGP'\
, 'X',\n'LHG', 'X',\n'LHY', 'F',\n'LI1', 'X',\n'LI\
G', 'X',\n'LIL', 'X',\n'LIM', 'X',\n'LIN', 'X',\n'\
LIO', 'X',\n'LIP', 'X',\n'LLA', 'X',\n'LLP', 'K',\\
n'LLY', 'K',\n'LMG', 'X',\n'LML', 'X',\n'LMT', 'X'\
,\n'LMU', 'X',\n'LMZ', 'X',\n'LNK', 'X',\n'LNL', '\
X',\n'LNO', 'X',\n'LOF', 'X',\n'LOL', 'L',\n'LOM',\
 'X',\n'LOR', 'X',\n'LOS', 'X',\n'LOV', 'L',\n'LOX\
', 'X',\n'LP1', 'X',\n'LP2', 'R',\n'LPA', 'X',\n'L\
PC', 'X',\n'LPF', 'X',\n'LPL', 'X',\n'LPM', 'X',\n\
'LPP', 'X',\n'LRB', 'X',\n'LRU', 'X',\n'LS1', 'X',\
\n'LS2', 'X',\n'LS3', 'X',\n'LS4', 'X',\n'LS5', 'X\
',\n'LTA', 'X',\n'LTL', 'X',\n'LTR', 'W',\n'LUM', \
'X',\n'LVS', 'L',\n'LXC', 'X',\n'LY2', 'X',\n'LY3'\
, 'X',\n'LYA', 'X',\n'LYB', 'X',\n'LYC', 'X',\n'LY\
D', 'X',\n'LYM', 'K',\n'LYN', 'X',\n'LYS', 'K',\n'\
LYT', 'X',\n'LYW', 'X',\n'LYZ', 'K',\n'M1A', 'X',\\
n'M1G', 'X',\n'M2G', 'X',\n'M3L', 'K',\n'M6P', 'X'\
,\n'M6T', 'X',\n'M7G', 'X',\n'MA1', 'X',\n'MA2', '\
X',\n'MA3', 'X',\n'MA4', 'X',\n'MA6', 'X',\n'MAA',\
 'A',\n'MAB', 'X',\n'MAC', 'X',\n'MAE', 'X',\n'MAG\
', 'X',\n'MAH', 'X',\n'MAI', 'R',\n'MAK', 'X',\n'M\
AL', 'X',\n'MAM', 'X',\n'MAN', 'X',\n'MAO', 'X',\n\
'MAP', 'X',\n'MAR', 'X',\n'MAS', 'X',\n'MAT', 'X',\
\n'MAU', 'X',\n'MAZ', 'X',\n'MBA', 'X',\n'MBD', 'X\
',\n'MBG', 'X',\n'MBH', 'X',\n'MBN', 'X',\n'MBO', \
'X',\n'MBR', 'X',\n'MBS', 'X',\n'MBV', 'X',\n'MBZ'\
, 'X',\n'MCA', 'X',\n'MCD', 'X',\n'MCE', 'X',\n'MC\
G', 'G',\n'MCI', 'X',\n'MCN', 'X',\n'MCP', 'X',\n'\
MCT', 'X',\n'MCY', 'X',\n'MD2', 'X',\n'MDA', 'X',\\
n'MDC', 'X',\n'MDG', 'X',\n'MDH', 'X',\n'MDL', 'X'\
,\n'MDM', 'X',\n'MDN', 'X',\n'MDP', 'X',\n'ME6', '\
X',\n'MEB', 'X',\n'MEC', 'X',\n'MEL', 'X',\n'MEN',\
 'N',\n'MEP', 'X',\n'MER', 'X',\n'MES', 'X',\n'MET\
', 'M',\n'MEV', 'X',\n'MF2', 'X',\n'MF3', 'M',\n'M\
FB', 'X',\n'MFD', 'X',\n'MFU', 'X',\n'MG7', 'X',\n\
'MGA', 'X',\n'MGB', 'X',\n'MGD', 'X',\n'MGG', 'R',\
\n'MGL', 'X',\n'MGN', 'Q',\n'MGO', 'X',\n'MGP', 'X\
',\n'MGR', 'X',\n'MGS', 'X',\n'MGT', 'X',\n'MGU', \
'X',\n'MGY', 'G',\n'MHB', 'X',\n'MHF', 'X',\n'MHL'\
, 'L',\n'MHM', 'X',\n'MHO', 'M',\n'MHS', 'H',\n'MH\
Z', 'X',\n'MIA', 'X',\n'MIC', 'X',\n'MID', 'X',\n'\
MIL', 'X',\n'MIM', 'X',\n'MIN', 'G',\n'MIP', 'X',\\
n'MIS', 'S',\n'MIT', 'X',\n'MJI', 'X',\n'MK1', 'X'\
,\n'MKC', 'X',\n'MLA', 'X',\n'MLC', 'X',\n'MLE', '\
L',\n'MLN', 'X',\n'MLT', 'X',\n'MLY', 'K',\n'MLZ',\
 'K',\n'MM3', 'X',\n'MM4', 'X',\n'MMA', 'X',\n'MMC\
', 'X',\n'MME', 'M',\n'MMO', 'R',\n'MMP', 'X',\n'M\
MQ', 'X',\n'MMT', 'X',\n'MN1', 'X',\n'MN2', 'X',\n\
'MN3', 'X',\n'MN5', 'X',\n'MN7', 'X',\n'MN8', 'X',\
\n'MNA', 'X',\n'MNB', 'X',\n'MNC', 'X',\n'MNG', 'X\
',\n'MNL', 'L',\n'MNO', 'X',\n'MNP', 'X',\n'MNQ', \
'X',\n'MNS', 'X',\n'MNT', 'X',\n'MNV', 'V',\n'MO1'\
, 'X',\n'MO2', 'X',\n'MO3', 'X',\n'MO4', 'X',\n'MO\
5', 'X',\n'MO6', 'X',\n'MOA', 'X',\n'MOB', 'X',\n'\
MOC', 'X',\n'MOE', 'X',\n'MOG', 'X',\n'MOH', 'X',\\
n'MOL', 'X',\n'MOO', 'X',\n'MOP', 'X',\n'MOR', 'X'\
,\n'MOS', 'X',\n'MOT', 'X',\n'MOX', 'X',\n'MP1', '\
X',\n'MP3', 'X',\n'MPA', 'X',\n'MPB', 'X',\n'MPC',\
 'X',\n'MPD', 'X',\n'MPG', 'X',\n'MPH', 'M',\n'MPI\
', 'X',\n'MPJ', 'M',\n'MPL', 'X',\n'MPN', 'X',\n'M\
PO', 'X',\n'MPP', 'X',\n'MPQ', 'G',\n'MPR', 'X',\n\
'MPS', 'X',\n'MQ0', 'X',\n'MQ7', 'X',\n'MQ8', 'X',\
\n'MQ9', 'X',\n'MQI', 'X',\n'MR2', 'X',\n'MRC', 'X\
',\n'MRM', 'X',\n'MRP', 'X',\n'MS2', 'X',\n'MSA', \
'X',\n'MSB', 'X',\n'MSD', 'X',\n'MSE', 'M',\n'MSF'\
, 'X',\n'MSI', 'X',\n'MSO', 'M',\n'MSQ', 'X',\n'MS\
T', 'X',\n'MSU', 'X',\n'MTA', 'X',\n'MTB', 'X',\n'\
MTC', 'X',\n'MTD', 'X',\n'MTE', 'X',\n'MTF', 'X',\\
n'MTG', 'X',\n'MTO', 'X',\n'MTS', 'X',\n'MTT', 'X'\
,\n'MTX', 'X',\n'MTY', 'Y',\n'MUG', 'X',\n'MUP', '\
X',\n'MUR', 'X',\n'MVA', 'V',\n'MW1', 'X',\n'MW2',\
 'X',\n'MXA', 'X',\n'MXY', 'X',\n'MYA', 'X',\n'MYC\
', 'X',\n'MYG', 'X',\n'MYR', 'X',\n'MYS', 'X',\n'M\
YT', 'X',\n'MZM', 'X',\n'N1T', 'X',\n'N25', 'X',\n\
'N2B', 'X',\n'N3T', 'X',\n'N4B', 'X',\n'NA2', 'X',\
\n'NA5', 'X',\n'NA6', 'X',\n'NAA', 'X',\n'NAB', 'X\
',\n'NAC', 'X',\n'NAD', 'X',\n'NAE', 'X',\n'NAF', \
'X',\n'NAG', 'X',\n'NAH', 'X',\n'NAI', 'X',\n'NAL'\
, 'A',\n'NAM', 'A',\n'NAN', 'X',\n'NAO', 'X',\n'NA\
P', 'X',\n'NAQ', 'X',\n'NAR', 'X',\n'NAS', 'X',\n'\
NAU', 'X',\n'NAV', 'X',\n'NAW', 'X',\n'NAX', 'X',\\
n'NAY', 'X',\n'NBA', 'X',\n'NBD', 'X',\n'NBE', 'X'\
,\n'NBG', 'X',\n'NBN', 'X',\n'NBP', 'X',\n'NBS', '\
X',\n'NBU', 'X',\n'NCA', 'X',\n'NCB', 'A',\n'NCD',\
 'X',\n'NCH', 'X',\n'NCM', 'X',\n'NCN', 'X',\n'NCO\
', 'X',\n'NCR', 'X',\n'NCS', 'X',\n'ND4', 'X',\n'N\
DA', 'X',\n'NDC', 'X',\n'NDD', 'X',\n'NDO', 'X',\n\
'NDP', 'X',\n'NDT', 'X',\n'NEA', 'X',\n'NEB', 'X',\
\n'NED', 'X',\n'NEM', 'H',\n'NEN', 'X',\n'NEO', 'X\
',\n'NEP', 'H',\n'NEQ', 'X',\n'NES', 'X',\n'NET', \
'X',\n'NEV', 'X',\n'NFA', 'F',\n'NFE', 'X',\n'NFG'\
, 'X',\n'NFP', 'X',\n'NFS', 'X',\n'NG6', 'X',\n'NG\
A', 'X',\n'NGL', 'X',\n'NGM', 'X',\n'NGO', 'X',\n'\
NGP', 'X',\n'NGT', 'X',\n'NGU', 'X',\n'NH2', 'X',\\
n'NH3', 'X',\n'NH4', 'X',\n'NHD', 'X',\n'NHE', 'X'\
,\n'NHM', 'X',\n'NHP', 'X',\n'NHR', 'X',\n'NHS', '\
X',\n'NI1', 'X',\n'NI2', 'X',\n'NIC', 'X',\n'NID',\
 'X',\n'NIK', 'X',\n'NIO', 'X',\n'NIP', 'X',\n'NIT\
', 'X',\n'NIU', 'X',\n'NIY', 'Y',\n'NLA', 'X',\n'N\
LE', 'L',\n'NLG', 'X',\n'NLN', 'L',\n'NLP', 'L',\n\
'NM1', 'X',\n'NMA', 'A',\n'NMB', 'X',\n'NMC', 'G',\
\n'NMD', 'X',\n'NME', 'X',\n'NMN', 'X',\n'NMO', 'X\
',\n'NMQ', 'X',\n'NMX', 'X',\n'NMY', 'X',\n'NNH', \
'R',\n'NNO', 'X',\n'NO2', 'X',\n'NO3', 'X',\n'NOA'\
, 'X',\n'NOD', 'X',\n'NOJ', 'X',\n'NON', 'X',\n'NO\
P', 'X',\n'NOR', 'X',\n'NOS', 'X',\n'NOV', 'X',\n'\
NOX', 'X',\n'NP3', 'X',\n'NPA', 'X',\n'NPC', 'X',\\
n'NPD', 'X',\n'NPE', 'X',\n'NPF', 'X',\n'NPH', 'C'\
,\n'NPI', 'X',\n'NPL', 'X',\n'NPN', 'X',\n'NPO', '\
X',\n'NPP', 'X',\n'NPT', 'X',\n'NPY', 'X',\n'NRG',\
 'R',\n'NRI', 'X',\n'NS1', 'X',\n'NS5', 'X',\n'NSP\
', 'X',\n'NTA', 'X',\n'NTB', 'X',\n'NTC', 'X',\n'N\
TH', 'X',\n'NTM', 'X',\n'NTP', 'X',\n'NTS', 'X',\n\
'NTU', 'X',\n'NTZ', 'X',\n'NU1', 'X',\n'NVA', 'V',\
\n'NVI', 'X',\n'NVP', 'X',\n'NW1', 'X',\n'NYP', 'X\
',\n'O4M', 'X',\n'OAA', 'X',\n'OAI', 'X',\n'OAP', \
'X',\n'OAR', 'X',\n'OAS', 'S',\n'OBA', 'X',\n'OBN'\
, 'X',\n'OC1', 'X',\n'OC2', 'X',\n'OC3', 'X',\n'OC\
4', 'X',\n'OC5', 'X',\n'OC6', 'X',\n'OC7', 'X',\n'\
OCL', 'X',\n'OCM', 'X',\n'OCN', 'X',\n'OCO', 'X',\\
n'OCP', 'X',\n'OCS', 'C',\n'OCT', 'X',\n'OCV', 'K'\
,\n'OCY', 'C',\n'ODA', 'X',\n'ODS', 'X',\n'OES', '\
X',\n'OET', 'X',\n'OF1', 'X',\n'OF2', 'X',\n'OF3',\
 'X',\n'OFL', 'X',\n'OFO', 'X',\n'OHE', 'X',\n'OHO\
', 'X',\n'OHT', 'X',\n'OIC', 'X',\n'OIP', 'X',\n'O\
KA', 'X',\n'OLA', 'X',\n'OLE', 'X',\n'OLI', 'X',\n\
'OLO', 'X',\n'OMB', 'X',\n'OMC', 'X',\n'OMD', 'X',\
\n'OME', 'X',\n'OMG', 'X',\n'OMP', 'X',\n'OMT', 'M\
',\n'OMU', 'X',\n'ONE', 'X',\n'ONL', 'L',\n'ONP', \
'X',\n'OPA', 'X',\n'OPD', 'X',\n'OPE', 'X',\n'OPG'\
, 'X',\n'OPH', 'X',\n'OPN', 'X',\n'OPP', 'X',\n'OP\
R', 'R',\n'ORN', 'X',\n'ORO', 'X',\n'ORP', 'X',\n'\
OSB', 'X',\n'OSS', 'X',\n'OTA', 'X',\n'OTB', 'X',\\
n'OTE', 'X',\n'OTG', 'X',\n'OUT', 'X',\n'OVA', 'X'\
,\n'OWQ', 'X',\n'OXA', 'X',\n'OXE', 'X',\n'OXI', '\
X',\n'OXL', 'X',\n'OXM', 'X',\n'OXN', 'X',\n'OXO',\
 'X',\n'OXP', 'X',\n'OXS', 'X',\n'OXY', 'X',\n'P11\
', 'A',\n'P24', 'X',\n'P28', 'X',\n'P2P', 'X',\n'P\
2U', 'X',\n'P3M', 'X',\n'P4C', 'X',\n'P4P', 'X',\n\
'P5P', 'X',\n'P6G', 'X',\n'PA1', 'X',\n'PA2', 'X',\
\n'PA3', 'X',\n'PA4', 'X',\n'PA5', 'X',\n'PAA', 'X\
',\n'PAB', 'X',\n'PAC', 'X',\n'PAD', 'X',\n'PAE', \
'X',\n'PAG', 'X',\n'PAH', 'X',\n'PAI', 'X',\n'PAL'\
, 'D',\n'PAM', 'X',\n'PAN', 'X',\n'PAO', 'X',\n'PA\
P', 'A',\n'PAQ', 'F',\n'PAR', 'X',\n'PAS', 'X',\n'\
PAT', 'W',\n'PBA', 'X',\n'PBB', 'X',\n'PBC', 'X',\\
n'PBF', 'F',\n'PBG', 'X',\n'PBI', 'X',\n'PBM', 'X'\
,\n'PBN', 'X',\n'PBP', 'X',\n'PBR', 'X',\n'PBZ', '\
X',\n'PC2', 'X',\n'PCA', 'E',\n'PCB', 'X',\n'PCD',\
 'X',\n'PCE', 'X',\n'PCG', 'X',\n'PCH', 'X',\n'PCL\
', 'X',\n'PCM', 'X',\n'PCP', 'X',\n'PCR', 'X',\n'P\
CS', 'X',\n'PCU', 'X',\n'PCV', 'X',\n'PCY', 'X',\n\
'PD1', 'X',\n'PDA', 'X',\n'PDC', 'X',\n'PDD', 'A',\
\n'PDE', 'A',\n'PDI', 'X',\n'PDL', 'A',\n'PDN', 'X\
',\n'PDO', 'X',\n'PDP', 'X',\n'PDT', 'X',\n'PDU', \
'X',\n'PE2', 'X',\n'PE6', 'X',\n'PEA', 'X',\n'PEB'\
, 'X',\n'PEC', 'X',\n'PED', 'X',\n'PEE', 'X',\n'PE\
F', 'X',\n'PEG', 'X',\n'PEL', 'X',\n'PEO', 'X',\n'\
PEP', 'X',\n'PEQ', 'X',\n'PER', 'X',\n'PET', 'X',\\
n'PFB', 'X',\n'PFC', 'X',\n'PFG', 'X',\n'PFL', 'X'\
,\n'PFM', 'X',\n'PFZ', 'X',\n'PG4', 'X',\n'PG5', '\
X',\n'PG6', 'X',\n'PGA', 'X',\n'PGC', 'X',\n'PGD',\
 'X',\n'PGE', 'X',\n'PGG', 'G',\n'PGH', 'X',\n'PGL\
', 'X',\n'PGO', 'X',\n'PGP', 'X',\n'PGQ', 'X',\n'P\
GR', 'X',\n'PGS', 'X',\n'PGU', 'X',\n'PGX', 'X',\n\
'PGY', 'G',\n'PH1', 'X',\n'PH2', 'X',\n'PH3', 'X',\
\n'PHA', 'F',\n'PHB', 'X',\n'PHC', 'X',\n'PHD', 'X\
',\n'PHE', 'F',\n'PHG', 'X',\n'PHH', 'X',\n'PHI', \
'F',\n'PHL', 'F',\n'PHM', 'X',\n'PHN', 'X',\n'PHO'\
, 'X',\n'PHP', 'X',\n'PHQ', 'X',\n'PHS', 'H',\n'PH\
T', 'X',\n'PHW', 'P',\n'PHY', 'X',\n'PI1', 'X',\n'\
PI2', 'X',\n'PI3', 'X',\n'PI4', 'X',\n'PI5', 'X',\\
n'PI6', 'X',\n'PI7', 'X',\n'PI8', 'X',\n'PI9', 'X'\
,\n'PIA', 'X',\n'PIB', 'X',\n'PIC', 'X',\n'PID', '\
X',\n'PIG', 'X',\n'PIH', 'X',\n'PIM', 'X',\n'PIN',\
 'X',\n'PIO', 'X',\n'PIP', 'X',\n'PIQ', 'X',\n'PIR\
', 'X',\n'PIV', 'X',\n'PKF', 'X',\n'PL1', 'X',\n'P\
L9', 'X',\n'PLA', 'D',\n'PLC', 'X',\n'PLE', 'L',\n\
'PLG', 'G',\n'PLH', 'X',\n'PLM', 'X',\n'PLP', 'X',\
\n'PLS', 'S',\n'PLT', 'W',\n'PLU', 'L',\n'PLY', 'X\
',\n'PMA', 'X',\n'PMB', 'X',\n'PMC', 'X',\n'PME', \
'F',\n'PML', 'X',\n'PMM', 'X',\n'PMO', 'X',\n'PMP'\
, 'X',\n'PMS', 'X',\n'PMY', 'X',\n'PN2', 'X',\n'PN\
A', 'X',\n'PNB', 'X',\n'PNC', 'G',\n'PND', 'X',\n'\
PNE', 'A',\n'PNF', 'X',\n'PNG', 'X',\n'PNI', 'X',\\
n'PNL', 'X',\n'PNM', 'X',\n'PNN', 'X',\n'PNO', 'X'\
,\n'PNP', 'X',\n'PNQ', 'X',\n'PNS', 'X',\n'PNT', '\
X',\n'PNU', 'X',\n'PO2', 'X',\n'PO4', 'X',\n'POB',\
 'X',\n'POC', 'X',\n'POL', 'X',\n'POM', 'P',\n'PON\
', 'X',\n'POP', 'X',\n'POR', 'X',\n'POS', 'X',\n'P\
P1', 'X',\n'PP2', 'X',\n'PP3', 'A',\n'PP4', 'X',\n\
'PP5', 'X',\n'PP6', 'X',\n'PP7', 'X',\n'PP8', 'N',\
\n'PP9', 'X',\n'PPB', 'X',\n'PPC', 'X',\n'PPD', 'X\
',\n'PPE', 'E',\n'PPG', 'X',\n'PPH', 'F',\n'PPI', \
'X',\n'PPJ', 'V',\n'PPL', 'X',\n'PPM', 'X',\n'PPN'\
, 'A',\n'PPO', 'X',\n'PPP', 'X',\n'PPQ', 'X',\n'PP\
R', 'X',\n'PPS', 'X',\n'PPT', 'X',\n'PPU', 'X',\n'\
PPX', 'F',\n'PPY', 'X',\n'PPZ', 'X',\n'PQ0', 'X',\\
n'PQN', 'X',\n'PQQ', 'X',\n'PR1', 'X',\n'PR2', 'X'\
,\n'PR3', 'X',\n'PRA', 'X',\n'PRB', 'X',\n'PRC', '\
X',\n'PRD', 'X',\n'PRE', 'X',\n'PRF', 'X',\n'PRH',\
 'X',\n'PRI', 'P',\n'PRL', 'X',\n'PRN', 'X',\n'PRO\
', 'P',\n'PRP', 'X',\n'PRR', 'A',\n'PRS', 'P',\n'P\
RZ', 'X',\n'PS0', 'X',\n'PSA', 'X',\n'PSD', 'X',\n\
'PSE', 'X',\n'PSF', 'S',\n'PSG', 'X',\n'PSI', 'X',\
\n'PSO', 'X',\n'PSQ', 'X',\n'PSS', 'X',\n'PST', 'X\
',\n'PSU', 'X',\n'PT1', 'X',\n'PT3', 'X',\n'PTA', \
'X',\n'PTC', 'X',\n'PTD', 'X',\n'PTE', 'X',\n'PTH'\
, 'Y',\n'PTL', 'X',\n'PTM', 'Y',\n'PTN', 'X',\n'PT\
O', 'X',\n'PTP', 'X',\n'PTR', 'Y',\n'PTS', 'X',\n'\
PTT', 'X',\n'PTU', 'X',\n'PTY', 'X',\n'PUA', 'X',\\
n'PUB', 'X',\n'PUR', 'X',\n'PUT', 'X',\n'PVA', 'X'\
,\n'PVB', 'X',\n'PVH', 'H',\n'PVL', 'X',\n'PXA', '\
X',\n'PXF', 'X',\n'PXG', 'X',\n'PXP', 'X',\n'PXY',\
 'X',\n'PXZ', 'X',\n'PY2', 'X',\n'PY4', 'X',\n'PY5\
', 'X',\n'PY6', 'X',\n'PYA', 'A',\n'PYC', 'X',\n'P\
YD', 'X',\n'PYE', 'X',\n'PYL', 'X',\n'PYM', 'X',\n\
'PYO', 'X',\n'PYP', 'X',\n'PYQ', 'X',\n'PYR', 'X',\
\n'PYS', 'X',\n'PYT', 'X',\n'PYX', 'X',\n'PYY', 'X\
',\n'PYZ', 'X',\n'PZQ', 'X',\n'Q82', 'X',\n'QNC', \
'X',\n'QND', 'X',\n'QSI', 'Q',\n'QTR', 'X',\n'QUA'\
, 'X',\n'QUE', 'X',\n'QUI', 'X',\n'QUO', 'X',\n'R1\
1', 'X',\n'R12', 'X',\n'R13', 'X',\n'R18', 'X',\n'\
R1P', 'X',\n'R56', 'X',\n'R5P', 'X',\n'RA2', 'X',\\
n'RAD', 'X',\n'RAI', 'X',\n'RAL', 'X',\n'RAM', 'X'\
,\n'RAN', 'X',\n'RAP', 'X',\n'RBF', 'X',\n'RBU', '\
X',\n'RCA', 'X',\n'RCL', 'X',\n'RCO', 'X',\n'RDC',\
 'X',\n'RDF', 'W',\n'RE9', 'X',\n'REA', 'X',\n'RED\
', 'K',\n'REO', 'X',\n'REP', 'X',\n'RET', 'X',\n'R\
FA', 'X',\n'RFB', 'X',\n'RFL', 'X',\n'RFP', 'X',\n\
'RG1', 'X',\n'RGS', 'X',\n'RH1', 'X',\n'RHA', 'X',\
\n'RHC', 'X',\n'RHD', 'X',\n'RHM', 'X',\n'RHO', 'X\
',\n'RHQ', 'X',\n'RHS', 'X',\n'RIA', 'X',\n'RIB', \
'X',\n'RIC', 'X',\n'RIF', 'X',\n'RIN', 'X',\n'RIP'\
, 'X',\n'RIT', 'X',\n'RMB', 'X',\n'RMN', 'X',\n'RM\
P', 'X',\n'RNG', 'X',\n'RNS', 'X',\n'RNT', 'X',\n'\
RO2', 'X',\n'RO4', 'X',\n'ROC', 'N',\n'ROI', 'X',\\
n'ROM', 'X',\n'RON', 'V',\n'ROP', 'X',\n'ROS', 'X'\
,\n'ROX', 'X',\n'RPA', 'X',\n'RPD', 'X',\n'RPH', '\
X',\n'RPL', 'X',\n'RPP', 'X',\n'RPR', 'X',\n'RPX',\
 'X',\n'RQ3', 'X',\n'RR1', 'X',\n'RR6', 'X',\n'RRS\
', 'X',\n'RS1', 'X',\n'RS2', 'X',\n'RS7', 'X',\n'R\
SS', 'X',\n'RTA', 'X',\n'RTB', 'X',\n'RTC', 'X',\n\
'RTL', 'X',\n'RUB', 'X',\n'RUN', 'X',\n'RWJ', 'X',\
\n'RXP', 'X',\n'S02', 'X',\n'S11', 'X',\n'S1H', 'S\
',\n'S27', 'X',\n'S2C', 'C',\n'S3P', 'X',\n'S4U', \
'X',\n'S57', 'X',\n'S58', 'X',\n'S5H', 'X',\n'S6G'\
, 'X',\n'S80', 'X',\n'SAA', 'X',\n'SAB', 'X',\n'SA\
C', 'S',\n'SAD', 'X',\n'SAE', 'X',\n'SAF', 'X',\n'\
SAH', 'C',\n'SAI', 'C',\n'SAL', 'X',\n'SAM', 'M',\\
n'SAN', 'X',\n'SAP', 'X',\n'SAR', 'X',\n'SAS', 'X'\
,\n'SB1', 'X',\n'SB2', 'X',\n'SB3', 'X',\n'SB4', '\
X',\n'SB5', 'X',\n'SB6', 'X',\n'SBA', 'L',\n'SBB',\
 'X',\n'SBD', 'A',\n'SBI', 'X',\n'SBL', 'A',\n'SBN\
', 'X',\n'SBO', 'X',\n'SBR', 'X',\n'SBS', 'X',\n'S\
BT', 'X',\n'SBU', 'X',\n'SBX', 'X',\n'SC4', 'X',\n\
'SCA', 'X',\n'SCC', 'X',\n'SCD', 'X',\n'SCH', 'C',\
\n'SCI', 'X',\n'SCL', 'X',\n'SCM', 'X',\n'SCN', 'X\
',\n'SCO', 'X',\n'SCP', 'S',\n'SCR', 'X',\n'SCS', \
'X',\n'SCV', 'C',\n'SCY', 'C',\n'SD8', 'X',\n'SDK'\
, 'X',\n'SDZ', 'X',\n'SE4', 'X',\n'SEA', 'X',\n'SE\
B', 'S',\n'SEC', 'X',\n'SEG', 'A',\n'SEI', 'X',\n'\
SEL', 'S',\n'SEM', 'X',\n'SEO', 'X',\n'SEP', 'S',\\
n'SER', 'S',\n'SES', 'X',\n'SET', 'S',\n'SEU', 'X'\
,\n'SF4', 'X',\n'SFG', 'X',\n'SFN', 'X',\n'SFO', '\
X',\n'SGA', 'X',\n'SGC', 'X',\n'SGL', 'X',\n'SGM',\
 'X',\n'SGN', 'X',\n'SGP', 'X',\n'SHA', 'X',\n'SHC\
', 'X',\n'SHF', 'X',\n'SHH', 'X',\n'SHP', 'G',\n'S\
HR', 'E',\n'SHT', 'T',\n'SHU', 'X',\n'SI2', 'X',\n\
'SIA', 'X',\n'SIF', 'X',\n'SIG', 'X',\n'SIH', 'X',\
\n'SIM', 'X',\n'SIN', 'X',\n'SKD', 'X',\n'SKF', 'X\
',\n'SLB', 'X',\n'SLE', 'X',\n'SLZ', 'K',\n'SMA', \
'X',\n'SMC', 'C',\n'SME', 'M',\n'SML', 'X',\n'SMM'\
, 'M',\n'SMN', 'X',\n'SMP', 'X',\n'SMS', 'X',\n'SN\
1', 'X',\n'SN6', 'X',\n'SN7', 'X',\n'SNC', 'C',\n'\
SNN', 'X',\n'SNP', 'X',\n'SO1', 'X',\n'SO2', 'X',\\
n'SO3', 'X',\n'SO4', 'X',\n'SOA', 'X',\n'SOC', 'C'\
,\n'SOM', 'X',\n'SOR', 'X',\n'SOT', 'X',\n'SOX', '\
X',\n'SPA', 'X',\n'SPB', 'X',\n'SPC', 'X',\n'SPD',\
 'X',\n'SPE', 'X',\n'SPG', 'X',\n'SPH', 'X',\n'SPI\
', 'X',\n'SPK', 'X',\n'SPM', 'X',\n'SPN', 'X',\n'S\
PO', 'X',\n'SPP', 'X',\n'SPS', 'X',\n'SPY', 'X',\n\
'SQU', 'X',\n'SRA', 'X',\n'SRB', 'X',\n'SRD', 'X',\
\n'SRL', 'X',\n'SRM', 'X',\n'SRS', 'X',\n'SRY', 'X\
',\n'SSA', 'X',\n'SSB', 'X',\n'SSG', 'X',\n'SSP', \
'X',\n'ST1', 'X',\n'ST2', 'X',\n'ST3', 'X',\n'ST4'\
, 'X',\n'ST5', 'X',\n'ST6', 'X',\n'STA', 'X',\n'ST\
B', 'X',\n'STE', 'X',\n'STG', 'X',\n'STI', 'X',\n'\
STL', 'X',\n'STN', 'X',\n'STO', 'X',\n'STP', 'X',\\
n'STR', 'X',\n'STU', 'X',\n'STY', 'Y',\n'SU1', 'X'\
,\n'SU2', 'X',\n'SUC', 'X',\n'SUI', 'X',\n'SUL', '\
X',\n'SUR', 'X',\n'SVA', 'S',\n'SWA', 'X',\n'T16',\
 'X',\n'T19', 'X',\n'T23', 'X',\n'T29', 'X',\n'T33\
', 'X',\n'T3P', 'X',\n'T42', 'A',\n'T44', 'X',\n'T\
5A', 'X',\n'T6A', 'T',\n'T6P', 'X',\n'T80', 'X',\n\
'T87', 'X',\n'TA1', 'X',\n'TAA', 'X',\n'TAB', 'X',\
\n'TAC', 'X',\n'TAD', 'X',\n'TAF', 'X',\n'TAM', 'X\
',\n'TAP', 'X',\n'TAR', 'X',\n'TAS', 'X',\n'TAU', \
'X',\n'TAX', 'X',\n'TAZ', 'X',\n'TB9', 'X',\n'TBA'\
, 'X',\n'TBD', 'X',\n'TBG', 'G',\n'TBH', 'X',\n'TB\
M', 'T',\n'TBO', 'X',\n'TBP', 'X',\n'TBR', 'X',\n'\
TBS', 'X',\n'TBT', 'X',\n'TBU', 'X',\n'TBZ', 'X',\\
n'TC4', 'X',\n'TCA', 'X',\n'TCB', 'X',\n'TCH', 'X'\
,\n'TCK', 'X',\n'TCL', 'X',\n'TCM', 'X',\n'TCN', '\
X',\n'TCP', 'X',\n'TCR', 'W',\n'TCS', 'X',\n'TCZ',\
 'X',\n'TDA', 'X',\n'TDB', 'X',\n'TDG', 'X',\n'TDP\
', 'X',\n'TDR', 'X',\n'TDX', 'X',\n'TEA', 'X',\n'T\
EM', 'X',\n'TEN', 'X',\n'TEO', 'X',\n'TEP', 'X',\n\
'TER', 'X',\n'TES', 'X',\n'TET', 'X',\n'TFA', 'X',\
\n'TFB', 'X',\n'TFH', 'X',\n'TFI', 'X',\n'TFK', 'X\
',\n'TFP', 'X',\n'THA', 'X',\n'THB', 'X',\n'THC', \
'T',\n'THD', 'X',\n'THE', 'X',\n'THF', 'X',\n'THJ'\
, 'X',\n'THK', 'X',\n'THM', 'X',\n'THN', 'X',\n'TH\
O', 'T',\n'THP', 'X',\n'THQ', 'X',\n'THR', 'T',\n'\
THS', 'X',\n'THT', 'X',\n'THU', 'X',\n'THX', 'X',\\
n'THZ', 'X',\n'TI1', 'X',\n'TI2', 'X',\n'TI3', 'P'\
,\n'TIA', 'X',\n'TIH', 'A',\n'TK4', 'X',\n'TLA', '\
X',\n'TLC', 'X',\n'TLM', 'X',\n'TLN', 'X',\n'TLX',\
 'X',\n'TM5', 'X',\n'TM6', 'X',\n'TMA', 'X',\n'TMB\
', 'T',\n'TMC', 'X',\n'TMD', 'T',\n'TME', 'X',\n'T\
MF', 'X',\n'TML', 'K',\n'TMM', 'X',\n'TMN', 'X',\n\
'TMP', 'X',\n'TMQ', 'X',\n'TMR', 'X',\n'TMT', 'X',\
\n'TMZ', 'X',\n'TNB', 'C',\n'TND', 'X',\n'TNK', 'X\
',\n'TNP', 'X',\n'TNT', 'X',\n'TOA', 'X',\n'TOB', \
'X',\n'TOC', 'X',\n'TOL', 'X',\n'TOP', 'X',\n'TOS'\
, 'X',\n'TOT', 'X',\n'TP1', 'G',\n'TP2', 'P',\n'TP\
3', 'E',\n'TP4', 'E',\n'TP7', 'T',\n'TPA', 'X',\n'\
TPE', 'X',\n'TPF', 'X',\n'TPI', 'X',\n'TPL', 'W',\\
n'TPM', 'X',\n'TPN', 'G',\n'TPO', 'T',\n'TPP', 'X'\
,\n'TPQ', 'A',\n'TPR', 'P',\n'TPS', 'X',\n'TPT', '\
X',\n'TPV', 'X',\n'TPX', 'X',\n'TPY', 'X',\n'TQ3',\
 'X',\n'TQ4', 'X',\n'TQ5', 'X',\n'TQ6', 'X',\n'TR1\
', 'X',\n'TRA', 'X',\n'TRB', 'X',\n'TRC', 'X',\n'T\
RD', 'X',\n'TRE', 'X',\n'TRF', 'W',\n'TRG', 'K',\n\
'TRH', 'X',\n'TRI', 'X',\n'TRJ', 'X',\n'TRM', 'X',\
\n'TRN', 'W',\n'TRO', 'W',\n'TRP', 'W',\n'TRQ', 'X\
',\n'TRS', 'X',\n'TRX', 'W',\n'TRZ', 'X',\n'TS2', \
'X',\n'TS3', 'X',\n'TS4', 'X',\n'TS5', 'X',\n'TSA'\
, 'X',\n'TSB', 'X',\n'TSI', 'X',\n'TSM', 'X',\n'TS\
N', 'X',\n'TSP', 'X',\n'TSU', 'X',\n'TTA', 'X',\n'\
TTE', 'X',\n'TTN', 'X',\n'TTO', 'X',\n'TTP', 'X',\\
n'TTX', 'X',\n'TXL', 'X',\n'TYA', 'Y',\n'TYB', 'Y'\
,\n'TYD', 'X',\n'TYI', 'Y',\n'TYL', 'X',\n'TYM', '\
W',\n'TYN', 'Y',\n'TYQ', 'Y',\n'TYR', 'Y',\n'TYS',\
 'Y',\n'TYV', 'X',\n'TYY', 'A',\n'TZB', 'X',\n'TZC\
', 'X',\n'TZE', 'X',\n'TZL', 'X',\n'TZO', 'X',\n'T\
ZP', 'X',\n'U01', 'X',\n'U02', 'X',\n'U03', 'X',\n\
'U04', 'X',\n'U05', 'X',\n'U0E', 'X',\n'U10', 'X',\
\n'U18', 'X',\n'U2G', 'X',\n'U3P', 'X',\n'U49', 'X\
',\n'U55', 'X',\n'U5P', 'X',\n'U66', 'X',\n'U89', \
'X',\n'U8U', 'X',\n'UAA', 'X',\n'UAG', 'A',\n'UAP'\
, 'X',\n'UAR', 'X',\n'UC1', 'X',\n'UC2', 'X',\n'UC\
3', 'X',\n'UC4', 'X',\n'UD1', 'X',\n'UD2', 'X',\n'\
UDP', 'X',\n'UDX', 'X',\n'UFG', 'X',\n'UFM', 'X',\\
n'UFP', 'X',\n'UGA', 'X',\n'UIN', 'X',\n'UKP', 'A'\
,\n'UM3', 'X',\n'UMA', 'A',\n'UMG', 'X',\n'UMP', '\
X',\n'UNA', 'X',\n'UND', 'X',\n'UNI', 'X',\n'UNK',\
 'X',\n'UNN', 'X',\n'UNX', 'X',\n'UP5', 'X',\n'UP6\
', 'X',\n'UPA', 'X',\n'UPF', 'X',\n'UPG', 'X',\n'U\
PP', 'X',\n'UQ1', 'X',\n'UQ2', 'X',\n'UQ6', 'X',\n\
'UR2', 'X',\n'URA', 'X',\n'URE', 'X',\n'URF', 'X',\
\n'URI', 'X',\n'URS', 'X',\n'UTP', 'X',\n'UVC', 'X\
',\n'UVW', 'X',\n'V35', 'X',\n'V36', 'X',\n'V4O', \
'X',\n'V7O', 'X',\n'VAA', 'V',\n'VAC', 'X',\n'VAD'\
, 'V',\n'VAF', 'V',\n'VAG', 'X',\n'VAL', 'V',\n'VA\
N', 'X',\n'VAS', 'X',\n'VAX', 'X',\n'VDX', 'X',\n'\
VDY', 'X',\n'VG1', 'X',\n'VIB', 'X',\n'VIR', 'X',\\
n'VIT', 'X',\n'VK3', 'X',\n'VO3', 'X',\n'VO4', 'X'\
,\n'VS1', 'F',\n'VS2', 'F',\n'VS3', 'F',\n'VS4', '\
F',\n'VXA', 'X',\n'W01', 'X',\n'W02', 'X',\n'W03',\
 'X',\n'W11', 'X',\n'W33', 'X',\n'W35', 'X',\n'W42\
', 'X',\n'W43', 'X',\n'W54', 'X',\n'W56', 'X',\n'W\
59', 'X',\n'W71', 'X',\n'W84', 'X',\n'W8R', 'X',\n\
'W91', 'X',\n'WAY', 'X',\n'WCC', 'X',\n'WO2', 'X',\
\n'WO4', 'X',\n'WRB', 'X',\n'WRR', 'X',\n'WRS', 'X\
',\n'WW7', 'X',\n'X2F', 'X',\n'X7O', 'X',\n'XAA', \
'X',\n'XAN', 'X',\n'XAO', 'X',\n'XBB', 'X',\n'XBP'\
, 'X',\n'XDN', 'X',\n'XDP', 'X',\n'XIF', 'X',\n'XI\
M', 'X',\n'XK2', 'X',\n'XL1', 'X',\n'XLS', 'X',\n'\
XMP', 'X',\n'XN1', 'X',\n'XN2', 'X',\n'XN3', 'X',\\
n'XUL', 'X',\n'XV6', 'X',\n'XYD', 'X',\n'XYH', 'X'\
,\n'XYL', 'X',\n'XYP', 'X',\n'XYS', 'X',\n'YOF', '\
Y',\n'YRR', 'X',\n'YT3', 'X',\n'YZ9', 'X',\n'Z34',\
 'G',\n'Z5A', 'X',\n'ZAF', 'X',\n'ZAP', 'X',\n'ZEB\
', 'X',\n'ZEN', 'X',\n'ZES', 'X',\n'ZID', 'X',\n'Z\
MR', 'X',\n'ZN3', 'X',\n'ZNH', 'X',\n'ZNO', 'X',\n\
'ZO3', 'X',\n'ZPR', 'P',\n'ZRA', 'A',\n'ZST', 'X',\
\n'ZYA', 'A',\n\n\n'ASN','N');\n} \n\n\nsub file2h\
ead\n      {\n	my $file = shift;\n	my $size = shif\
t;\n	my $f= new FileHandle;\n	my $line;\n	open ($f\
,$file);\n	read ($f,$line, $size);\n	close ($f);\n\
	return $line;\n      }\nsub file2tail\n      {\n	\
my $file = shift;\n	my $size = shift;\n	my $f= new\
 FileHandle;\n	my $line;\n	\n	open ($f,$file);\n	s\
eek ($f,$size*-1, 2);\n	read ($f,$line, $size);\n	\
close ($f);\n	return $line;\n      }\n\n\nsub vtmp\
nam\n      {\n	my $r=rand(100000);\n	my $f=\"file.\
$r.$$\";\n	while (-e $f)\n	  {\n	    $f=vtmpnam();\
\n	  }\n	push (@TMPFILE_LIST, $f);\n	return $f;\n \
     }\n\nsub myexit\n  {\n    my $code=@_[0];\n  \
  if ($CLEAN_EXIT_STARTED==1){return;}\n    else {\
$CLEAN_EXIT_STARTED=1;}\n    ### ONLY BARE EXIT\n \
   exit ($code);\n  }\nsub set_error_lock\n    {\n\
      my $name = shift;\n      my $pid=$$;\n\n    \
  \n      &lock4tc ($$,\"LERROR\", \"LSET\", \"$$ \
-- ERROR: $name $PROGRAM\\n\");\n      return;\n  \
  }\nsub set_lock\n  {\n    my $pid=shift;\n    my\
 $msg= shift;\n    my $p=getppid();\n    &lock4tc \
($pid,\"LLOCK\",\"LRESET\",\"$p$msg\\n\");\n  }\ns\
ub unset_lock\n   {\n     \n    my $pid=shift;\n  \
  &lock4tc ($pid,\"LLOCK\",\"LRELEASE\",\"\");\n  \
}\nsub shift_lock\n  {\n    my $from=shift;\n    m\
y $to=shift;\n    my $from_type=shift;\n    my $to\
_type=shift;\n    my $action=shift;\n    my $msg;\\
n    \n    if (!&lock4tc($from, $from_type, \"LCHE\
CK\", \"\")){return 0;}\n    $msg=&lock4tc ($from,\
 $from_type, \"LREAD\", \"\");\n    &lock4tc ($fro\
m, $from_type,\"LRELEASE\", $msg);\n    &lock4tc (\
$to, $to_type, $action, $msg);\n    return;\n  }\n\
sub isshellpid\n  {\n    my $p=shift;\n    if (!lo\
ck4tc ($p, \"LLOCK\", \"LCHECK\")){return 0;}\n   \
 else\n      {\n	my $c=lock4tc($p, \"LLOCK\", \"LR\
EAD\");\n	if ( $c=~/-SHELL-/){return 1;}\n      }\\
n    return 0;\n  }\nsub isrootpid\n  {\n    if(lo\
ck4tc (getppid(), \"LLOCK\", \"LCHECK\")){return 0\
;}\n    else {return 1;}\n  }\nsub lock4tc\n	{\n	 \
 my ($pid,$type,$action,$value)=@_;\n	  my $fname;\
\n	  my $host=hostname;\n	  \n	  if ($type eq \"LL\
OCK\"){$fname=\"$LOCKDIR/.$pid.$host.lock4tcoffee\\
";}\n	  elsif ( $type eq \"LERROR\"){ $fname=\"$LO\
CKDIR/.$pid.$host.error4tcoffee\";}\n	  elsif ( $t\
ype eq \"LWARNING\"){ $fname=\"$LOCKDIR/.$pid.$hos\
t.warning4tcoffee\";}\n	  \n	  if ($debug_lock)\n	\
    {\n	      print STDERR \"\\n\\t---lock4tc(tcg)\
: $action => $fname =>$value (RD: $LOCKDIR)\\n\";\\
n	    }\n\n	  if    ($action eq \"LCHECK\") {retur\
n -e $fname;}\n	  elsif ($action eq \"LREAD\"){ret\
urn file2string($fname);}\n	  elsif ($action eq \"\
LSET\") {return string2file ($value, $fname, \">>\\
");}\n	  elsif ($action eq \"LRESET\") {return str\
ing2file ($value, $fname, \">\");}\n	  elsif ($act\
ion eq \"LRELEASE\") \n	    {\n	      if ( $debug_\
lock)\n		{\n		  my $g=new FileHandle;\n		  open ($\
g, \">>$fname\");\n		  print $g \"\\nDestroyed by \
$$\\n\";\n		  close ($g);\n		  safe_system (\"mv $\
fname $fname.old\");\n		}\n	      else\n		{\n		  u\
nlink ($fname);\n		}\n	    }\n	  return \"\";\n	}\\
n	\nsub file2string\n	{\n	  my $file=@_[0];\n	  my\
 $f=new FileHandle;\n	  my $r;\n	  open ($f, \"$fi\
le\");\n	  while (<$f>){$r.=$_;}\n	  close ($f);\n\
	  return $r;\n	}\nsub string2file \n    {\n    my\
 ($s,$file,$mode)=@_;\n    my $f=new FileHandle;\n\
    \n    open ($f, \"$mode$file\");\n    print $f\
  \"$s\";\n    close ($f);\n  }\n\nBEGIN\n    {\n \
     srand;\n    \n      $SIG{'SIGUP'}='signal_cle\
anup';\n      $SIG{'SIGINT'}='signal_cleanup';\n  \
    $SIG{'SIGQUIT'}='signal_cleanup';\n      $SIG{\
'SIGILL'}='signal_cleanup';\n      $SIG{'SIGTRAP'}\
='signal_cleanup';\n      $SIG{'SIGABRT'}='signal_\
cleanup';\n      $SIG{'SIGEMT'}='signal_cleanup';\\
n      $SIG{'SIGFPE'}='signal_cleanup';\n      \n \
     $SIG{'SIGKILL'}='signal_cleanup';\n      $SIG\
{'SIGPIPE'}='signal_cleanup';\n      $SIG{'SIGSTOP\
'}='signal_cleanup';\n      $SIG{'SIGTTIN'}='signa\
l_cleanup';\n      $SIG{'SIGXFSZ'}='signal_cleanup\
';\n      $SIG{'SIGINFO'}='signal_cleanup';\n     \
 \n      $SIG{'SIGBUS'}='signal_cleanup';\n      $\
SIG{'SIGALRM'}='signal_cleanup';\n      $SIG{'SIGT\
STP'}='signal_cleanup';\n      $SIG{'SIGTTOU'}='si\
gnal_cleanup';\n      $SIG{'SIGVTALRM'}='signal_cl\
eanup';\n      $SIG{'SIGUSR1'}='signal_cleanup';\n\
\n\n      $SIG{'SIGSEGV'}='signal_cleanup';\n     \
 $SIG{'SIGTERM'}='signal_cleanup';\n      $SIG{'SI\
GCONT'}='signal_cleanup';\n      $SIG{'SIGIO'}='si\
gnal_cleanup';\n      $SIG{'SIGPROF'}='signal_clea\
nup';\n      $SIG{'SIGUSR2'}='signal_cleanup';\n\n\
      $SIG{'SIGSYS'}='signal_cleanup';\n      $SIG\
{'SIGURG'}='signal_cleanup';\n      $SIG{'SIGCHLD'\
}='signal_cleanup';\n      $SIG{'SIGXCPU'}='signal\
_cleanup';\n      $SIG{'SIGWINCH'}='signal_cleanup\
';\n      \n      $SIG{'INT'}='signal_cleanup';\n \
     $SIG{'TERM'}='signal_cleanup';\n      $SIG{'K\
ILL'}='signal_cleanup';\n      $SIG{'QUIT'}='signa\
l_cleanup';\n      \n      our $debug_lock=$ENV{\"\
DEBUG_LOCK\"};\n      \n      \n      \n      \n  \
    foreach my $a (@ARGV){$CL.=\" $a\";}\n      if\
 ( $debug_lock ){print STDERR \"\\n\\n\\n*********\
* START PG: $PROGRAM *************\\n\";}\n      i\
f ( $debug_lock ){print STDERR \"\\n\\n\\n********\
**(tcg) LOCKDIR: $LOCKDIR $$ *************\\n\";}\\
n      if ( $debug_lock ){print STDERR \"\\n --- $\
$ -- $CL\\n\";}\n      \n	     \n      \n      \n \
   }\nsub flush_error\n  {\n    my $msg=shift;\n  \
  return add_error ($EXIT_FAILURE,$$, $$,getppid()\
, $msg, $CL);\n  }\nsub add_error \n  {\n    my $c\
ode=shift;\n    my $rpid=shift;\n    my $pid=shift\
;\n    my $ppid=shift;\n    my $type=shift;\n    m\
y $com=shift;\n    \n    $ERROR_DONE=1;\n    lock4\
tc ($rpid, \"LERROR\",\"LSET\",\"$pid -- ERROR: $t\
ype\\n\");\n    lock4tc ($$, \"LERROR\",\"LSET\", \
\"$pid -- COM: $com\\n\");\n    lock4tc ($$, \"LER\
ROR\",\"LSET\", \"$pid -- STACK: $ppid -> $pid\\n\\
");\n   \n    return $code;\n  }\nsub add_warning \
\n  {\n    my $rpid=shift;\n    my $pid =shift;\n \
   my $command=shift;\n    my $msg=\"$$ -- WARNING\
: $command\\n\";\n    print STDERR \"$msg\";\n    \
lock4tc ($$, \"LWARNING\", \"LSET\", $msg);\n  }\n\
\nsub signal_cleanup\n  {\n    print dtderr \"\\n*\
*** $$ (tcg) was killed\\n\";\n    &cleanup;\n    \
exit ($EXIT_FAILURE);\n  }\nsub clean_dir\n  {\n  \
  my $dir=@_[0];\n    if ( !-d $dir){return ;}\n  \
  elsif (!($dir=~/tmp/)){return ;}#safety check 1\\
n    elsif (($dir=~/\\*/)){return ;}#safety check \
2\n    else\n      {\n	`rm -rf $dir`;\n      }\n  \
  return;\n  }\nsub cleanup\n  {\n    #print stder\
r \"\\n----tc: $$ Kills $PIDCHILD\\n\";\n    #kill\
 (SIGTERM,$PIDCHILD);\n    my $p=getppid();\n    $\
CLEAN_EXIT_STARTED=1;\n    \n    \n    \n    if (&\
lock4tc($$,\"LERROR\", \"LCHECK\", \"\"))\n      {\
\n	my $ppid=getppid();\n	if (!$ERROR_DONE) \n	  {\\
n	    &lock4tc($$,\"LERROR\", \"LSET\", \"$$ -- ST\
ACK: $p -> $$\\n\");\n	    &lock4tc($$,\"LERROR\",\
 \"LSET\", \"$$ -- COM: $CL\\n\");\n	  }\n      }\\
n    my $warning=&lock4tc($$, \"LWARNING\", \"LREA\
D\", \"\");\n    my $error=&lock4tc($$,  \"LERROR\\
", \"LREAD\", \"\");\n    #release error and warni\
ng lock if root\n    \n    if (isrootpid() && ($wa\
rning || $error) )\n      {\n	\n	print STDERR \"**\
************** Summary *************\\n$error\\n$w\
arning\\n\";\n\n	&lock4tc($$,\"LERROR\",\"RELEASE\\
",\"\");\n	&lock4tc($$,\"LWARNING\",\"RELEASE\",\"\
\");\n      } \n    \n    \n    foreach my $f (@TM\
PFILE_LIST)\n      {\n	if (-e $f){unlink ($f);} \n\
      }\n    foreach my $d (@TMPDIR_LIST)\n      {\
\n	clean_dir ($d);\n      }\n    #No More Lock Rel\
ease\n    #&lock4tc($$,\"LLOCK\",\"LRELEASE\",\"\"\
); #release lock \n\n    if ( $debug_lock ){print \
STDERR \"\\n\\n\\n********** END PG: $PROGRAM ($$)\
 *************\\n\";}\n    if ( $debug_lock ){prin\
t STDERR \"\\n\\n\\n**********(tcg) LOCKDIR: $LOCK\
DIR $$ *************\\n\";}\n  }\nEND \n  {\n    \\
n    &cleanup();\n  }\n   \n\nsub safe_system \n{\\
n  my $com=shift;\n  my $ntry=shift;\n  my $ctry=s\
hift;\n  my $pid;\n  my $status;\n  my $ppid=getpp\
id();\n  if ($com eq \"\"){return 1;}\n  \n  \n\n \
 if (($pid = fork ()) < 0){return (-1);}\n  if ($p\
id == 0)\n    {\n      set_lock($$, \" -SHELL- $co\
m (tcg)\");\n      exec ($com);\n    }\n  else\n  \
  {\n      lock4tc ($$, \"LLOCK\", \"LSET\", \"$pi\
d\\n\");#update parent\n      $PIDCHILD=$pid;\n   \
 }\n  if ($debug_lock){printf STDERR \"\\n\\t ....\
 safe_system (fasta_seq2hmm)  p: $$ c: $pid COM: $\
com\\n\";}\n\n  waitpid ($pid,WTERMSIG);\n\n  shif\
t_lock ($pid,$$, \"LWARNING\",\"LWARNING\", \"LSET\
\");\n\n  if ($? == $EXIT_FAILURE || lock4tc($pid,\
 \"LERROR\", \"LCHECK\", \"\"))\n    {\n      if (\
$ntry && $ctry <$ntry)\n	{\n	  add_warning ($$,$$,\
\"$com failed [retry: $ctry]\");\n	  lock4tc ($pid\
, \"LRELEASE\", \"LERROR\", \"\");\n	  return safe\
_system ($com, $ntry, ++$ctry);\n	}\n      elsif (\
$ntry == -1)\n	{\n	  if (!shift_lock ($pid, $$, \"\
LERROR\", \"LWARNING\", \"LSET\"))\n	    {\n	     \
 add_warning ($$,$$,\"$com failed\");\n	    }\n	  \
else\n	    {\n	      lock4tc ($pid, \"LRELEASE\", \
\"LERROR\", \"\");\n	    }\n	  return $?;}\n      \
else\n	{\n	  if (!shift_lock ($pid,$$, \"LERROR\",\
\"LERROR\", \"LSET\"))\n	    {\n	      myexit(add_\
error ($EXIT_FAILURE,$$,$pid,getppid(), \"UNSPECIF\
IED system\", $com));\n	    }\n	}\n    }\n  return\
 $?;\n}\n\nsub check_configuration \n    {\n      \
my @l=@_;\n      my $v;\n      foreach my $p (@l)\\
n	{\n	  \n	  if   ( $p eq \"EMAIL\")\n	    { \n	  \
    if ( !($EMAIL=~/@/))\n		{\n		add_warning($$,$$\
,\"Could Not Use EMAIL\");\n		myexit(add_error ($E\
XIT_FAILURE,$$,$$,getppid(),\"EMAIL\",\"$CL\"));\n\
	      }\n	    }\n	  elsif( $p eq \"INTERNET\")\n	\
    {\n	      if ( !&check_internet_connection())\\
n		{\n		  myexit(add_error ($EXIT_FAILURE,$$,$$,ge\
tppid(),\"INTERNET\",\"$CL\"));\n		}\n	    }\n	  e\
lsif( $p eq \"wget\")\n	    {\n	      if (!&pg_is_\
installed (\"wget\") && !&pg_is_installed (\"curl\\
"))\n		{\n		  myexit(add_error ($EXIT_FAILURE,$$,$\
$,getppid(),\"PG_NOT_INSTALLED:wget\",\"$CL\"));\n\
		}\n	    }\n	  elsif( !(&pg_is_installed ($p)))\n\
	    {\n	      myexit(add_error ($EXIT_FAILURE,$$,\
$$,getppid(),\"PG_NOT_INSTALLED:$p\",\"$CL\"));\n	\
    }\n	}\n      return 1;\n    }\nsub pg_is_insta\
lled\n  {\n    my @ml=@_;\n    my $r, $p, $m;\n   \
 my $supported=0;\n    \n    my $p=shift (@ml);\n \
   if ($p=~/::/)\n      {\n	if (safe_system (\"per\
l -M$p -e 1\")==$EXIT_SUCCESS){return 1;}\n	else {\
return 0;}\n      }\n    else\n      {\n	$r=`which\
 $p 2>/dev/null`;\n	if ($r eq \"\"){return 0;}\n	e\
lse {return 1;}\n      }\n  }\n\n\n\nsub check_int\
ernet_connection\n  {\n    my $internet;\n    my $\
tmp;\n    &check_configuration ( \"wget\"); \n    \
\n    $tmp=&vtmpnam ();\n    \n    if     (&pg_is_\
installed    (\"wget\")){`wget www.google.com -O$t\
mp >/dev/null 2>/dev/null`;}\n    elsif  (&pg_is_i\
nstalled    (\"curl\")){`curl www.google.com -o$tm\
p >/dev/null 2>/dev/null`;}\n    \n    if ( !-e $t\
mp || -s $tmp < 10){$internet=0;}\n    else {$inte\
rnet=1;}\n    if (-e $tmp){unlink $tmp;}\n\n    re\
turn $internet;\n  }\nsub check_pg_is_installed\n \
 {\n    my @ml=@_;\n    my $r=&pg_is_installed (@m\
l);\n    if (!$r && $p=~/::/)\n      {\n	print STD\
ERR \"\\nYou Must Install the perl package $p on y\
our system.\\nRUN:\\n\\tsudo perl -MCPAN -e 'insta\
ll $pg'\\n\";\n      }\n    elsif (!$r)\n      {\n\
	myexit(flush_error(\"\\nProgram $p Supported but \
Not Installed on your system\"));\n      }\n    el\
se\n      {\n	return 1;\n      }\n  }\n\n\nsub rem\
ote_is_pdb_name_deprecated\n{\n    my $in=@_[0];\n\
    my ($ref_file, $pdb);\n    my ($value,$value1,\
$value2);\n    my $max=2;\n    \n    \n    \n    $\
ref_file=\"$cache/pdb_entry_type.txt\";\n    \n   \
 if ( $in=~/[^\\w\\d\\:\\_]/){return 0;}\n    elsi\
f ($no_remote_pdb_dir==1)\n      {\n	my $pdbdir=$E\
NV{'PDB_DIR'};\n	\n	my $r1=\"$pdbdir/derived_data/\
pdb_entry_type.txt\";\n	my $r2=$ref_file;\n	if    \
(-e $r1){$ref_file=$r1;}\n	elsif (-e $r2){$ref_fil\
e=$r2;}\n	else\n	  {\n	    my $p=substr ($in,0, 4)\
;\n	    add_warning ($$, $$, \"Cannot find pdb_ent\
ry_type.txt;  $p is assumed to be valid; add ftp:/\
/ftp.wwpdb.org/pub/pdb/derived_data/pdb_entry_type\
.txt in $cache to check name status\");\n	  }\n   \
   }\n    elsif ( !-e $ref_file || (-M $ref_file)>\
$max || -z $ref_file)\n      {\n	&url2file(\"ftp:/\
/ftp.wwpdb.org/pub/pdb/derived_data/pdb_entry_type\
.txt\", $ref_file);\n      }\n    $pdb=substr ($in\
,0, 4);\n    chomp(($value1=`grep -c $pdb $ref_fil\
e`));\n    $pdb=lc($pdb);\n    chomp(($value2=`gre\
p -c $pdb $ref_file`));\n    $value=($value1 || $v\
alue2)?1:0;\n    $value=($value>0)?1:0;\n    \n   \
 return $value;\n  }\n","use Cwd;\nuse Env;\nuse F\
ile::Path;\nuse FileHandle;\nuse strict;\n\n\nour \
(%MODE, %PG, %ENV_SET, %SUPPORTED_OS);\n\n\nour $E\
XIT_SUCCESS=0;\nour $EXIT_FAILURE=1;\nour $INTERNE\
T=0;\n\nour $CP=\"cp \"; #was causing a crash on M\
acOSX\nour $SILENT=\">/dev/null 2>/dev/null\";\nou\
r $WEB_BASE=\"http://www.tcoffee.org\";\nour $TCLI\
NKDB_ADDRESS=\"$WEB_BASE/Resources/tclinkdb.txt\";\
\nour $OS=get_os();\nour $ROOT=&get_root();\nour $\
CD=cwd();\nour $CDIR=$CD;\nour $HOME=$ENV{'HOME'};\
\n\nour $OSNAME=$ENV{'OSNAME'};\nour $OSARCH=$ENV{\
'OSARCH'};\nour $REPO_ROOT=\"\";\n\nour $TCDIR;\no\
ur $TCCACHE;\nour $TCTMP;\nour $TCM;\nour $TCMETHO\
DS;\nour $TCPLUGINS;\nour $PLUGINS_DIR=\"\";\nour \
$INSTALL_DIR=\"\";\n\nour $CXX=\"g++\";\nour $CXXF\
LAGS=\"\";\n\nour $CPP=\"g++\";\nour $CPPFLAGS=\"\\
";\n\nour $CC=\"gcc\";\nour $CFLAGS=$ENV{'CFLAGS'}\
;\n\nour $FC=\"f77\";\nour $FFLAGS=\"\";\n\nmy $in\
stall=\"all\";\nmy $default_update_action=\"no_upd\
ate\";\nmy @required_applications=(\"wget_OR_curl\\
");\nmy @smode=(\"all\", \"clean\", \"install\");\\
n\n&initialize_PG();\n\nmy $cl=join( \" \", @ARGV)\
;\nif ($#ARGV==-1 || ($cl=~/-h/) ||($cl=~/-H/) )\n\
  {\n     print \"\\n!!!!!!! ./install  t_coffee  \
           --> installs t_coffee only\";\n     pri\
nt \"\\n!!!!!!! ./install  all                  --\
> installs all the modes [mcoffee, expresso, psico\
ffee,rcoffee..]\";\n     print \"\\n!!!!!!! ./inst\
all  [mcoffee|rcoffee|..] --> installs the specifi\
ed mode\";\n     print \"\\n!!!!!!! ./install  -h \
                  --> print usage\\n\\n\";\n     i\
f ( $#ARGV==-1){exit ($EXIT_FAILURE);}\n   }\n    \
 \nif (($cl=~/-h/) ||($cl=~/-H/) )\n  {\n    my $m\
;\n    print \"\\n\\n!!!!!!! advanced mode\\n\";\n\
    foreach $m ((keys (%MODE)),@smode)\n      {\n	\
print \"!!!!!!!       ./install $m\\n\";\n      }\\
n    \n    print \"!!!!!!! ./install [target:packa\
ge|mode|] [-update|-force|-exec=dir|-dis=dir|-root\
|-tclinkdb=file|-] [CC=|FCC=|CXX=|CFLAGS=|CXXFLAGS\
=]\\n\";\n    print \"!!!!!!! ./install clean    [\
removes all executables]\\n\";\n    print \"!!!!!!\
! ./install [optional:target] -update             \
  [updates package already installed]\\n\";\n    p\
rint \"!!!!!!! ./install [optional:target] -force \
               [Forces recompilation over everythi\
ng]\\n\";\n    \n    print \"!!!!!!! ./install [op\
tional:target] -root                 [You are runn\
ing as root]\\n\";\n    print \"!!!!!!! ./install \
[optional:target] -exec=/foo/bar/       [address f\
or the T-Coffee executable]\\n\";\n    print \"!!!\
!!!! ./install [optional:target] -dis=/foo/bar/   \
     [Address where distributions should be stored\
]\\n\";\n    print \"!!!!!!! ./install [optional:t\
arget] -tclinkdb=foo|update  [file containing all \
the packages to be installed]\\n\";\n    print \"!\
!!!!!! ./install [optional:target] -clean         \
       [clean everything]\\n\";\n    print \"!!!!!\
!! ./install [optional:target] -plugins           \
   [plugins directory]\\n\";\n    print \"!!!!!!! \
./install [optional:target] -tcdir=/foor/bar      \
[base path where T-Coffee will be installed]\\n\";\
\n    print \"!!!!!!! ./install [optional:target] \
-repo=/path/to/repo   [binaries repository root di\
rectory]\\n\";\n    print \"!!!!!!! mode:\";\n    \
foreach $m (keys(%MODE)){print \"$m \";}\n    prin\
t \"\\n\";\n    print \"!!!!!!! Packages:\";\n    \
foreach $m (keys (%PG)){print \"$m \";}\n    print\
 \"\\n\";\n    \n    print \"\\n\\n\";\n    exit (\
$EXIT_FAILURE);\n  }\n\n\n\nmy (@argl)=($cl=~/(\\S\
+=[^=]+)\\s\\w+=/g);\npush (@argl, ($cl=~/(\\S+=[^\
=]+\\S)\\s*$/g));\n\nforeach $a (@argl)\n  {\n    \
if ( ($cl=~/CXX=(.*)/)){$CXX=$1;}\n    if ( ($cl=~\
/-CC=(.*)/    )){$CC=$1;}\n    if ( ($cl=~/-FC=(.*\
)/    )){$FC=$1;}\n    if ( ($cl=~/-CFLAGS=(.*)/))\
{$CFLAGS=$1;}\n    if ( ($cl=~/-CXXFLAGS=(.*)/)){$\
CXXFLAGS=$1;}\n  }\nour ($ROOT_INSTALL, $NO_QUESTI\
ON, $default_update_action,$BINARIES_ONLY,$force, \
$default_update_action, $INSTALL_DIR, $PLUGINS_DIR\
, $DISTRIBUTIONS,$tclinkdb, $proxy, $clean);\nif (\
 ($cl=~/-root/)){$ROOT_INSTALL=1;}\nif ( ($cl=~/-n\
o_question/)){$NO_QUESTION=1;}\nif ( ($cl=~/-updat\
e/)){$default_update_action=\"update\";}\n$BINARIE\
S_ONLY=1;\nif ( ($cl=~/-nobinaries/)){$BINARIES_ON\
LY=0;}\nif ( ($cl=~/-force/)){$force=1;$default_up\
date_action=\"update\"}\nif ( ($cl=~/-exec=\\s*(\\\
S+)/)){$INSTALL_DIR=$1;}\nif ( ($cl=~/-plugins=\\s\
*(\\S+)/)){$PLUGINS_DIR=$1;}\nif ( ($cl=~/-dis=\\s\
*(\\S+)/)){$DISTRIBUTIONS=$1;}\n\nif ( ($cl=~/-tcl\
inkdb=\\s*(\\S+)/)){$tclinkdb=$1;}\nif ( ($cl=~/-p\
roxy=\\s*(\\S+)/)){$proxy=$1;}\nif ( ($cl=~/-clean\
/)){$clean=1;}\nif ( ($cl=~/-repo=\\s*(\\S+)/)){ $\
REPO_ROOT=$1; }\nif ( ($cl=~/-tcdir=\\s*(\\S+)/)){\
 $TCDIR=$1; }\nif ($tclinkdb){&update_tclinkdb ($t\
clinkdb);}\n\n\nif( $REPO_ROOT ne \"\" ) {\n	if( $\
OSNAME eq \"\" ) { print \"You have specified the \
repository folder but the required \\\"OSNAME\\\" \
enviroment variable is missing. \\n\"; exit 1; } \\
n	if( $OSARCH eq \"\" ) { print \"You have specifi\
ed the repository folder but the required \\\"OSAR\
CH\\\" enviroment variable is missing. \\n\"; exit\
 1; } \n}\n\n\nif(!$TCDIR) { $TCDIR=\"$HOME/.t_cof\
fee\"; }\n&add_dir ($TCDIR);\n&add_dir ($TCCACHE=\\
"$TCDIR/cache\");\n&add_dir ($TCTMP=\"$CDIR/tmp\")\
;\n&add_dir ($TCM=\"$TCDIR/mcoffee\");\n&add_dir (\
$TCMETHODS=\"$TCDIR/methods\");\n&add_dir ($TCPLUG\
INS=\"$TCDIR/plugins/$OS\");\n\n\nour $BASE=\"$CD/\
bin\";\nour $BIN=\"$BASE/binaries/$OS\";\nour $DOW\
NLOAD_DIR=\"$BASE/download\";\nour $DOWNLOAD_FILE=\
\"$DOWNLOAD_DIR/files\";\nour $TMP=\"$BASE/tmp\";\\
n\n&add_dir($BASE);\n&add_dir($BIN);\n&add_dir($DO\
WNLOAD_DIR);\n&add_dir($DOWNLOAD_FILE);\nif (!$DIS\
TRIBUTIONS){$DISTRIBUTIONS=\"$DOWNLOAD_DIR/distrib\
utions\";}\n&add_dir ($DISTRIBUTIONS);\n&add_dir (\
$TMP);\n\n\nif    (!$PLUGINS_DIR && !$ROOT_INSTALL\
){$PLUGINS_DIR=$TCPLUGINS;}\nelsif (!$PLUGINS_DIR \
&&  $ROOT_INSTALL){$PLUGINS_DIR=\"/usr/local/bin/\\
";}\n\nif    (!$INSTALL_DIR && !$ROOT_INSTALL){$IN\
STALL_DIR=\"$HOME/bin/\";mkpath ($INSTALL_DIR);}\n\
elsif (!$INSTALL_DIR &&  $ROOT_INSTALL){$INSTALL_D\
IR=\"/usr/local/bin/\";}\n\nif (-d \"mcoffee\"){`c\
p mcoffee/* $TCM`;}\n\n\nour $ENV_FILE=\"$TCDIR/t_\
coffee_env\";\n&env_file2putenv ($ENV_FILE);\n&set\
_proxy($proxy);\nmy ($target, $p, $r);\n$target=$p\
;\n\nforeach $p (  ((keys (%PG)),(keys(%MODE)),(@s\
mode)) )\n  {\n    if ($ARGV[0] eq $p && $target e\
q \"\"){$target=$p;}\n  }\nif ($target eq \"\"){ex\
it ($EXIT_FAILURE);}\n\n\nforeach $r (@required_ap\
plications)\n  {\n    my @app_list;\n    my $i;\n \
   $i=0;\n    \n    @app_list=split (/_OR_/, $r);\\
n    foreach my $pg (@app_list)\n      {\n	$i+=&pg\
_is_installed ($pg);\n      }\n    if ($i==0)\n   \
   {\n      print \"One of the following packages \
must be installed to proceed: \";\n      foreach m\
y $pg (@app_list)\n	{\n	  print (\"$pg \");\n	}\n \
     die;\n    }\n  }\n\n\n\n\n\n\n&sign_license_n\
i();\n\n\n$PG{C}{compiler}=get_C_compiler($CC);\n$\
PG{Fortran}{compiler}=get_F_compiler($FC);\n$PG{CX\
X}{compiler}=$PG{CPP}{compiler}=$PG{GPP}{compiler}\
=get_CXX_compiler($CXX);\nif ($CXXFLAGS){$PG{CPP}{\
options}=$PG{GPP}{options}=$PG{CXX}{options}=$CXXF\
LAGS;}\nif ($CFLAGS ne \"\" ){$PG{C}{options}=$CFL\
AGS;}\nforeach my $c (keys(%PG))\n  {\n    my $arg\
uments;\n    if ($PG{$c}{compiler})\n      {\n	$ar\
guments=\"$PG{$c}{compiler_flag}=$PG{$c}{compiler}\
 \";\n	if ($PG{$c}{options})\n	  {\n	    $argument\
s.=\"$PG{$c}{options_flag}='\" . $PG{$c}{options} \
. \"' \";\n	  }\n	$PG{$c}{arguments}=$arguments;\n\
      }\n  }\n\nif ($PG{$target}){$PG{$target}{ins\
tall}=1;}\nelse\n  {\n    foreach my $pg (keys(%PG\
))\n      {\n	if ( $target eq \"all\" || ($PG{$pg}\
{mode}=~/$target/))\n	  {\n	    $PG{$pg} {install}\
=1;\n	  }\n      }\n  }\n\nforeach my $pg (keys(%P\
G))\n  {\n    if (!$PG{$pg}{update_action}){$PG{$p\
g}{update_action}=$default_update_action;}\n    el\
sif ($PG{$pg}{update_action} eq \"never\"){$PG{$pg\
}{install}=0;}\n    if ( $force && $PG{$pg}{instal\
l})\n      {\n	`rm $BIN/$pg $BIN/$pg.exe $SILENT`;\
\n      }\n    if ($PG{$pg}{update_action} eq \"up\
date\" && $PG{$pg}{install}){$PG{$pg}{update}=1;}\\
n  }\n\nif (($target=~/clean/))\n  {\n    print \"\
------- cleaning executables -----\\n\";\n    `rm \
bin/* $SILENT`;\n    exit ($EXIT_SUCCESS);\n  }\n\\
nif ( !$PG{$target}){print \"------- Installing T-\
Coffee Modes\\n\";}\n\nforeach my $m (keys(%MODE))\
\n  {\n    if ( $target eq \"all\" || $target eq $\
m)\n      {\n	print \"\\n------- The installer wil\
l now install the $m components $MODE{$m}{descript\
ion}\\n\";\n	foreach my $pg (keys(%PG))\n	  {\n	  \
  if ( $PG{$pg}{mode} =~/$m/ && $PG{$pg}{install})\
\n	      {\n		if ($PG{$pg}{touched}){print \"-----\
-- $PG{$pg}{dname}: already processed\\n\";}\n		el\
se {$PG{$pg}{success}=&install_pg($pg);$PG{$pg}{to\
uched}=1;}\n	      }\n	  }\n      }\n  }\n\nif ( $\
PG{$target}){print \"------- Installing Individual\
 Package\\n\";}\nforeach my $pg (keys (%PG))\n  {\\
n    \n    if ( $PG{$pg}{install} && !$PG{$pg}{tou\
ched})\n      {\n	print \"\\n------- Install $pg\\\
n\";\n	$PG{$pg}{success}=&install_pg($pg);$PG{$pg}\
{touched}=1;\n      }\n  }\nprint \"------- Finish\
ing The installation\\n\";\nmy $final_report=&inst\
all ($INSTALL_DIR);\n\nprint \"\\n\";\nprint \"***\
**************************************************\
****************\\n\";\nprint \"********          \
    INSTALLATION SUMMARY          ****************\
*\\n\";\nprint \"*********************************\
************************************\\n\";\nprint \
\"------- SUMMARY package Installation:\\n\";\npri\
nt \"-------   Executable Installed in: $PLUGINS_D\
IR\\n\";\n\nforeach my $pg (keys(%PG))\n  {\n    i\
f ( $PG{$pg}{install})\n      {\n	my $bin_status=(\
$PG{$pg}{from_binary} && $PG{$pg}{success})?\"[fro\
m binary]\":\"\";\n	if     ( $PG{$pg}{new} && !$PG\
{$pg}{old})                     {print \"*------  \
      $PG{$pg}{dname}: installed $bin_status\\n\";\
 $PG{$pg}{status}=1;}\n	elsif  ( $PG{$pg}{new} && \
 $PG{$pg}{old})                     {print \"*----\
--        $PG{$pg}{dname}: updated $bin_status\\n\\
"  ; $PG{$pg}{status}=1;} \n	elsif  (!$PG{$pg}{new\
} &&  $PG{$pg}{old} && !$PG{$pg}{update}){print \"\
*------        $PG{$pg}{dname}: previous\\n\" ; $P\
G{$pg}{status}=1;}\n	elsif  (!$PG{$pg}{new} &&  $P\
G{$pg}{old} &&  $PG{$pg}{update}){print \"*------ \
       $PG{$pg}{dname}: failed update (previous in\
stallation available)\\n\";$PG{$pg}{status}=0;}\n	\
else                                              \
            {print \"*------        $PG{$pg}{dname\
}: failed installation\\n\";$PG{$pg}{status}=0;}\n\
      }\n  }\nmy $failure;\n\nif ( !$PG{$target}){\
print \"*------ SUMMARY mode Installation:\\n\";}\\
nforeach my $m (keys(%MODE))\n  {\n  \n    if ( $t\
arget eq \"all\" || $target eq $m)\n      {\n	my $\
succesful=1;\n	foreach my $pg (keys(%PG))\n	  {\n	\
    if (($PG{$pg}{mode}=~/$m/) && $PG{$pg}{install\
} && $PG{$pg}{status}==0)\n	      {\n		$succesful=\
0;\n		print \"*!!!!!!       $PG{$pg}{dname}: Missi\
ng\\n\";\n	      }\n	  }\n	if ( $succesful)\n	  {\\
n	    $MODE{$m}{status}=1;\n	    print \"*------  \
     MODE $MODE{$m}{dname} SUCCESSFULLY installed\\
\n\";\n	  }\n	else\n	  {\n	    $failure++;\n	    $\
MODE{$m}{status}=0;\n	    print \"*!!!!!!       MO\
DE $MODE{$m}{dname} UNSUCCESSFULLY installed\\n\";\
\n	  }\n      }\n  }\n\n    \n      \nif ($clean==\
1 && ($BASE=~/install4tcoffee/) ){print \"*------ \
Clean Installation Directory: $BASE\\n\";`rm -rf $\
BASE`;}\nforeach my $pg (keys(%PG)){if ($PG{$pg}{i\
nstall} && $PG{$pg}{status}==0){exit ($EXIT_FAILUR\
E);}}\n\nif ($failure)\n  {\n    print \"*********\
**************************************************\
**********\\n\";\n    print \"********     SOME PA\
CKAGES FAILED TO INSTALL        *****************\\
\n\";\n    print \"*******************************\
**************************************\\n\";\n    \
print \"\\nSome of the reported failures may be du\
e to connectivity problems\";\n    print \"\\nReru\
n the installation and the installer will specific\
ally try to install the missing packages\";\n    p\
rint \"\\nIf this Fails, go to the original websit\
e and install the package manually\";\n  }\n\nprin\
t \"**********************************************\
***********************\\n\";\nprint \"********   \
           FINALIZE YOUR INSTALLATION    *********\
********\\n\";\nprint \"**************************\
*******************************************\\n\";\\
nprint \"------- Your executables are in:\\n\"; \n\
print \"-------       $PLUGINS_DIR:\\n\";\nprint \\
"------- Add this directory to your path with the \
following command:\\n\";\nprint \"-------       ex\
port PATH=$PLUGINS_DIR:\\$PATH\\n\";\nprint \"----\
--- Make this permanent by adding this line to the\
 file:\\n\";\nprint \"-------       $HOME/.bashrc\\
\n\";\nexit ($EXIT_SUCCESS);  \n  \nsub get_CXX_co\
mpiler\n  {\n    my $c=@_[0];\n    my (@clist)=(\"\
g++\");\n    \n    return get_compil ($c, @clist);\
\n }\nsub get_C_compiler\n  {\n    my $c=@_[0];\n \
   my (@clist)=(\"gcc\", \"cc\", \"icc\");\n    \n\
    return get_compil ($c, @clist);\n }\n\nsub get\
_F_compiler\n  {\n    my ($c)=@_[0];\n    my @clis\
t=(\"f77\", \"g77\",\"g95\", \"gfortran\", \"ifort\
\");\n    return get_compil ($c, @clist);\n  } \n \
      \nsub get_compil\n  {\n    my ($fav,@clist)=\
(@_);\n    \n    #return the first compiler found \
installed in the system. Check first the favorite\\
n    foreach my $c ($fav,@clist)\n      {\n	if  (&\
pg_is_installed ($c)){return $c;}\n      }\n    re\
turn \"\";\n  }\nsub exit_if_pg_not_installed\n  {\
\n    my (@arg)=(@_);\n    \n    foreach my $p (@a\
rg)\n      {\n	if ( !&pg_is_installed ($p))\n	  {\\
n	    print \"!!!!!!!! The $p utility must be inst\
alled for this installation to proceed [FATAL]\\n\\
";\n	    die;\n	  }\n      }\n    return 1;\n  }\n\
sub set_proxy\n  {\n    my ($proxy)=(@_);\n    my \
(@list,$p);\n    \n    @list= (\"HTTP_proxy\", \"h\
ttp_proxy\", \"HTTP_PROXY\", \"ALL_proxy\", \"all_\
proxy\",\"HTTP_proxy_4_TCOFFEE\",\"http_proxy_4_TC\
OFFEE\");\n    \n    if (!$proxy)\n      {\n	forea\
ch my $p (@list)\n	  {\n	    if ( ($ENV_SET{$p}) |\
| $ENV{$p}){$proxy=$ENV{$p};}\n	  }\n      }\n    \
foreach my $p(@list){$ENV{$p}=$proxy;}\n  }\n	\nsu\
b check_internet_connection\n  {\n    my $internet\
;\n    \n    if ( -e \"x\"){unlink (\"x\");}\n    \
if     (&pg_is_installed    (\"wget\")){`wget www.\
google.com -Ox >/dev/null 2>/dev/null`;}\n    elsi\
f  (&pg_is_installed    (\"curl\")){`curl www.goog\
le.com -ox >/dev/null 2>/dev/null`;}\n    else\n  \
    {\n	printf stderr \"\\nERROR: No pg for remote\
 file fetching [wget or curl][FATAL]\\n\";\n	exit \
($EXIT_FAILURE);\n      }\n    \n    if ( !-e \"x\\
" || -s \"x\" < 10){$internet=0;}\n    else {$inte\
rnet=1;}\n    if (-e \"x\"){unlink \"x\";}\n    re\
turn $internet;\n  }\nsub url2file\n  {\n    my ($\
cmd, $file,$wget_arg, $curl_arg)=(@_);\n    my ($e\
xit,$flag, $pg, $arg);\n    \n    if ($INTERNET ||\
 check_internet_connection ()){$INTERNET=1;}\n    \
else\n      {\n	print STDERR \"ERROR: No Internet \
Connection [FATAL:install.pl]\\n\";\n	exit ($EXIT_\
FAILURE);\n      }\n    \n    if     (&pg_is_insta\
lled    (\"wget\")){$pg=\"wget\"; $flag=\"-O\";$ar\
g=\"--tries=2 --connect-timeout=10 $wget_arg\";}\n\
    elsif  (&pg_is_installed    (\"curl\")){$pg=\"\
curl\"; $flag=\"-o\";$arg=$curl_arg;}\n    else\n \
     {\n	printf stderr \"\\nERROR: No pg for remot\
e file fetching [wget or curl][FATAL]\\n\";\n	exit\
 ($EXIT_FAILURE);\n      }\n    \n    \n    if (-e\
 $file){unlink($file);}\n    $exit=system \"$pg $c\
md $flag$file $arg\";\n    return $exit;\n  }\n\ns\
ub pg_is_installed\n  {\n    my ($p, $dir)=(@_);\n\
    my ($r,$m, $ret);\n    my ($supported, $langua\
ge, $compil);\n    \n  \n    if ( $PG{$p})\n      \
{\n	$language=$PG{$p}{language2};\n	$compil=$PG{$l\
anguage}{compiler};\n      }\n    \n    if ( $comp\
il eq \"CPAN\")\n      {\n	if ( system (\"perl -M$\
p -e 1\")==$EXIT_SUCCESS){$ret=1;}\n	else {$ret=0;\
}\n      }\n    elsif ($dir)\n      {\n	if (-e \"$\
dir/$p\" || -e \"$dir/$p\\.exe\"){$ret=1;}\n	else \
{$ret=0;}\n      }\n    elsif (-e \"$PLUGINS_DIR/$\
p\" || -e \"$PLUGINS_DIR/$p.exe\"){$ret=1;}\n    e\
lse\n      {\n	$r=`which $p 2>/dev/null`;\n	if ($r\
 eq \"\"){$ret=0;}\n	else {$ret=1;}\n      }\n   \\
n    return $ret;\n  }\nsub install\n  {\n    my (\
$new_bin)=(@_);\n    my ($copied, $report);\n\n   \
 \n    if (!$ROOT_INSTALL)\n      {\n	\n	if (-e \"\
$BIN/t_coffee\"){`$CP $BIN/t_coffee $INSTALL_DIR`}\
;\n	`cp $BIN/* $PLUGINS_DIR`;\n	$copied=1;\n      \
}\n    else\n      {\n	$copied=&root_run (\"You mu\
st be root to finalize the installation\", \"$CP $\
BIN/* $INSTALL_DIR $SILENT\");\n      }\n    \n   \
  \n  if ( !$copied)\n    {\n      $report=\"*!!!!\
!! Installation unsuccesful. The executables have \
been left in $BASE/bin\\n\";\n    }\n  elsif ( $co\
pied && $ROOT)\n    {\n      $report=\"*------ Ins\
tallation succesful. Your executables have been co\
pied in $new_bin and are on your PATH\\n\";\n    }\
\n  elsif ( $copied && !$ROOT)\n    {\n      $repo\
rt= \"*!!!!!! T-Coffee and associated packages hav\
e been copied in: $new_bin\\n\";\n      $report.=\\
"*!!!!!! This address is NOT in your PATH sytem va\
riable\\n\";\n      $report.=\"*!!!!!! You can do \
so by adding the following line in your ~/.bashrc \
file:\\n\";\n      $report.=\"*!!!!!! export PATH=\
$new_bin:\\$PATH\\n\";\n    }\n  return $report;\n\
}\n\nsub sign_license_ni\n  {\n    my $F=new FileH\
andle;\n    open ($F, \"license.txt\");\n    while\
 (<$F>)\n      {\n	print \"$_\";\n      }\n    clo\
se ($F);\n    \n    return;\n  }\n\nsub install_pg\
\n  {\n    my ($pg)=(@_);\n    my ($report, $previ\
ous, $language, $compiler, $return);\n    \n    if\
 (!$PG{$pg}{install}){return 1;}\n    \n    $previ\
ous=&pg_is_installed ($pg);\n    \n    if ($PG{$pg\
}{update_action} eq \"no_update\" && $previous)\n \
     {\n	$PG{$pg}{old}=1;\n	$PG{$pg}{new}=0;\n	$re\
turn=1;\n      }\n    else\n      {\n	$PG{$pg}{old\
}=$previous;\n	\n	if ($PG{$pg} {language2} eq \"Pe\
rl\"){&install_perl_package ($pg);}\n	elsif ($pg n\
e \"t_coffee\" && $BINARIES_ONLY && &install_binar\
y_package ($pg)){$PG{$pg}{from_binary}=1;}\n	elsif\
 (&install_source_package ($pg)){;}\n	else \n	  {\\
n	    \n	    if (!&supported_os($OS))\n	      {\n	\
	print \"!!!!!!!! $pg compilation failed, binary u\
nsupported for $OS\\n\"; \n	      }\n	    elsif (!\
($PG{$pg}{from_binary}=&install_binary_package ($p\
g)))\n	      {\n		print \"!!!!!!!! $pg compilation\
 and  binary installation failed\\n\";\n	      }\n\
	  }\n	$PG{$pg}{new}=$return=&pg_is_installed ($pg\
,$BIN);\n      }\n\n    \n    return $return;\n  }\
\nsub install_perl_package\n  {\n    my ($pg)=(@_)\
;\n    my ($report, $language, $compiler);\n    \n\
    $language=$PG{$pg} {language2};\n    $compiler\
=$PG{$language}{compiler};\n    \n    if (!&pg_is_\
installed ($pg))\n      {\n	if ( $OS eq \"windows\\
"){`perl -M$compiler -e 'install $pg'`;}\n	elsif (\
 $ROOT eq \"sudo\"){system (\"sudo perl -M$compile\
r -e 'install $pg'\");}\n	else {system (\"su root \
-c perl -M$compiler -e 'install $pg'\");}\n      }\
\n    return &pg_is_installed ($pg);\n  }\n\n\n\ns\
ub install_source_package\n  {\n    my ($pg)=(@_);\
\n    my ($report, $download, $arguments, $languag\
e, $address, $name, $ext, $main_dir, $distrib);\n \
   my $wget_tmp=\"$TMP/wget.tmp\";\n    my (@fl);\\
n    if ( -e \"$BIN/$pg\" || -e \"$BIN/$pg.exe\"){\
return 1;}\n    \n    #\n    # check if the module\
 exists in the repository cache \n    #\n	if( repo\
_load($pg) ) {\n		return 1;\n	}\n    \n    if ($pg\
 eq \"t_coffee\")  {return   &install_t_coffee ($p\
g);}\n    elsif ($pg eq \"TMalign\"){return   &ins\
tall_TMalign ($pg);}\n    \n    chdir $DISTRIBUTIO\
NS;\n    \n    $download=$PG{$pg}{source};\n    \n\
    if (($download =~/tgz/))\n      {\n	($address,\
$name,$ext)=($download=~/(.+\\/)([^\\/]+)(\\.tgz).\
*/);\n      }\n    elsif (($download=~/tar\\.gz/))\
\n      {\n	($address,$name,$ext)=($download=~/(.+\
\\/)([^\\/]+)(\\.tar\\.gz).*/);\n      }\n    elsi\
f (($download=~/tar/))\n      {\n	($address,$name,\
$ext)=($download=~/(.+\\/)([^\\/]+)(\\.tar).*/);\n\
      }\n    else\n      {\n	($address,$name)=($do\
wnload=~/(.+\\/)([^\\/]+)/);\n	$ext=\"\";\n      }\
\n    $distrib=\"$name$ext\";\n    \n    if ( !-d \
$pg){mkdir $pg;}\n    chdir $pg;\n   \n    #get th\
e distribution if available\n    if ( -e \"$DOWNLO\
AD_DIR/$distrib\")\n      {\n	`$CP $DOWNLOAD_DIR/$\
distrib .`;\n      }\n    #UNTAR and Prepare every\
thing\n    if (!-e \"$name.tar\" && !-e \"$name\")\
\n      {\n	&check_rm ($wget_tmp);\n	print \"\\n--\
----- Downloading/Installing $pg\\n\";\n	\n	if (!-\
e $distrib && &url2file (\"$download\", \"$wget_tm\
p\")==$EXIT_SUCCESS)\n	  {\n	    \n	    `mv $wget_\
tmp $distrib`;\n	    `$CP $distrib $DOWNLOAD_DIR/`\
;\n	  }\n\n	if (!-e $distrib)\n	  {\n	    print \"\
!!!!!!! Download of $pg distribution failed\\n\";\\
n	    print \"!!!!!!! Check Address: $PG{$pg}{sour\
ce}\\n\";\n	    return 0;\n	  }\n	print \"\\n-----\
-- unzipping/untaring $name\\n\";\n	if (($ext =~/z\
/))\n	  { \n	    &flush_command (\"gunzip $name$ex\
t\");\n	    \n	  }\n	if (($ext =~/tar/) || ($ext =\
~/tgz/))\n	  {\n	    &flush_command(\"tar -xvf $na\
me.tar\");\n	  }\n      }\n    #Guess and enter th\
e distribution directory\n    @fl=ls($p);\n    for\
each my $f (@fl)\n      {\n	if (-d $f)\n	  {\n	   \
 $main_dir=$f;\n	  }\n      }\n    if (-d $main_di\
r)\n	  \n      {\n	chdir $main_dir;}\n    else\n  \
    {\n	print \"Error: $main_dir does not exist\";\
\n      }\n    print \"\\n------- Compiling/Instal\
ling $pg\\n\";\n    `make clean $SILENT`;\n    \n \
   \n    #\n    # SAP module\n    #\n    if ($pg e\
q \"sap\")\n      {\n	if (-e \"./configure\")\n	  \
{\n	    #new sap distribution\n	    \n	    &flush_\
command (\"./configure\");\n	    &flush_command (\\
"make clean\");\n	    &flush_command (\"make\");\n\
	    &check_cp (\"./src/$pg\", \"$BIN\");\n	    re\
po_store(\"./src/$pg\");\n	  }\n	else\n	  {\n	    \
#old style distribution\n	    `rm *.o sap  sap.exe\
 ./util/aa/*.o  ./util/wt/.o $SILENT`;\n	    &flus\
h_command (\"make $arguments sap\");\n	    &check_\
cp ($pg, \"$BIN\");\n	    repo_store($pg);\n	  }\n\
      }\n    \n    #\n    # CLUSTALW2 module\n    \
#\n    elsif ($pg eq \"clustalw2\")\n      {\n	&fl\
ush_command(\"./configure\");\n	&flush_command(\"m\
ake $arguments\");\n	&check_cp (\"./src/$pg\", \"$\
BIN\");\n	repo_store(\"./src/$pg\");\n      }\n\n \
   #\n    # CLUSTAL-OMEGA module\n    #\n    elsif\
 ($pg eq \"clustalo\")\n      {\n	&flush_command(\\
"./configure\");\n	&flush_command(\"make $argument\
s\");\n	&check_cp (\"./src/$pg\", \"$BIN\");\n	rep\
o_store(\"./src/$pg\");\n      }\n\n    #\n    # S\
TRIKE module\n    #\n    elsif ($pg eq \"strike\")\
\n      {\n	&flush_command(\"make $arguments\");\n\
	&check_cp (\"./bin/$pg\", \"$BIN\");\n	repo_store\
(\"./bin/$pg\");\n      }\n    \n    #\n    # FSA \
module\n    # \n    elsif ($pg eq \"fsa\")\n      \
{\n	&flush_command(\"./configure --prefix=$BIN\");\
\n	&flush_command(\"make $arguments\");\n	&flush_c\
ommand (\"make install\");\n\n	repo_store(\"fsa\",\
 \"$BIN/bin\");\n	`mv $BIN/bin/* $BIN`;\n	`rmdir $\
BIN/bin`;\n      }\n    \n    #\n    # CLUSTALW mo\
dule\n    #\n    elsif ($pg eq \"clustalw\")\n    \
  {\n	&flush_command(\"make $arguments clustalw\")\
;\n	`$CP $pg $BIN $SILENT`;\n	repo_store($pg);\n  \
    }\n    \n    #\n    # MAFFT module\n    #\n   \
 elsif ($pg eq \"mafft\")\n      {\n	my $base=cwd(\
);\n	my $c;\n	\n	#compile core\n	mkpath (\"./mafft\
/bin\");\n	mkpath (\"./mafft/lib\");\n	chdir \"$ba\
se/core\";\n	`make clean $SILENT`;\n	&flush_comman\
d (\"make $arguments\");\n	&flush_command (\"make \
install LIBDIR=../mafft/lib BINDIR=../mafft/bin\")\
;\n	\n	#compile extension\n	chdir \"$base/extensio\
ns\";\n	`make clean $SILENT`;\n	&flush_command (\"\
make $arguments\");\n	&flush_command (\"make insta\
ll LIBDIR=../mafft/lib BINDIR=../mafft/bin\");\n	\\
n	#put everything in mafft and copy the compiled s\
tuff in bin\n	chdir \"$base\";\n	if ($ROOT_INSTALL\
)\n	  {\n	    &root_run (\"You Must be Root to Ins\
tall MAFFT\\n\", \"mkdir /usr/local/mafft/;$CP maf\
ft/lib/* /usr/local/mafft;$CP mafft/lib/mafft* /us\
r/local/bin ;$CP mafft/bin/mafft /usr/local/bin/; \
\");\n	  }\n	else\n	  {\n	    `$CP mafft/lib/*  $B\
IN`;\n	    `$CP mafft/bin/mafft  $BIN`;\n	  }\n	`t\
ar -cvf mafft.tar mafft`;\n	`gzip mafft.tar`;\n	`m\
v mafft.tar.gz $BIN`;\n	\n	repo_store(\"mafft/bin/\
mafft\", \"mafft/lib/\", \"$BIN/mafft.tar.gz\");\n\
      }\n      \n    #\n    # DIALIGN-TX module\n \
   #\n    elsif ( $pg eq \"dialign-tx\" )\n      {\
\n	my $f;\n	my $base=cwd();\n\n	chdir \"./source\"\
;\n	if ($OS eq \"macosx\"){&flush_command (\"cp ma\
kefile.MAC_OS makefile\");}\n\n	&flush_command (\"\
 make CPPFLAGS='-O3 -funroll-loops' all\");\n	\n	c\
hdir \"..\";\n	&check_cp (\"./source/$pg\", \"$BIN\
\");\n	repo_store(\"./source/$pg\");\n      }\n   \
   \n    #\n    # DIALIGN-T module \n    # (is the\
 same as dialign-tx, but it is mantained for backw\
ard name compatibility with tcoffee)\n    #\n    e\
lsif ( $pg eq \"dialign-t\" )\n      {\n	my $f;\n	\
my $base=cwd();\n\n	chdir \"./source\";\n	if ($OS \
eq \"macosx\"){&flush_command (\"cp makefile.MAC_O\
S makefile\");}\n\n	&flush_command (\" make CPPFLA\
GS='-O3 -funroll-loops' all\");\n	\n	chdir \"..\";\
\n	&check_cp (\"./source/dialign-tx\", \"$BIN/dial\
ign-t\");\n	repo_store(\"$BIN/dialign-t\");	\n    \
  }      \n      \n    #\n    # POA module\n    #\\
n    elsif ($pg eq \"poa\")\n      {\n	&flush_comm\
and (\"make $arguments poa\");\n	&check_cp (\"$pg\\
", \"$BIN\");\n	repo_store(\"$pg\");\n      }\n   \
  \n     \n    #\n    # PROBCONS module\n    #\n  \
  elsif ( $pg eq \"probcons\")\n      {\n	&add_C_l\
ibraries(\"./ProbabilisticModel.h\", \"list\", \"c\
string\");\n	\n	`rm *.exe $SILENT`;\n	&flush_comma\
nd (\"make $arguments probcons\");\n	&check_cp(\"$\
pg\", \"$BIN/$pg\");\n	repo_store(\"$pg\");\n     \
 }\n      \n    #\n    # PROBCONS RNA module\n    \
#\n    elsif ( $pg eq \"probconsRNA\")\n      {\n	\
&add_C_libraries(\"./ProbabilisticModel.h\", \"lis\
t\", \"cstring\");\n	&add_C_libraries(\"./Main.cc\\
", \"iomanip\", \"cstring\",\"climits\");\n	`rm *.\
exe $SILENT`;\n	&flush_command (\"make $arguments \
probcons\");\n	&check_cp(\"probcons\", \"$BIN/$pg\\
");\n	repo_store(\"$BIN/$pg\");\n      }\n\n	#\n	#\
 MUSCLE module\n	#\n    elsif (  $pg eq \"muscle\"\
)\n      {	\n	`rm *.o muscle muscle.exe $SILENT`;\\
n	if ($OS eq \"macosx\" || $OS eq \"linux\")\n	  {\
\n	    &replace_line_in_file (\"./Makefile\", \"LD\
LIBS = -lm -static\",  \"LDLIBS = -lm\");\n	  }\n	\
elsif ($OS eq \"windows\")\n	  {\n	    &replace_li\
ne_in_file (\"./intmath.cpp\",  \"double log2e\", \
     \"double cedric_log\");\n	    &replace_line_i\
n_file (\"./intmath.cpp\",  \"double log2\",      \
 \"double log_notuse\");\n	    &replace_line_in_fi\
le (\"./intmath.cpp\",  \"double cedric_log\", \"d\
ouble log2e\");\n	  }\n	&flush_command (\"make $ar\
guments all\");\n	&check_cp(\"$pg\", \"$BIN\");\n	\
repo_store(\"$pg\");	\n      }\n      \n     #\n  \
   # MUS4 module\n     #\n     elsif (  $pg eq \"m\
us4\")\n      {\n	`rm *.o muscle muscle.exe $SILEN\
T`;\n	&flush_command (\"./mk\");\n	&check_cp(\"$pg\
\", \"$BIN\");\n	repo_store(\"$pg\");	\n      }\n \
     \n    #\n    # PCMA module\n    #\n    elsif \
( $pg eq \"pcma\")\n      {\n	if ($OS eq \"macosx\\
")\n	  {\n	    &replace_line_in_file (\"./alcomp2.\
c\", \"malloc.h\",  \"\");\n	  }\n	&flush_command \
(\"make $arguments pcma\");\n	&check_cp(\"$pg\", \\
"$BIN\");\n	repo_store(\"$pg\");	\n      }\n      \
\n    #\n    # KALIGN module\n    #\n    elsif ($p\
g eq \"kalign\")\n      {\n	&flush_command (\"./co\
nfigure\");\n	&flush_command(\"make $arguments\");\
\n	&check_cp (\"$pg\",$BIN);\n	repo_store(\"$pg\")\
;	\n      }\n      \n    #\n    # AMAP module\n   \
 #\n    elsif ( $pg eq \"amap\")\n      {\n	&add_C\
_libraries(\"./Amap.cc\", \"iomanip\", \"cstring\"\
,\"climits\");	\n	`make clean $SILENT`;\n	&flush_c\
ommand (\"make $arguments all\");\n	&check_cp (\"$\
pg\", $BIN);\n	repo_store(\"$pg\");	\n      }\n   \
   \n    #\n    # PRODA module\n    #\n    elsif (\
 $pg eq \"proda\")\n      {\n	`sed -i '' 's/int er\
rno = 0;/int errno; errno = 0;/' Main.cc`;\n	&add_\
C_libraries(\"AlignedFragment.h\", \"vector\", \"i\
ostream\", \"cstring\",\"cstdlib\");\n	&add_C_libr\
aries(\"Main.cc\", \"vector\", \"climits\");	\n	&a\
dd_C_libraries(\"Sequence.cc\", \"stdlib.h\", \"cs\
tdio\");	\n	&flush_command (\"make $arguments all\\
");\n	&check_cp (\"$pg\", $BIN);\n	repo_store(\"$p\
g\");	\n      }\n      \n    #\n    # PRANK module\
\n    #\n    elsif ( $pg eq \"prank\")\n      {\n	\
&flush_command (\"make $arguments all\");\n	&check\
_cp (\"$pg\", $BIN);\n	repo_store(\"$pg\");	\n    \
  }\n      \n    #\n    # !!!! MUSTANG module\n   \
 #\n     elsif ( $pg eq \"mustang\")\n      {\n	&f\
lush_command (\"rm ./bin/*\");\n	&flush_command (\\
"make $arguments all\");\n\n	if ( $OS=~/windows/){\
&flush_command(\"cp ./bin/* $BIN/mustang.exe\");}\\
n	else {&flush_command(\"cp ./bin/* $BIN/mustang\"\
);}\n	\n	repo_store(\"$BIN/mustang\");\n      }\n\\
n	#\n	# RNAplfold module\n	#\n    elsif ( $pg eq \\
"RNAplfold\")\n      {\n	&flush_command(\"./config\
ure\");\n	&flush_command (\"make $arguments all\")\
;\n	&check_cp(\"./Progs/RNAplfold\", \"$BIN\");\n	\
&check_cp(\"./Progs/RNAalifold\", \"$BIN\");\n	&ch\
eck_cp(\"./Progs/RNAfold\", \"$BIN\");\n	\n	repo_s\
tore(\"./Progs/RNAplfold\", \"./Progs/RNAalifold\"\
, \"./Progs/RNAfold\");\n      }\n      \n    #\n \
   # !!! RETREE module\n    #\n    elsif ( $pg eq \
\"retree\")\n      {\n	chdir \"src\";\n	&flush_com\
mand (\"cp Makefile.unx Makefile\");\n	&flush_comm\
and (\"make $arguments all\");\n	&flush_command (\\
"make put\");\n	system \"cp ../exe/* $BIN\";\n	\n	\
repo_store(\"retree\", \"../exe\");\n      }\n	\n \
   chdir $CDIR;\n    return &pg_is_installed ($pg,\
 $BIN);\n  }\n\nsub install_t_coffee\n  {\n    my \
($pg)=(@_);\n    my ($report,$cflags, $arguments, \
$language, $compiler) ;\n    #1-Install T-Coffee\n\
    chdir \"t_coffee_source\";\n    &flush_command\
 (\"make clean\");\n    print \"\\n------- Compili\
ng T-Coffee\\n\";\n    $language=$PG{$pg} {languag\
e2};\n    $arguments=$PG{$language}{arguments};\n\\
n    if ( $CC ne \"\"){\n      print \"make -i $ar\
guments t_coffee \\n\";\n      &flush_command (\"m\
ake -i $arguments t_coffee\");\n    }\n    &check_\
cp ($pg, $BIN);\n    \n    chdir $CDIR;\n    retur\
n &pg_is_installed ($pg, $BIN);\n  }\nsub install_\
TMalign\n  {\n    my ($pg)=(@_);\n    my $report;\\
n    chdir \"t_coffee_source\";\n    print \"\\n--\
----- Compiling TMalign\\n\";\n    `rm TMalign TMa\
lign.exe $SILENT`;\n    if ( $FC ne \"\"){&flush_c\
ommand (\"make -i $PG{Fortran}{arguments} TMalign\\
");}\n    &check_cp ($pg, $BIN);\n    repo_store($\
pg);\n\n    if ( !-e \"$BIN/$pg\" && pg_has_binary\
_distrib ($pg))\n      {\n	print \"!!!!!!! Compila\
tion of $pg impossible. Will try to install from b\
inary\\n\";\n	return &install_binary_package ($pg)\
;\n      }\n    chdir $CDIR;\n    return &pg_is_in\
stalled ($pg, $BIN);\n  }\n\nsub pg_has_binary_dis\
trib\n  {\n    my ($pg)=(@_);\n    if ($PG{$pg}{wi\
ndows}){return 1;}\n    elsif ($PG{$pg}{osx}){retu\
rn 1;}\n    elsif ($PG{$pg}{linux}){return 1;}\n  \
  return 0;\n  }\nsub install_binary_package\n  {\\
n    my ($pg)=(@_);\n    my ($base,$report,$name, \
$download, $arguments, $language, $dir);\n    my $\
isdir;\n    &input_os();\n    \n    #\n    # - pao\
lodt - Check if the module exists in the repositor\
y cache \n    #\n	if( repo_load($pg) ) {\n	    $PG\
{$pg}{from_binary}=1;\n		return 1;\n	}\n    # - pa\
olodt - end \n    \n    if (!&supported_os($OS)){r\
eturn 0;}\n    if ( $PG{$pg}{binary}){$name=$PG{$p\
g}{binary};}\n    else {$name=$pg;}\n    \n    $do\
wnload=\"$WEB_BASE/Packages/Binaries/$OS/$name\";\\
n    \n    $base=cwd();\n    chdir $TMP;\n    \n  \
  if (!-e $name)\n      {\n	`rm x $SILENT`;\n	if (\
 url2file(\"$download\",\"x\")==$EXIT_SUCCESS)\n	 \
 {\n	    `mv x $name`;\n	  }\n      }\n    \n    i\
f (!-e $name)\n      {\n	print \"!!!!!!! $PG{$pg}{\
dname}: Download of $pg binary failed\\n\";\n	prin\
t \"!!!!!!! $PG{$pg}{dname}: Check Address: $downl\
oad\\n\";\n	return 0;\n      }\n    print \"\\n---\
---- Installing $pg\\n\";\n    \n    if ($name =~/\
tar\\.gz/)\n      {\n	`gunzip  $name`;\n	`tar -xvf\
 $pg.tar`;\n	chdir $pg;\n	`chmod u+x *`;\n 	`mv * \
$BIN`;\n	#if (!($pg=~/\\*/)){`rm -rf $pg`;}\n     \
 }\n    else\n      {\n	&check_cp (\"$pg\", \"$BIN\
\");\n	`chmod u+x $BIN/$pg`; \n	unlink ($pg);\n   \
   }\n    chdir $base;\n    $PG{$pg}{from_binary}=\
1;\n    return &pg_is_installed ($pg, $BIN);\n  }\\
n\nsub add_dir \n  {\n    my $dir=@_[0];\n    \n  \
  if (!-e $dir && !-d $dir)\n      {\n	my @l;\n	um\
ask (0000);\n	@l=mkpath ($dir,{mode => 0777});\n	\\
n      }\n    else\n      {\n	return 0;\n      }\n\
  }\nsub check_rm \n  {\n    my ($file)=(@_);\n   \
 \n    if ( -e $file)\n      {\n	return unlink($fi\
le);\n      }\n    return 0;\n  }\nsub check_cp\n \
 {\n    my ($from, $to)=(@_);\n    if ( !-e $from \
&& -e \"$from\\.exe\"){$from=\"$from\\.exe\";}\n  \
  if ( !-e $from){return 0;}\n        \n    `$CP $\
from $to`;\n    return 1;\n  }\n\nsub repo_store \\
n{\n   # check that all required data are availabl\
e\n   if( $REPO_ROOT eq \"\" ) { return; }\n\n\n  \
  # extract the package name from the specified pa\
th\n    my $pg =`basename $_[0]`;\n    chomp($pg);\
\n	\n    my $VER = $PG{$pg}{version};\n    my $CAC\
HE = \"$REPO_ROOT/$pg/$VER/$OSNAME-$OSARCH\"; \n  \
  \n    print \"-------- Storing package: \\\"$pg\\
\\" to path: $CACHE\\n\";\n    \n    # clean the c\
ache path if exists and create it again\n    `rm -\
rf $CACHE`;\n    `mkdir -p $CACHE`;\n    \n 	for m\
y $path (@_) {\n\n	    # check if it is a single f\
ile \n	 	if( -f $path ) {\n	    	`cp $path $CACHE`\
;\n		}\n		# .. or a directory, in this case copy a\
ll the content \n		elsif( -d $path ) {\n			opendir\
(IMD, $path);\n			my @thefiles= readdir(IMD);\n			\
closedir(IMD);\n			\n			for my $_file (@thefiles) \
{\n				if( $_file ne \".\" && $_file ne \"..\") {\\
n	    			`cp $path/$_file $CACHE`;\n				}\n			}\n	\
	} \n	}	   \n    \n	\n}   \n\nsub repo_load \n{\n \
   my ($pg)=(@_);\n\n    #Bypass the Repository Ca\
che\n    return 0;\n    # check that all required \
data are available\n    if( $REPO_ROOT eq \"\" ) {\
 return 0; }\n\n    my $VER = $PG{$pg}{version};\n\
    my $CACHE = \"$REPO_ROOT/$pg/$VER/$OSNAME-$OSA\
RCH\"; \n    if( !-e \"$CACHE/$pg\" ) {\n   	 	pri\
nt \"-------- Module \\\"$pg\\\" NOT found on repo\
sitory cache.\\n\";\n    	return 0;\n    }\n    \n\
    print \"-------- Module \\\"$pg\\\" found on r\
epository cache. Using copy on path: $CACHE\\n\";\\
n    `cp $CACHE/* $BIN`;\n    return 1;\n}\n\nsub \
check_file_list_exists \n  {\n    my ($base, @flis\
t)=(@_);\n    my $f;\n\n    foreach $f (@flist)\n \
     {\n	if ( !-e \"$base/$f\"){return 0;}\n      \
}\n    return 1;\n  }\nsub ls\n  {\n    my $f=@_[0\
];\n    my @fl;\n    chomp(@fl=`ls -1 $f`);\n    r\
eturn @fl;\n  }\nsub flush_command\n  {\n    my $c\
ommand=@_[0];\n    my $F=new FileHandle;\n    open\
 ($F, \"$command|\");\n    while (<$F>){print \"  \
  --- $_\";}\n    close ($F);\n  }    \n\nsub inpu\
t_installation_directory\n  {\n    my $dir=@_[0];\\
n    my $new;\n    \n    print \"------- The curre\
nt installation directory is: [$dir]\\n\";\n    pr\
int \"??????? Return to keep the default or new va\
lue:\";\n   \n    if ($NO_QUESTION==0)\n      {\n	\
chomp ($new=<stdin>);\n	while ( $new ne \"\" && !i\
nput_yes (\"You have entered $new. Is this correct\
? ([y]/n):\"))\n	  {\n	    print \"???????New inst\
allation directory:\";\n	    chomp ($new=<stdin>);\
\n	  }\n	$dir=($new eq \"\")?$dir:$new;\n	$dir=~s/\
\\/$//;\n      }\n    \n    if ( -d $dir){return $\
dir;}\n    elsif (&root_run (\"You must be root to\
 create $dir\",\"mkdir $dir\")==$EXIT_SUCCESS){ret\
urn $dir;}\n    else\n      {\n	print \"!!!!!!! $d\
ir could not be created\\n\";\n	if ( $NO_QUESTION)\
\n	  {\n	    return \"\";\n	  }\n	elsif ( &input_y\
es (\"??????? Do you want to provide a new directo\
ry([y]/n)?:\"))\n	  {\n	    return input_installat\
ion_directory ($dir);\n	  }\n	else\n	  {\n	    ret\
urn \"\";\n	  }\n      }\n    \n  }\nsub input_yes\
\n  {\n    my $question =@_[0];\n    my $answer;\n\
\n    if ($NO_QUESTION==1){return 1;}\n    \n    i\
f ($question eq \"\"){$question=\"??????? Do you w\
ish to proceed ([y]/n)?:\";}\n    print $question;\
\n    chomp($answer=lc(<STDIN>));\n    if (($answe\
r=~/^y/) || $answer eq \"\"){return 1;}\n    elsif\
 ( ($answer=~/^n/)){return 0;}\n    else\n      {\\
n	return input_yes($question);\n      }\n  }\nsub \
root_run\n  {\n    my ($txt, $cmd)=(@_);\n    \n  \
  if ( system ($cmd)==$EXIT_SUCCESS){return $EXIT_\
SUCCESS;}\n    else \n      {\n	print \"------- $t\
xt\\n\";\n	if ( $ROOT eq \"sudo\"){return system (\
\"sudo $cmd\");}\n	else {return system (\"su root \
-c \\\"$cmd\\\"\");}\n      }\n  }\nsub get_root\n\
  {\n    if (&pg_is_installed (\"sudo\")){return \\
"sudo\";}\n    else {return \"su\";}\n  }\n\nsub g\
et_os\n  {\n    my $raw_os=`uname`;\n    my $os;\n\
\n    $raw_os=lc ($raw_os);\n    \n    if ($raw_os\
 =~/cygwin/){$os=\"windows\";}\n    elsif ($raw_os\
 =~/linux/){$os=\"linux\";}\n    elsif ($raw_os =~\
/osx/){$os=\"macosx\";}\n    elsif ($raw_os =~/dar\
win/){$os=\"macosx\";}\n    else\n      {\n	$os=$r\
aw_os;\n      }\n    return $os;\n  }\nsub input_o\
s\n  {\n    my $answer;\n    if ($OS) {return $OS;\
}\n    \n    print \"??????? which os do you use: \
[w]indows, [l]inux, [m]acosx:?\";\n    $answer=lc(\
<STDIN>);\n\n    if (($answer=~/^m/)){$OS=\"macosx\
\";}\n    elsif ( ($answer=~/^w/)){$OS=\"windows\"\
;}\n    elsif ( ($answer=~/^linux/)){$OS=\"linux\"\
;}\n    \n    else\n      {\n	return &input_os();\\
n      }\n    return $OS;\n  }\n\nsub supported_os\
\n  {\n    my ($os)=(@_[0]);\n    return $SUPPORTE\
D_OS{$os};\n  }\n    \n    \n\n\nsub update_tclink\
db \n  {\n    my $file =@_[0];\n    my $name;\n   \
 my $F=new FileHandle;\n    my ($download, $addres\
s, $name, $l, $db);\n    \n    if ( $file eq \"upd\
ate\"){$file=$TCLINKDB_ADDRESS;}\n    \n    if ( $\
file =~/http:\\/\\// || $file =~/ftp:\\/\\//)\n   \
   {\n	($address, $name)=($download=~/(.*)\\/([^\\\
/]+)$/);\n	`rm x $SILENT`;\n	if (&url2file ($file,\
\"x\")==$EXIT_SUCCESS)\n	  {\n	    print \"-------\
 Susscessful upload of $name\";\n	    `mv x $name`\
;\n	    $file=$name;\n	  }\n      }\n    open ($F,\
 \"$file\");\n    while (<$F>)\n      {\n	my $l=$_\
;\n	if (($l =~/^\\/\\//) || ($db=~/^#/)){;}\n	elsi\
f ( !($l =~/\\w/)){;}\n	else\n	  {\n	    my @v=spl\
it (/\\s+/, $l);\n	    if ( $l=~/^MODE/)\n	      {\
\n		$MODE{$v[1]}{$v[2]}=$v[3];\n	      }\n	    els\
if ($l=~/^PG/)\n	      {\n		$PG{$v[1]}{$v[2]}=$v[3\
];\n	      }\n	  }\n      }\n    close ($F);\n    \
&post_process_PG();\n    return;\n  }\n\n\n\nsub i\
nitialize_PG\n  {\n\n$PG{\"t_coffee\"}{\"4_TCOFFEE\
\"}=\"TCOFFEE\";\n$PG{\"t_coffee\"}{\"type\"}=\"se\
quence_multiple_aligner\";\n$PG{\"t_coffee\"}{\"AD\
DRESS\"}=\"http://www.tcoffee.org\";\n$PG{\"t_coff\
ee\"}{\"language\"}=\"C++\";\n$PG{\"t_coffee\"}{\"\
language2\"}=\"CXX\";\n$PG{\"t_coffee\"}{\"source\\
"}=\"http://www.tcoffee.org/Packages/Stable/Latest\
/T-COFFEE_distribution.tar.gz\";\n$PG{\"t_coffee\"\
}{\"update_action\"}=\"always\";\n$PG{\"t_coffee\"\
}{\"mode\"}=\"tcoffee,mcoffee,rcoffee,expresso,3dc\
offee\";\n$PG{\"clustalo\"}{\"4_TCOFFEE\"}=\"CLUST\
ALO\";\n$PG{\"clustalo\"}{\"type\"}=\"sequence_mul\
tiple_aligner\";\n$PG{\"clustalo\"}{\"ADDRESS\"}=\\
"http://www.clustal.org/omega/\";\n$PG{\"clustalo\\
"}{\"language\"}=\"C++\";\n$PG{\"clustalo\"}{\"lan\
guage2\"}=\"C++\";\n$PG{\"clustalo\"}{\"source\"}=\
\"http://www.clustal.org/omega/clustal-omega-1.2.4\
.tar.gz\";\n$PG{\"clustalo\"}{\"mode\"}=\"mcoffee\\
";\n$PG{\"clustalo\"}{\"binary\"}=\"clustalo\";\n$\
PG{\"clustalo\"}{\"version\"}=\"1.2.4\";\n$PG{\"st\
rike\"}{\"4_TCOFFEE\"}=\"STRIKE\";\n$PG{\"strike\"\
}{\"type\"}=\"sequence_alignment_scoring\";\n$PG{\\
"strike\"}{\"ADDRESS\"}=\"http://www.tcoffee.org/P\
rojects/strike/index.html\";\n$PG{\"strike\"}{\"la\
nguage\"}=\"C++\";\n$PG{\"strike\"}{\"language2\"}\
=\"CXX\";\n$PG{\"strike\"}{\"source\"}=\"http://ww\
w.tcoffee.org/Projects/strike/strike_v1.2.tar.bz2\\
";\n$PG{\"strike\"}{\"mode\"}=\"tcoffee,expresso\"\
;\n$PG{\"strike\"}{\"version\"}=\"1.2\";\n$PG{\"cl\
ustalw2\"}{\"4_TCOFFEE\"}=\"CLUSTALW2\";\n$PG{\"cl\
ustalw2\"}{\"type\"}=\"sequence_multiple_aligner\"\
;\n$PG{\"clustalw2\"}{\"ADDRESS\"}=\"http://www.cl\
ustal.org\";\n$PG{\"clustalw2\"}{\"language\"}=\"C\
++\";\n$PG{\"clustalw2\"}{\"language2\"}=\"CXX\";\\
n$PG{\"clustalw2\"}{\"source\"}=\"http://www.clust\
al.org/download/2.0.10/clustalw-2.0.10-src.tar.gz\\
";\n$PG{\"clustalw2\"}{\"mode\"}=\"mcoffee,rcoffee\
\";\n$PG{\"clustalw2\"}{\"version\"}=\"2.0.10\";\n\
$PG{\"clustalw\"}{\"4_TCOFFEE\"}=\"CLUSTALW\";\n$P\
G{\"clustalw\"}{\"type\"}=\"sequence_multiple_alig\
ner\";\n$PG{\"clustalw\"}{\"ADDRESS\"}=\"http://ww\
w.clustal.org\";\n$PG{\"clustalw\"}{\"language\"}=\
\"C\";\n$PG{\"clustalw\"}{\"language2\"}=\"C\";\n$\
PG{\"clustalw\"}{\"source\"}=\"http://www.clustal.\
org/download/1.X/ftp-igbmc.u-strasbg.fr/pub/Clusta\
lW/clustalw1.82.UNIX.tar.gz\";\n$PG{\"clustalw\"}{\
\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\"clustalw\"}{\
\"version\"}=\"1.82\";\n$PG{\"dialign-t\"}{\"4_TCO\
FFEE\"}=\"DIALIGNT\";\n$PG{\"dialign-t\"}{\"type\"\
}=\"sequence_multiple_aligner\";\n$PG{\"dialign-t\\
"}{\"ADDRESS\"}=\"http://dialign-tx.gobics.de/\";\\
n$PG{\"dialign-t\"}{\"DIR\"}=\"/usr/share/dialign-\
tx/\";\n$PG{\"dialign-t\"}{\"language\"}=\"C\";\n$\
PG{\"dialign-t\"}{\"language2\"}=\"C\";\n$PG{\"dia\
lign-t\"}{\"source\"}=\"http://dialign-tx.gobics.d\
e/DIALIGN-TX_1.0.2.tar.gz\";\n$PG{\"dialign-t\"}{\\
"mode\"}=\"mcoffee\";\n$PG{\"dialign-t\"}{\"binary\
\"}=\"dialign-t\";\n$PG{\"dialign-t\"}{\"version\"\
}=\"1.0.2\";\n$PG{\"dialign-tx\"}{\"4_TCOFFEE\"}=\\
"DIALIGNTX\";\n$PG{\"dialign-tx\"}{\"type\"}=\"seq\
uence_multiple_aligner\";\n$PG{\"dialign-tx\"}{\"A\
DDRESS\"}=\"http://dialign-tx.gobics.de/\";\n$PG{\\
"dialign-tx\"}{\"DIR\"}=\"/usr/share/dialign-tx/\"\
;\n$PG{\"dialign-tx\"}{\"language\"}=\"C\";\n$PG{\\
"dialign-tx\"}{\"language2\"}=\"C\";\n$PG{\"dialig\
n-tx\"}{\"source\"}=\"http://dialign-tx.gobics.de/\
DIALIGN-TX_1.0.2.tar.gz\";\n$PG{\"dialign-tx\"}{\"\
mode\"}=\"mcoffee\";\n$PG{\"dialign-tx\"}{\"binary\
\"}=\"dialign-tx\";\n$PG{\"dialign-tx\"}{\"version\
\"}=\"1.0.2\";\n$PG{\"poa\"}{\"4_TCOFFEE\"}=\"POA\\
";\n$PG{\"poa\"}{\"type\"}=\"sequence_multiple_ali\
gner\";\n$PG{\"poa\"}{\"ADDRESS\"}=\"http://www.bi\
oinformatics.ucla.edu/poa/\";\n$PG{\"poa\"}{\"lang\
uage\"}=\"C\";\n$PG{\"poa\"}{\"language2\"}=\"C\";\
\n$PG{\"poa\"}{\"source\"}=\"http://downloads.sour\
ceforge.net/poamsa/poaV2.tar.gz\";\n$PG{\"poa\"}{\\
"DIR\"}=\"/usr/share/\";\n$PG{\"poa\"}{\"FILE1\"}=\
\"blosum80.mat\";\n$PG{\"poa\"}{\"mode\"}=\"mcoffe\
e\";\n$PG{\"poa\"}{\"binary\"}=\"poa\";\n$PG{\"poa\
\"}{\"version\"}=\"2.0\";\n$PG{\"probcons\"}{\"4_T\
COFFEE\"}=\"PROBCONS\";\n$PG{\"probcons\"}{\"type\\
"}=\"sequence_multiple_aligner\";\n$PG{\"probcons\\
"}{\"ADDRESS\"}=\"http://probcons.stanford.edu/\";\
\n$PG{\"probcons\"}{\"language2\"}=\"CXX\";\n$PG{\\
"probcons\"}{\"language\"}=\"C++\";\n$PG{\"probcon\
s\"}{\"source\"}=\"http://probcons.stanford.edu/pr\
obcons_v1_12.tar.gz\";\n$PG{\"probcons\"}{\"mode\"\
}=\"mcoffee\";\n$PG{\"probcons\"}{\"binary\"}=\"pr\
obcons\";\n$PG{\"probcons\"}{\"version\"}=\"1.12\"\
;\n$PG{\"msaprobs\"}{\"4_TCOFFEE\"}=\"MSAPROBS\";\\
n$PG{\"msaprobs\"}{\"type\"}=\"sequence_multiple_a\
ligner\";\n$PG{\"msaprobs\"}{\"ADDRESS\"}=\"http:/\
/msaprobs.sourceforge.net/homepage.htm#latest\";\n\
$PG{\"msaprobs\"}{\"language2\"}=\"CXX\";\n$PG{\"m\
saprobs\"}{\"language\"}=\"C++\";\n$PG{\"msaprobs\\
"}{\"source\"}=\"https://sourceforge.net/projects/\
msaprobs/files/MSAProbs-MPI/MSAProbs-MPI_rel1.0.5.\
tar.gz\";\n$PG{\"msaprobs\"}{\"mode\"}=\"mcoffee\"\
;\n$PG{\"msaprobs\"}{\"binary\"}=\"msaprobs\";\n$P\
G{\"msaprobs\"}{\"version\"}=\"1.05\";\n$PG{\"msap\
robs\"}{\"update_action\"}=\"never\";\n$PG{\"upp\"\
}{\"4_TCOFFEE\"}=\"UPP\";\n$PG{\"upp\"}{\"type\"}=\
\"sequence_multiple_aligner\";\n$PG{\"upp\"}{\"ADD\
RESS\"}=\"http://www.cs.utexas.edu/users/phylo/sof\
tware/upp/\";\n$PG{\"upp\"}{\"language2\"}=\"CXX\"\
;\n$PG{\"upp\"}{\"language\"}=\"C++\";\n$PG{\"upp\\
"}{\"source\"}=\"https://github.com/smirarab/pasta\
/archive/upp.zip\";\n$PG{\"upp\"}{\"mode\"}=\"mcof\
fee\";\n$PG{\"upp\"}{\"binary\"}=\"upp\";\n$PG{\"u\
pp\"}{\"version\"}=\"1\";\n$PG{\"upp\"}{\"update_a\
ction\"}=\"never\";\n$PG{\"mafft\"}{\"4_TCOFFEE\"}\
=\"MAFFT\";\n$PG{\"mafft\"}{\"type\"}=\"sequence_m\
ultiple_aligner\";\n$PG{\"mafft\"}{\"ADDRESS\"}=\"\
http://align.bmr.kyushu-u.ac.jp/mafft/online/serve\
r/\";\n$PG{\"mafft\"}{\"language\"}=\"C\";\n$PG{\"\
mafft\"}{\"language\"}=\"C\";\n$PG{\"mafft\"}{\"so\
urce\"}=\"http://mafft.cbrc.jp/alignment/software/\
mafft-7.310-with-extensions-src.tgz\";\n$PG{\"maff\
t\"}{\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\"mafft\"\
}{\"binary\"}=\"mafft.tar.gz\";\n$PG{\"mafft\"}{\"\
version\"}=\"7.310\";\n$PG{\"msa\"}{\"4_TCOFFEE\"}\
=\"MSA\";\n$PG{\"msa\"}{\"type\"}=\"sequence_multi\
ple_aligner\";\n$PG{\"msa\"}{\"ADDRESS\"}=\"https:\
//www.ncbi.nlm.nih.gov/CBBresearch/Schaffer/msa.ht\
ml\";\n$PG{\"msa\"}{\"language\"}=\"C\";\n$PG{\"ms\
a\"}{\"language\"}=\"C\";\n$PG{\"msa\"}{\"source\"\
}=\"ftp://ftp.ncbi.nih.gov/pub/msa/msa.tar.Z\";\n$\
PG{\"msa\"}{\"mode\"}=\"mcoffee\";\n$PG{\"msa\"}{\\
"binary\"}=\"msa.pl\";\n$PG{\"msa\"}{\"version\"}=\
\"1.0\";\n$PG{\"msa\"}{\"update_action\"}=\"never\\
";\n$PG{\"dca\"}{\"4_TCOFFEE\"}=\"DCA\";\n$PG{\"dc\
a\"}{\"type\"}=\"sequence_multiple_aligner\";\n$PG\
{\"dca\"}{\"ADDRESS\"}=\"https://bibiserv2.cebitec\
.uni-bielefeld.de/dca\";\n$PG{\"dca\"}{\"language\\
"}=\"C\";\n$PG{\"dca\"}{\"language\"}=\"C\";\n$PG{\
\"dca\"}{\"source\"}=\"https://bibiserv2.cebitec.u\
ni-bielefeld.de/applications/dca/resources/downloa\
ds/dca-1.1-src.tar.gz\";\n$PG{\"dca\"}{\"mode\"}=\\
"mcoffee\";\n$PG{\"dca\"}{\"binary\"}=\"dca.pl\";\\
n$PG{\"dca\"}{\"version\"}=\"1.1\";\n$PG{\"dca\"}{\
\"update_action\"}=\"never\";\n$PG{\"muscle\"}{\"4\
_TCOFFEE\"}=\"MUSCLE\";\n$PG{\"muscle\"}{\"type\"}\
=\"sequence_multiple_aligner\";\n$PG{\"muscle\"}{\\
"ADDRESS\"}=\"http://www.drive5.com/muscle/\";\n$P\
G{\"muscle\"}{\"language\"}=\"C++\";\n$PG{\"muscle\
\"}{\"language2\"}=\"GPP\";\n$PG{\"muscle\"}{\"sou\
rce\"}=\"http://www.drive5.com/muscle/downloads3.7\
/muscle3.7_src.tar.gz\";\n$PG{\"muscle\"}{\"window\
s\"}=\"http://www.drive5.com/muscle/downloads3.7/m\
uscle3.7_win32.zip\";\n$PG{\"muscle\"}{\"linux\"}=\
\"http://www.drive5.com/muscle/downloads3.7/muscle\
3.7_linux_ia32.tar.gz\";\n$PG{\"muscle\"}{\"mode\"\
}=\"mcoffee,rcoffee\";\n$PG{\"muscle\"}{\"version\\
"}=\"3.7\";\n$PG{\"pcma\"}{\"4_TCOFFEE\"}=\"PCMA\"\
;\n$PG{\"pcma\"}{\"type\"}=\"sequence_multiple_ali\
gner\";\n$PG{\"pcma\"}{\"ADDRESS\"}=\"http://proda\
ta.swmed.edu/pcma/pcma.php\";\n$PG{\"pcma\"}{\"lan\
guage\"}=\"C\";\n$PG{\"pcma\"}{\"language2\"}=\"C\\
";\n$PG{\"pcma\"}{\"source\"}=\"http://prodata.swm\
ed.edu/download/pub/PCMA/pcma.tar.gz\";\n$PG{\"pcm\
a\"}{\"mode\"}=\"mcoffee\";\n$PG{\"pcma\"}{\"versi\
on\"}=\"1.0\";\n$PG{\"kalign\"}{\"4_TCOFFEE\"}=\"K\
ALIGN\";\n$PG{\"kalign\"}{\"type\"}=\"sequence_mul\
tiple_aligner\";\n$PG{\"kalign\"}{\"ADDRESS\"}=\"h\
ttp://msa.cgb.ki.se\";\n$PG{\"kalign\"}{\"language\
\"}=\"C\";\n$PG{\"kalign\"}{\"language2\"}=\"C\";\\
n$PG{\"kalign\"}{\"source\"}=\"http://msa.cgb.ki.s\
e/downloads/kalign/current.tar.gz\";\n$PG{\"kalign\
\"}{\"mode\"}=\"mcoffee\";\n$PG{\"kalign\"}{\"vers\
ion\"}=\"1.0\";\n$PG{\"amap\"}{\"4_TCOFFEE\"}=\"AM\
AP\";\n$PG{\"amap\"}{\"type\"}=\"sequence_multiple\
_aligner\";\n$PG{\"amap\"}{\"ADDRESS\"}=\"http://b\
io.math.berkeley.edu/amap/\";\n$PG{\"amap\"}{\"lan\
guage\"}=\"C++\";\n$PG{\"amap\"}{\"language2\"}=\"\
CXX\";\n$PG{\"amap\"}{\"source\"}=\"https://github\
.com/mes5k/amap-align/archive/amap.zip\";\n$PG{\"a\
map\"}{\"mode\"}=\"mcoffee\";\n$PG{\"amap\"}{\"ver\
sion\"}=\"2.0\";\n$PG{\"amap\"}{\"update_action\"}\
=\"never\";\n$PG{\"proda\"}{\"4_TCOFFEE\"}=\"PRODA\
\";\n$PG{\"proda\"}{\"type\"}=\"sequence_multiple_\
aligner\";\n$PG{\"proda\"}{\"ADDRESS\"}=\"http://p\
roda.stanford.edu\";\n$PG{\"proda\"}{\"language\"}\
=\"C++\";\n$PG{\"proda\"}{\"language2\"}=\"CXX\";\\
n$PG{\"proda\"}{\"source\"}=\"http://proda.stanfor\
d.edu/proda_1_0.tar.gz\";\n$PG{\"proda\"}{\"mode\"\
}=\"mcoffee\";\n$PG{\"proda\"}{\"version\"}=\"1.0\\
";\n$PG{\"prank\"}{\"4_TCOFFEE\"}=\"PRANK\";\n$PG{\
\"prank\"}{\"type\"}=\"sequence_multiple_aligner\"\
;\n$PG{\"prank\"}{\"ADDRESS\"}=\"http://www.ebi.ac\
.uk/goldman-srv/prank/\";\n$PG{\"prank\"}{\"langua\
ge\"}=\"C++\";\n$PG{\"prank\"}{\"language2\"}=\"CX\
X\";\n$PG{\"prank\"}{\"source\"}=\"http://www.ebi.\
ac.uk/goldman-srv/prank/src/prank/prank.src.100802\
.tgz\";\n$PG{\"prank\"}{\"mode\"}=\"mcoffee\";\n$P\
G{\"prank\"}{\"version\"}=\"100303\";\n$PG{\"sap\"\
}{\"4_TCOFFEE\"}=\"SAP\";\n$PG{\"sap\"}{\"type\"}=\
\"structure_pairwise_aligner\";\n$PG{\"sap\"}{\"AD\
DRESS\"}=\"https://mathbio.crick.ac.uk/wiki/Softwa\
re#SAP\";\n$PG{\"sap\"}{\"language\"}=\"C\";\n$PG{\
\"sap\"}{\"language2\"}=\"C\";\n$PG{\"sap\"}{\"sou\
rce\"}=\"https://github.com/jkleinj/SAP/archive/v.\
1.1.3.tar.gz\";\n$PG{\"sap\"}{\"mode\"}=\"expresso\
,3dcoffee\";\n$PG{\"sap\"}{\"version\"}=\"1.1.3\";\
\n$PG{\"TMalign\"}{\"4_TCOFFEE\"}=\"TMALIGN\";\n$P\
G{\"TMalign\"}{\"type\"}=\"structure_pairwise_alig\
ner\";\n$PG{\"TMalign\"}{\"ADDRESS\"}=\"http://zha\
nglab.ccmb.med.umich.edu/TM-align/TMalign.f\";\n$P\
G{\"TMalign\"}{\"language\"}=\"Fortran\";\n$PG{\"T\
Malign\"}{\"language2\"}=\"Fortran\";\n$PG{\"TMali\
gn\"}{\"source\"}=\"http://zhanglab.ccmb.med.umich\
.edu/TM-align/TMalign.f\";\n$PG{\"TMalign\"}{\"lin\
ux\"}=\"http://zhanglab.ccmb.med.umich.edu/TM-alig\
n/TMalign_32.gz\";\n$PG{\"TMalign\"}{\"mode\"}=\"e\
xpresso,3dcoffee\";\n$PG{\"TMalign\"}{\"version\"}\
=\"2013.05.11\";\n$PG{\"mustang\"}{\"4_TCOFFEE\"}=\
\"MUSTANG\";\n$PG{\"mustang\"}{\"type\"}=\"structu\
re_pairwise_aligner\";\n$PG{\"mustang\"}{\"ADDRESS\
\"}=\"http://lcb.infotech.monash.edu.au/mustang/\"\
;\n$PG{\"mustang\"}{\"language\"}=\"C++\";\n$PG{\"\
mustang\"}{\"language2\"}=\"CXX\";\n$PG{\"mustang\\
"}{\"source\"}=\"http://lcb.infotech.monash.edu.au\
/mustang/mustang_v3.2.3.tgz\";\n$PG{\"mustang\"}{\\
"mode\"}=\"expresso,3dcoffee\";\n$PG{\"mustang\"}{\
\"version\"}=\"3.2.3\";\n$PG{\"lsqman\"}{\"4_TCOFF\
EE\"}=\"LSQMAN\";\n$PG{\"lsqman\"}{\"type\"}=\"str\
ucture_pairwise_aligner\";\n$PG{\"lsqman\"}{\"ADDR\
ESS\"}=\"empty\";\n$PG{\"lsqman\"}{\"language\"}=\\
"empty\";\n$PG{\"lsqman\"}{\"language2\"}=\"empty\\
";\n$PG{\"lsqman\"}{\"source\"}=\"empty\";\n$PG{\"\
lsqman\"}{\"update_action\"}=\"never\";\n$PG{\"lsq\
man\"}{\"mode\"}=\"expresso,3dcoffee\";\n$PG{\"ali\
gn_pdb\"}{\"4_TCOFFEE\"}=\"ALIGN_PDB\";\n$PG{\"ali\
gn_pdb\"}{\"type\"}=\"structure_pairwise_aligner\"\
;\n$PG{\"align_pdb\"}{\"ADDRESS\"}=\"empty\";\n$PG\
{\"align_pdb\"}{\"language\"}=\"empty\";\n$PG{\"al\
ign_pdb\"}{\"language2\"}=\"empty\";\n$PG{\"align_\
pdb\"}{\"source\"}=\"empty\";\n$PG{\"align_pdb\"}{\
\"update_action\"}=\"never\";\n$PG{\"align_pdb\"}{\
\"mode\"}=\"expresso,3dcoffee\";\n$PG{\"fugueali\"\
}{\"4_TCOFFEE\"}=\"FUGUE\";\n$PG{\"fugueali\"}{\"t\
ype\"}=\"structure_pairwise_aligner\";\n$PG{\"fugu\
eali\"}{\"ADDRESS\"}=\"http://mizuguchilab.org/fug\
ue/\";\n$PG{\"fugueali\"}{\"language\"}=\"empty\";\
\n$PG{\"fugueali\"}{\"language2\"}=\"empty\";\n$PG\
{\"fugueali\"}{\"source\"}=\"empty\";\n$PG{\"fugue\
ali\"}{\"update_action\"}=\"never\";\n$PG{\"fuguea\
li\"}{\"mode\"}=\"expresso,3dcoffee\";\n$PG{\"dali\
lite.pl\"}{\"4_TCOFFEE\"}=\"DALILITEc\";\n$PG{\"da\
lilite.pl\"}{\"type\"}=\"structure_pairwise_aligne\
r\";\n$PG{\"dalilite.pl\"}{\"ADDRESS\"}=\"built_in\
\";\n$PG{\"dalilite.pl\"}{\"ADDRESS2\"}=\"http://w\
ww.ebi.ac.uk/Tools/webservices/services/dalilite\"\
;\n$PG{\"dalilite.pl\"}{\"language\"}=\"Perl\";\n$\
PG{\"dalilite.pl\"}{\"language2\"}=\"Perl\";\n$PG{\
\"dalilite.pl\"}{\"source\"}=\"empty\";\n$PG{\"dal\
ilite.pl\"}{\"update_action\"}=\"never\";\n$PG{\"d\
alilite.pl\"}{\"mode\"}=\"expresso,3dcoffee\";\n$P\
G{\"probconsRNA\"}{\"4_TCOFFEE\"}=\"PROBCONSRNA\";\
\n$PG{\"probconsRNA\"}{\"type\"}=\"RNA_multiple_al\
igner\";\n$PG{\"probconsRNA\"}{\"ADDRESS\"}=\"http\
://probcons.stanford.edu/\";\n$PG{\"probconsRNA\"}\
{\"language\"}=\"C++\";\n$PG{\"probconsRNA\"}{\"la\
nguage2\"}=\"CXX\";\n$PG{\"probconsRNA\"}{\"source\
\"}=\"http://probcons.stanford.edu/probconsRNA.tar\
.gz\";\n$PG{\"probconsRNA\"}{\"mode\"}=\"mcoffee,r\
coffee\";\n$PG{\"probconsRNA\"}{\"version\"}=\"1.0\
\";\n$PG{\"sfold\"}{\"4_TCOFFEE\"}=\"CONSAN\";\n$P\
G{\"sfold\"}{\"type\"}=\"RNA_pairwise_aligner\";\n\
$PG{\"sfold\"}{\"ADDRESS\"}=\"http://selab.janelia\
.org/software/consan/\";\n$PG{\"sfold\"}{\"languag\
e\"}=\"empty\";\n$PG{\"sfold\"}{\"language2\"}=\"e\
mpty\";\n$PG{\"sfold\"}{\"source\"}=\"empty\";\n$P\
G{\"sfold\"}{\"update_action\"}=\"never\";\n$PG{\"\
sfold\"}{\"mode\"}=\"rcoffee\";\n$PG{\"RNAplfold\"\
}{\"4_TCOFFEE\"}=\"RNAPLFOLD\";\n$PG{\"RNAplfold\"\
}{\"type\"}=\"RNA_secondarystructure_predictor\";\\
n$PG{\"RNAplfold\"}{\"ADDRESS\"}=\"http://www.tbi.\
univie.ac.at/RNA/\";\n$PG{\"RNAplfold\"}{\"languag\
e\"}=\"C\";\n$PG{\"RNAplfold\"}{\"language2\"}=\"C\
\";\n$PG{\"RNAplfold\"}{\"source\"}=\"http://www.t\
bi.univie.ac.at/RNA/packages/source/ViennaRNA-2.1.\
9.tar.gz\";\n$PG{\"RNAplfold\"}{\"mode\"}=\"rcoffe\
e,\";\n$PG{\"RNAplfold\"}{\"binary\"}=\"RNAplfold.\
tar.gz\";\n$PG{\"RNAplfold\"}{\"version\"}=\"2.1.9\
\";\n$PG{\"retree\"}{\"4_TCOFFEE\"}=\"PHYLIP\";\n$\
PG{\"retree\"}{\"type\"}=\"Phylogeny\";\n$PG{\"ret\
ree\"}{\"ADDRESS\"}=\"http://evolution.gs.washingt\
on.edu/phylip/\";\n$PG{\"retree\"}{\"language\"}=\\
"C\";\n$PG{\"retree\"}{\"language2\"}=\"C\";\n$PG{\
\"retree\"}{\"source\"}=\"http://www.tcoffee.org/P\
ackages/mirrors/source/phylip-3.66.tar.gz\";\n$PG{\
\"retree\"}{\"mode\"}=\"trmsd,\";\n$PG{\"retree\"}\
{\"binary\"}=\"retree.tar.gz\";\n$PG{\"retree\"}{\\
"version\"}=\"3.66\";\n$PG{\"hmmtop\"}{\"4_TCOFFEE\
\"}=\"HMMTOP\";\n$PG{\"hmmtop\"}{\"type\"}=\"prote\
in_secondarystructure_predictor\";\n$PG{\"hmmtop\"\
}{\"ADDRESS\"}=\"www.enzim.hu/hmmtop/\";\n$PG{\"hm\
mtop\"}{\"language\"}=\"C\";\n$PG{\"hmmtop\"}{\"la\
nguage2\"}=\"C\";\n$PG{\"hmmtop\"}{\"source\"}=\"h\
ttp://www.tcoffee.org/Packages/mirrors/hmmtop2.1.t\
gz\";\n$PG{\"hmmtop\"}{\"binary\"}=\"hmmtop\";\n$P\
G{\"hmmtop\"}{\"update_action\"}=\"never\";\n$PG{\\
"hmmtop\"}{\"mode\"}=\"tcoffee\";\n$PG{\"hmmtop\"}\
{\"version\"}=\"2.1\";\n$PG{\"gorIV\"}{\"4_TCOFFEE\
\"}=\"GOR4\";\n$PG{\"gorIV\"}{\"type\"}=\"protein_\
secondarystructure_predictor\";\n$PG{\"gorIV\"}{\"\
ADDRESS\"}=\"http://mig.jouy.inra.fr/logiciels/gor\
IV/\";\n$PG{\"gorIV\"}{\"language\"}=\"C\";\n$PG{\\
"gorIV\"}{\"language2\"}=\"C\";\n$PG{\"gorIV\"}{\"\
source\"}=\"http://www.tcoffee.org/Packages/mirror\
s/GOR_IV.tar.gz\";\n$PG{\"gorIV\"}{\"update_action\
\"}=\"never\";\n$PG{\"gorIV\"}{\"mode\"}=\"tcoffee\
\";\n$PG{\"wublast.pl\"}{\"4_TCOFFEE\"}=\"EBIWUBLA\
STc\";\n$PG{\"wublast.pl\"}{\"type\"}=\"protein_ho\
mology_predictor\";\n$PG{\"wublast.pl\"}{\"ADDRESS\
\"}=\"built_in\";\n$PG{\"wublast.pl\"}{\"ADDRESS2\\
"}=\"http://www.ebi.ac.uk/Tools/webservices/servic\
es/wublast\";\n$PG{\"wublast.pl\"}{\"language\"}=\\
"Perl\";\n$PG{\"wublast.pl\"}{\"language2\"}=\"Per\
l\";\n$PG{\"wublast.pl\"}{\"source\"}=\"empty\";\n\
$PG{\"wublast.pl\"}{\"update_action\"}=\"never\";\\
n$PG{\"wublast.pl\"}{\"mode\"}=\"psicoffee,express\
o,accurate\";\n$PG{\"blastpgp.pl\"}{\"4_TCOFFEE\"}\
=\"EBIBLASTPGPc\";\n$PG{\"blastpgp.pl\"}{\"type\"}\
=\"protein_homology_predictor\";\n$PG{\"blastpgp.p\
l\"}{\"ADDRESS\"}=\"built_in\";\n$PG{\"blastpgp.pl\
\"}{\"ADDRESS2\"}=\"http://www.ebi.ac.uk/Tools/web\
services/services/blastpgp\";\n$PG{\"blastpgp.pl\"\
}{\"language\"}=\"Perl\";\n$PG{\"blastpgp.pl\"}{\"\
language2\"}=\"Perl\";\n$PG{\"blastpgp.pl\"}{\"sou\
rce\"}=\"empty\";\n$PG{\"blastpgp.pl\"}{\"update_a\
ction\"}=\"never\";\n$PG{\"blastpgp.pl\"}{\"mode\"\
}=\"psicoffee,expresso,accurate\";\n$PG{\"blastall\
\"}{\"4_TCOFFEE\"}=\"blastall\";\n$PG{\"blastall\"\
}{\"type\"}=\"protein_homology_predictor\";\n$PG{\\
"blastall\"}{\"ADDRESS\"}=\"ftp://ftp.ncbi.nih.gov\
/blast/executables/LATEST\";\n$PG{\"blastall\"}{\"\
language\"}=\"C\";\n$PG{\"blastall\"}{\"language2\\
"}=\"C\";\n$PG{\"blastall\"}{\"source\"}=\"ftp://f\
tp.ncbi.nlm.nih.gov/blast/executables/blast+/2.6.0\
/ncbi-blast-2.6.0+-src.tar.gz\";\n$PG{\"blastall\"\
}{\"update_action\"}=\"never\";\n$PG{\"blastall\"}\
{\"mode\"}=\"psicoffee,expresso,3dcoffee\";\n$PG{\\
"legacy_blast.pl\"}{\"4_TCOFFEE\"}=\"NCBIBLAST\";\\
n$PG{\"legacy_blast.pl\"}{\"type\"}=\"protein_homo\
logy_predictor\";\n$PG{\"legacy_blast.pl\"}{\"ADDR\
ESS\"}=\"ftp://ftp.ncbi.nih.gov/blast/executables/\
LATEST\";\n$PG{\"legacy_blast.pl\"}{\"language\"}=\
\"C\";\n$PG{\"legacy_blast.pl\"}{\"language2\"}=\"\
C\";\n$PG{\"legacy_blast.pl\"}{\"source\"}=\"ftp:/\
/ftp.ncbi.nlm.nih.gov/blast/executables/blast+/2.6\
.0/ncbi-blast-2.6.0+-src.tar.gz\";\n$PG{\"legacy_b\
last.pl\"}{\"update_action\"}=\"never\";\n$PG{\"le\
gacy_blast.pl\"}{\"mode\"}=\"psicoffee,expresso,3d\
coffee\";\n$PG{\"SOAP::Lite\"}{\"4_TCOFFEE\"}=\"SO\
APLITE\";\n$PG{\"SOAP::Lite\"}{\"type\"}=\"library\
\";\n$PG{\"SOAP::Lite\"}{\"ADDRESS\"}=\"http://cpa\
nsearch.perl.org/src/MKUTTER/SOAP-Lite-0.710.08/Ma\
kefile.PL\";\n$PG{\"SOAP::Lite\"}{\"language\"}=\"\
Perl\";\n$PG{\"SOAP::Lite\"}{\"language2\"}=\"Perl\
\";\n$PG{\"SOAP::Lite\"}{\"source\"}=\"empty\";\n$\
PG{\"SOAP::Lite\"}{\"update_action\"}=\"never\";\n\
$PG{\"SOAP::Lite\"}{\"mode\"}=\"none\";\n$PG{\"XML\
::Simple\"}{\"4_TCOFFEE\"}=\"XMLSIMPLE\";\n$PG{\"X\
ML::Simple\"}{\"type\"}=\"library\";\n$PG{\"XML::S\
imple\"}{\"ADDRESS\"}=\"http://search.cpan.org/~gr\
antm/XML-Simple-2.18/lib/XML/Simple.pm\";\n$PG{\"X\
ML::Simple\"}{\"language\"}=\"Perl\";\n$PG{\"XML::\
Simple\"}{\"language2\"}=\"Perl\";\n$PG{\"XML::Sim\
ple\"}{\"source\"}=\"empty\";\n$PG{\"XML::Simple\"\
}{\"mode\"}=\"psicoffee,expresso,accurate\";\n$PG{\
\"x3dna\"}{\"4_TCOFFEE\"}=\"x3dna-ssr\";\n$PG{\"x3\
dna\"}{\"type\"}=\"RNA_secondarystructure_predicto\
r\";\n$PG{\"x3dna\"}{\"ADDRESS\"}=\"http://x3dna.b\
io.columbia.edu/\";\n$PG{\"x3dna\"}{\"source\"}=\"\
http://www.tcoffee.org/Packages/mirrors/source/x3d\
na-v2.3-linux-64bit.tar.gz\";\n$PG{\"x3dna\"}{\"mo\
de\"}=\"saracoffee\";\n$PG{\"x3dna\"}{\"update_act\
ion\"}=\"never\";\n$PG{\"fsa\"}{\"4_TCOFFEE\"}=\"F\
SA\";\n$PG{\"fsa\"}{\"type\"}=\"sequence_multiple_\
aligner\";\n$PG{\"fsa\"}{\"ADDRESS\"}=\"http://fsa\
.sourceforge.net/\";\n$PG{\"fsa\"}{\"language\"}=\\
"C++\";\n$PG{\"fsa\"}{\"language2\"}=\"CXX\";\n$PG\
{\"fsa\"}{\"source\"}=\"http://sourceforge.net/pro\
jects/fsa/files/fsa-1.15.3.tar.gz/download/\";\n$P\
G{\"fsa\"}{\"mode\"}=\"mcoffee\";\n$PG{\"fsa\"}{\"\
version\"}=\"1.15.3\";\n$PG{\"fsa\"}{\"update_acti\
on\"}=\"never\";\n$PG{\"mus4\"}{\"4_TCOFFEE\"}=\"M\
US4\";\n$PG{\"mus4\"}{\"type\"}=\"sequence_multipl\
e_aligner\";\n$PG{\"mus4\"}{\"ADDRESS\"}=\"http://\
www.drive5.com/muscle/\";\n$PG{\"mus4\"}{\"languag\
e\"}=\"C++\";\n$PG{\"mus4\"}{\"language2\"}=\"GPP\\
";\n$PG{\"mus4\"}{\"source\"}=\"http://www.drive5.\
com/muscle/muscle4.0_src.tar.gz\";\n$PG{\"mus4\"}{\
\"mode\"}=\"mcoffee,rcoffee\";\n$PG{\"mus4\"}{\"ve\
rsion\"}=\"4.0\";\n$PG{\"mus4\"}{\"update_action\"\
}=\"never\";\n$MODE{\"tcoffee\"}{\"name\"}=\"tcoff\
ee\";\n$MODE{\"rcoffee\"}{\"name\"}=\"rcoffee\";\n\
$MODE{\"3dcoffee\"}{\"name\"}=\"3dcoffee\";\n$MODE\
{\"mcoffee\"}{\"name\"}=\"mcoffee\";\n$MODE{\"expr\
esso\"}{\"name\"}=\"expresso\";\n$MODE{\"trmsd\"}{\
\"name\"}=\"trmsd\";\n$MODE{\"accurate\"}{\"name\"\
}=\"accurate\";\n$MODE{\"seq_reformat\"}{\"name\"}\
=\"seq_reformat\";\n\n\n$PG{C}{compiler}=\"gcc\";\\
n$PG{C}{compiler_flag}=\"CC\";\n$PG{C}{options}=\"\
\";\n$PG{C}{options_flag}=\"CFLAGS\";\n$PG{C}{type\
}=\"compiler\";\n\n$PG{\"CXX\"}{compiler}=\"g++\";\
\n$PG{\"CXX\"}{compiler_flag}=\"CXX\";\n$PG{\"CXX\\
"}{options}=\"\";\n$PG{\"CXX\"}{options_flag}=\"CX\
XFLAGS\";\n$PG{CXX}{type}=\"compiler\";\n\n$PG{\"C\
PP\"}{compiler}=\"g++\";\n$PG{\"CPP\"}{compiler_fl\
ag}=\"CPP\";\n$PG{\"CPP\"}{options}=\"\";\n$PG{\"C\
PP\"}{options_flag}=\"CPPFLAGS\";\n$PG{CPP}{type}=\
\"compiler\";\n\n$PG{\"GPP\"}{compiler}=\"g++\";\n\
$PG{\"GPP\"}{compiler_flag}=\"GPP\";\n$PG{\"GPP\"}\
{options}=\"\";\n$PG{\"GPP\"}{options_flag}=\"CFLA\
GS\";\n$PG{GPP}{type}=\"compiler\";\n\n$PG{Fortran\
}{compiler}=\"g77\";\n$PG{Fortran}{compiler_flag}=\
\"FCC\";\n$PG{Fortran}{type}=\"compiler\";\n\n$PG{\
Perl}{compiler}=\"CPAN\";\n$PG{Perl}{type}=\"compi\
ler\";\n\n$SUPPORTED_OS{macox}=\"Macintosh\";\n$SU\
PPORTED_OS{linux}=\"Linux\";\n$SUPPORTED_OS{window\
s}=\"Cygwin\";\n\n\n\n$MODE{t_coffee}{description}\
=\" for regular multiple sequence alignments\";\n$\
MODE{rcoffee} {description}=\" for RNA multiple se\
quence alignments\";\n\n$MODE{psicoffee} {descript\
ion}=\" for Homology Extended multiple sequence al\
ignments\";\n$MODE{expresso}{description}=\" for v\
ery accurate structure based multiple sequence ali\
gnments\";\n$MODE{\"3dcoffee\"}{description}=\" fo\
r multiple structure alignments\";\n$MODE{mcoffee}\
 {description}=\" for combining alternative multip\
le sequence alignment packages\\n------- into a un\
ique meta-package. The installer will upload sever\
al MSA packages and compile them\\n\n\";\n\n\n&pos\
t_process_PG();\nreturn;\n}\n\nsub post_process_PG\
\n  {\n    my $p;\n    \n    %PG=&name2dname (%PG)\
;\n    %MODE=&name2dname(%MODE);\n    foreach $p (\
keys(%PG)){if ( $PG{$p}{type} eq \"compiler\"){$PG\
{$p}{update_action}=\"never\";}}\n    \n  }\n\nsub\
 name2dname\n  {\n    my (%L)=(@_);\n    my ($l, $\
ml);\n    \n    foreach my $pg (keys(%L))\n      {\
\n	$l=length ($pg);\n	if ( $l>$ml){$ml=$l;}\n     \
 }\n    $ml+=1;\n    foreach my $pg (keys(%L))\n  \
    {\n	my $name;\n	$l=$ml-length ($pg);\n	$name=$\
pg;\n	for ( $b=0; $b<$l; $b++)\n	  {\n	    $name .\
=\" \";\n	  }\n	$L{$pg}{dname}=$name;\n      }\n  \
  return %L;\n  }\n\nsub env_file2putenv\n  {\n   \
 my $f=@_[0];\n    my $F=new FileHandle;\n    my $\
n;\n    \n    open ($F, \"$f\");\n    while (<$F>)\
\n      {\n	my $line=$_;\n	my($var, $value)=($_=~/\
(\\S+)\\=(\\S*)/);\n	$ENV{$var}=$value;\n	$ENV_SET\
{$var}=1;\n	$n++;\n      }\n    close ($F);\n    r\
eturn $n;\n  }\n\nsub replace_line_in_file\n  {\n \
   my ($file, $wordin, $wordout)=@_;\n    my $O=ne\
w FileHandle;\n    my $I=new FileHandle;\n    my $\
l;\n    if (!-e $file){return;}\n    \n    system \
(\"mv $file $file.old\");\n    open ($O, \">$file\\
");\n    open ($I, \"$file.old\");\n    while (<$I\
>)\n      {\n	$l=$_;\n	if (!($l=~/$wordin/)){print\
 $O \"$l\";}\n	elsif ( $wordout ne \"\"){$l=~s/$wo\
rdin/$wordout/g;print $O \"$l\";}\n      }\n    cl\
ose ($O);\n    close ($I);\n    return;\n  }\n\nsu\
b add_C_libraries\n  {\n   my ($file,$first,@list)\
=@_;\n   \n    my $O=new FileHandle;\n    my $I=ne\
w FileHandle;\n    my ($l,$anchor);\n    if (!-e $\
file){return;}\n   \n    $anchor=\"#include <$firs\
t>\";\n	 \n    system (\"mv $file $file.old\");\n \
   open ($O, \">$file\");\n    open ($I, \"$file.o\
ld\");\n    while (<$I>)\n      {\n	$l=$_;\n	print\
 $O \"$l\";\n	if (!($l=~/$anchor/))\n	   {\n	    \\
n	    foreach my $lib (@list)\n	       {\n        \
          print $O \"#include <$lib>\\n\";\n	     \
  }\n           }\n      }\n    close ($O);\n    c\
lose ($I);\n    return;\n    }\n","use Env;\nuse C\
wd;\n@suffix=(\"tmp\", \"temp\", \"cache\", \"t_co\
ffee\", \"core\", \"tcoffee\");\n\nif ($#ARGV==-1)\
\n  {\n    print \"clean_cache.pl -file <file to a\
dd in -dir> -dir=<dir> -size=<value in Mb>\\n0: un\
limited -1 always.\\nWill only clean directories m\
atching:[\";\n    foreach $k(@suffix){print \"*$k*\
 \";}\n    print \"]\\n\";\n    exit (EXIT_FAILURE\
);\n  }\n\n$cl=join (\" \",@ARGV);\nif (($cl=~/\\-\
no_action/))\n  {\n    exit (EXIT_SUCCESS);\n  }\n\
\nif (($cl=~/\\-debug/))\n  {\n    $DEBUG=1;\n  }\\
nelse\n  {\n    $DEBUG=0;\n  }\n\nif (($cl=~/\\-di\
r=(\\S+)/))\n  {\n    $dir=$1;\n  }\nelse\n  {\n  \
  $dir=\"./\";\n  }\n\nif ($cl=~/\\-file=(\\S+)/)\\
n  {\n    $file=$1;\n  }\nelse\n  {\n    $file=0;\\
n  }\n\nif ($cl=~/\\-size=(\\S+)/)\n  {\n    $max_\
size=$1;\n  }\nelse\n  {\n    $max_size=0;#unlimit\
ed\n  }\nif ($cl=~/\\-force/)\n  {\n    $force=1;\\
n  }\nelse\n  {\n    $force=0;\n  }\n\nif ($cl=~/\\
\-age=(\\S+)/)\n  {\n    $max_age=$1;\n  }\nelse\n\
  {\n    $max_age=0;#unlimited\n  }\n\n$max_size*=\
1000000;\nif ( ! -d $dir)\n  {\n    print STDERR \\
"\\nCannot process $dir: does not exist \\n\";\n  \
  exit (EXIT_FAILURE);\n  }\n\nif ( !($dir=~/^\\//\
))\n  {\n    $base=cwd();\n    $dir=\"$base/$dir\"\
;\n  }\n\n$proceed=0;\nforeach $s (@suffix)\n  {\n\
    \n    if (($dir=~/$s/)){$proceed=1;}\n    $s=u\
c ($s);\n    if (($dir=~/$s/)){$proceed=1;}\n  }\n\
if ( $proceed==0)\n  {\n    print STDERR \"Clean_c\
ache.pl can only clean directories whose absolute \
path name contains the following strings:\";\n    \
foreach $w (@suffix) {print STDERR \"$w \";$w=lc($\
w); print STDERR \"$w \";}\n    print STDERR \"\\n\
Cannot process $dir\\n\";\n    exit (EXIT_FAILURE)\
;\n  }\n\n$name_file=\"$dir/name_file.txt\";\n$siz\
e_file=\"$dir/size_file.txt\";\nif ( $force){&crea\
te_ref_file ($dir,$name_file,$size_file);}\nif ($f\
ile){&add_file ($dir, $name_file, $size_file, $fil\
e);}\n&clean_dir ($dir, $name_file, $size_file, $m\
ax_size,$max_age);\nexit (EXIT_SUCCESS);\n\nsub cl\
ean_dir \n  {\n    my ($dir, $name_file, $size_fil\
e, $max_size, $max_age)=@_;\n    my ($tot_size, $s\
ize, $f, $s);\n\n  \n    $tot_size=&get_tot_size (\
$dir, $name_file, $size_file);\n\n    if ( $tot_si\
ze<=$max_size){return ;}\n    else {$max_size/=2;}\
\n    \n    #recreate the name file in case some t\
emprary files have not been properly registered\n \
   &create_ref_file ($dir, $name_file, $size_file,\
 $max_age);\n  \n    $new_name_file=&vtmpnam();\n \
   open (R, \"$name_file\");\n    open (W, \">$new\
_name_file\");\n    while (<R>)\n      {\n	my $lin\
e=$_;\n	\n	($f, $s)=($line=~/(\\S+) (\\S+)/);\n	if\
 ( !($f=~/\\S/)){next;}\n	\n	elsif ($max_size && $\
tot_size>=$max_size && !($f=~/name_file/))\n	  {\n\
	    remove ( \"$dir/$f\");\n	    $tot_size-=$s;\n\
	  }\n	elsif ( $max_age && -M(\"$dir/$f\")>=$max_a\
ge)\n	  {\n	    remove ( \"$dir/$f\");\n	    $tot_\
size-=$s;\n	  }\n	else\n	  {\n	    print W \"$f $s\
\\n\";\n	  }\n      }\n    close (R);\n    close (\
W);\n    open (F, \">$size_file\");\n    print F \\
"$tot_size\";\n    if ( -e $new_name_file){`mv $ne\
w_name_file $name_file`;}\n    close (F);\n  }\nsu\
b get_tot_size\n  {\n    my ($dir, $name_file, $si\
ze_file)=@_;\n    my $size;\n    \n    if ( !-d $d\
ir){return 0;}\n    if ( !-e $name_file)\n      {\\
n	\n	&create_ref_file ($dir, $name_file, $size_fil\
e);\n      }\n    open (F, \"$size_file\");\n    $\
size=<F>;\n    close (F);\n    chomp ($size);\n   \
 return $size;\n  }\nsub size \n  {\n    my $f=@_[\
0];\n\n    if ( !-d $f){return -s($f);}\n    else \
{return &dir2size($f);}\n  }\nsub dir2size\n  {\n \
   my $d=@_[0];\n    my ($s, $f);\n    \n    if ( \
!-d $d) {return 0;}\n    \n    foreach $f (&dir2li\
st ($d))\n      {\n	if ( -d $f){$s+=&dir2size (\"$\
d/$f\");}\n	else {$s+= -s \"$dir/$f\";}\n      }\n\
    return $s;\n  }\n\nsub remove \n  {\n    my $f\
ile=@_[0];\n    my ($f);\n    \n    debug_print( \\
"--- $file ---\\n\");\n    if (($file eq \".\") ||\
 ($file eq \"..\") || ($file=~/\\*/)){return EXIT_\
FAILURE;}\n    elsif ( !-d $file)\n      {\n	debug\
_print (\"unlink $file\\n\");\n	if (-e $file){unli\
nk ($file);}\n      }\n    elsif ( -d $file)\n    \
  {\n	debug_print (\"++++++++ $file +++++++\\n\");\
\n	foreach $f (&dir2list($file))\n	  {\n	    &remo\
ve (\"$file/$f\");\n	  }\n	debug_print (\"rmdir $f\
ile\\n\");\n	rmdir $file;\n      }\n    else\n    \
  {\n	debug_print (\"????????? $file ????????\\n\"\
);\n      }\n    return EXIT_SUCCESS;\n  }\n\nsub \
dir2list\n  {\n    my $dir=@_[0];\n    my (@list1,\
 @list2,@list3, $l);\n\n    opendir (DIR,$dir);\n \
   @list1=readdir (DIR);\n    closedir (DIR);\n   \
 \n    foreach $l (@list1)\n      {\n	if ( $l ne \\
".\" && $l ne \"..\"){@list2=(@list2, $l);}\n     \
 }\n    @list3 = sort { (-M \"$dir/$list2[$b]\") <\
=> (-M \"$dir/$list2[$a]\")} @list2;\n    return @\
list3;\n    \n  }\n\nsub debug_print\n  {\n    \n \
   if ($DEBUG==1){print @_;}\n    \n  }\nsub creat\
e_ref_file\n  {\n    my ($dir,$name_file,$size_fil\
e)=@_;\n    my ($f, $s, $tot_size, @l);\n    \n   \
 if ( !-d $dir){return;}\n    \n    @l=&dir2list (\
$dir);\n    open (F, \">$name_file\");\n    foreac\
h $f (@l)\n      {\n	$s=&size(\"$dir/$f\");\n	$tot\
_size+=$s;\n	print F \"$f $s\\n\";\n      }\n    &\
myecho ($tot_size, \">$size_file\");\n    close (F\
);\n  }\nsub add_file \n  {\n    my ($dir,$name_fi\
le,$size_file,$file)=@_;\n    my ($s, $tot_size);\\
n    \n    if ( !-d $dir)   {return;}\n    if ( !-\
e \"$dir/$file\" ) {return;}\n    if ( !-e $name_f\
ile){&create_ref_file ($dir,$name_file,$size_file)\
;}\n					    \n    $s=&size(\"$dir/$file\");\n    \
open (F, \">>$name_file\");\n    print F \"$file\\\
n\";\n    close (F);\n\n    $tot_size=&get_tot_siz\
e ($dir,$name_file,$size_file);\n    $tot_size+=$s\
;\n    &myecho ($tot_size, \">$size_file\");\n    \
\n  }\n	\nsub myecho\n  {\n    my ($string, $file)\
=@_;\n    open (ECHO, $file) || die;\n    print EC\
HO \"$string\";\n    close (ECHO);\n  }\n    \n		\\
n	\nsub vtmpnam\n  {\n    my $tmp_file_name;\n    \
$tmp_name_counter++;\n    $tmp_file_name=\"tmp_fil\
e_for_clean_cache_pdb$$.$tmp_name_counter\";\n    \
$tmp_file_list[$ntmp_file++]=$tmp_file_name;\n    \
if ( -e $tmp_file_name) {return &vtmpnam ();}\n   \
 else {return $tmp_file_name;}\n  }\n","\nmy $addr\
ess=\"http://www.tcoffee.org/Data/Datasets/NatureP\
rotocolsDataset.tar.gz\";\nmy $out=\"NatureProtoco\
lsDataset.tar.gz\";\n&url2file ($address,$out);\n\\
nif ( -e $out)\n  {\n    \n    system (\"gunzip Na\
tureProtocolsDataset.tar.gz\");\n    system (\"tar\
 -xvf NatureProtocolsDataset.tar\");\n  	system (\\
"rm -rf NatureProtocolsDataset.tar\");  \n    prin\
t \"Your Data Set is in the Folder 'NatureProtocol\
sDataset'\\n\";\n  }\nelse \n  {\n    print \"Coul\
d not Download Dataset --- Web site may be down --\
 Try again later\\n\";\n  }\n\n\n\n\nsub url2file\\
n{\n    my ($address, $out, $wget_arg, $curl_arg)=\
(@_);\n    my ($pg, $flag, $r, $arg, $count);\n   \
 \n    if (!$CONFIGURATION){&check_configuration (\
\"wget\", \"INTERNET\", \"gzip\");$CONFIGURATION=1\
;}\n    \n    if (&pg_is_installed (\"wget\"))   {\
$pg=\"wget\"; $flag=\"-O\";$arg=$wget_arg;}\n    e\
lsif (&pg_is_installed (\"curl\")){$pg=\"curl\"; $\
flag=\"-o\";$arg=$curl_arg;}\n    return system (\\
"$pg $address $flag $out>/dev/null 2>/dev/null\");\
\n\n}\n\nsub pg_is_installed\n  {\n    my @ml=@_;\\
n    my $r, $p, $m;\n    my $supported=0;\n    \n \
   my $p=shift (@ml);\n    if ($p=~/::/)\n      {\\
n	if (system (\"perl -M$p -e 1\")==$EXIT_SUCCESS){\
return 1;}\n	else {return 0;}\n      }\n    else\n\
      {\n	$r=`which $p 2>/dev/null`;\n	if ($r eq \\
"\"){return 0;}\n	else {return 1;}\n      }\n  }\n\
sub check_configuration \n    {\n      my @l=@_;\n\
      my $v;\n      foreach my $p (@l)\n	{\n	  \n	\
  if   ( $p eq \"EMAIL\")\n	    { \n	      if ( !(\
$EMAIL=~/@/))\n		{\n		  exit (EXIT_FAILURE);\n		}\\
n	    }\n	  elsif( $p eq \"INTERNET\")\n	    {\n	 \
     if ( !&check_internet_connection())\n		{\n		 \
 exit (EXIT_FAILURE);\n		}\n	    }\n	  elsif( $p e\
q \"wget\")\n	    {\n	      if (!&pg_is_installed \
(\"wget\") && !&pg_is_installed (\"curl\"))\n		{\n\
		  exit (EXIT_FAILURE);\n		}\n	    }\n	  elsif( !\
(&pg_is_installed ($p)))\n	    {\n	      exit (EXI\
T_FAILURE);\n	    }\n	}\n      return 1;\n    }\ns\
ub check_internet_connection\n  {\n    my $interne\
t;\n    my $tmp;\n    &check_configuration ( \"wge\
t\"); \n    \n    $tmp=&vtmpnam ();\n    \n    if \
    (&pg_is_installed    (\"wget\")){`wget www.goo\
gle.com -O$tmp >/dev/null 2>/dev/null`;}\n    elsi\
f  (&pg_is_installed    (\"curl\")){`curl www.goog\
le.com -o$tmp >/dev/null 2>/dev/null`;}\n    \n   \
 if ( !-e $tmp || -s $tmp < 10){$internet=0;}\n   \
 else {$internet=1;}\n    if (-e $tmp){unlink $tmp\
;}\n\n    return $internet;\n  }\n\nsub vtmpnam\n \
     {\n	my $r=rand(100000);\n	my $f=\"file.$r.$$\\
";\n	while (-e $f)\n	  {\n	    $f=vtmpnam();\n	  }\
\n	push (@TMPFILE_LIST, $f);\n	return $f;\n      }\
\n\n","\n$t_coffee=\"t_coffee\";\n\nforeach $value\
 ( @ARGV)\n  {\n    $seq_file=$seq_file.\" \".$val\
ue;\n  }\n\n$name=$ARGV[0];\n$name=~s/\\.[^\\.]*$/\
/;\n$lib_name=\"$name.mocca_lib\";\n$type=`t_coffe\
e $seq_file -get_type -quiet`;\nchop ($type);\n\ni\
f ( $type eq \"PROTEIN\"){$lib_mode=\"lalign_rs_s_\
pair -lalign_n_top 20\";}\nelsif ( $type eq\"DNA\"\
){$lib_mode=\"lalign_rs_s_dna_pair -lalign_n_top 4\
0\";}\n\nif ( !(-e $lib_name))\n  {\n	  \n  $comma\
nd=\"$t_coffee -mocca -seq_weight=no -cosmetic_pen\
alty=0 -mocca_interactive -in $lib_mode -out_lib $\
lib_name -infile $seq_file\";\n  \n  }\nelsif ( (-\
e $lib_name))\n  {\n  $command=\"$t_coffee -mocca \
-seq_weight=no -cosmetic_penalty=0 -mocca_interact\
ive -in $lib_name -infile $seq_file\";\n  \n  }\n\\
nsystem ($command);\n\nexit;\n\n","my $WSDL = 'htt\
p://www.ebi.ac.uk/Tools/webservices/wsdl/WSDaliLit\
e.wsdl';\n\nuse SOAP::Lite;\nuse Data::Dumper;\nus\
e Getopt::Long qw(:config no_ignore_case bundling)\
;\nuse File::Basename;\n\nmy $checkInterval = 5;\n\
\nmy %params=(\n	    'async' => '1', # Use async m\
ode and simulate sync mode in client\n	    );\nGet\
Options(\n    'pdb1=s'     => \\$params{'sequence1\
'},\n    'chainid1=s' => \\$params{'chainid1'},\n \
   'pdb2=s'     => \\$params{'sequence2'},\n    'c\
hainid2=s' => \\$params{'chainid2'},\n    \"help|h\
\"	 => \\$help, # Usage info\n    \"async|a\"	 => \
\\$async, # Asynchronous submission\n    \"polljob\
\"	 => \\$polljob, # Get results\n    \"status\"	 \
=> \\$status, # Get status\n    \"jobid|j=s\"  => \
\\$jobid, # JobId\n    \"email|S=s\"  => \\$params\
{email}, # E-mail address\n    \"trace\"      => \\
\$trace, # SOAP messages\n    \"sequence=s\" => \\\
$sequence, # Input PDB\n    );\n\nmy $scriptName =\
 basename($0, ());\nif($help) {\n    &usage();\n  \
  exit(0);\n}\n\nif($trace) {\n    print \"Tracing\
 active\\n\";\n    SOAP::Lite->import(+trace => 'd\
ebug');\n}\n\nmy $soap = SOAP::Lite\n    ->service\
($WSDL)\n    ->on_fault(sub {\n        my $soap = \
shift;\n        my $res = shift;\n        # Throw \
an exception for all faults\n        if(ref($res) \
eq '') {\n            die($res);\n        } else {\
\n            die($res->faultstring);\n        }\n\
        return new SOAP::SOM;\n    }\n            \
   );\n\nif( !($polljob || $status) &&\n    !( def\
ined($params{'sequence1'}) && defined($params{'seq\
uence2'}) )\n    ) {\n    print STDERR 'Error: bad\
 option combination', \"\\n\";\n    &usage();\n   \
 exit(1);\n}\nelsif($polljob && defined($jobid)) {\
\n    print \"Getting results for job $jobid\\n\";\
\n    getResults($jobid);\n}\nelsif($status && def\
ined($jobid)) {\n    print STDERR \"Getting status\
 for job $jobid\\n\";\n    my $result = $soap->che\
ckStatus($jobid);\n    print STDOUT \"$result\", \\
"\\n\";\n    if($result eq 'DONE') {\n	print STDER\
R \"To get results: $scriptName --polljob --jobid \
$jobid\\n\";\n    }\n}\nelse {\n    if(-f $params{\
'sequence1'}) {\n	$params{'sequence1'} = read_file\
($params{'sequence1'});\n    }\n    if(-f $params{\
'sequence2'}) {\n	$params{'sequence2'} = read_file\
($params{'sequence2'});\n    }\n\n    my $jobid;\n\
    my $paramsData = SOAP::Data->name('params')->t\
ype(map=>\\%params);\n    # For SOAP::Lite 0.60 an\
d earlier parameters are passed directly\n    if($\
SOAP::Lite::VERSION eq '0.60' || $SOAP::Lite::VERS\
ION =~ /0\\.[1-5]/) {\n        $jobid = $soap->run\
DaliLite($paramsData);\n    }\n    # For SOAP::Lit\
e 0.69 and later parameter handling is different, \
so pass\n    # undef's for templated params, and t\
hen pass the formatted args.\n    else {\n        \
$jobid = $soap->runDaliLite(undef,\n				     $para\
msData);\n    }\n\n    if (defined($async)) {\n	pr\
int STDOUT $jobid, \"\\n\";\n        print STDERR \
\"To check status: $scriptName --status --jobid $j\
obid\\n\";\n    } else { # Synchronous mode\n     \
   print STDERR \"JobId: $jobid\\n\";\n        sle\
ep 1;\n        getResults($jobid);\n    }\n}\n\nsu\
b clientPoll($) {\n    my $jobid = shift;\n    my \
$result = 'PENDING';\n    # Check status and wait \
if not finished\n    #print STDERR \"Checking stat\
us: $jobid\\n\";\n    while($result eq 'RUNNING' |\
| $result eq 'PENDING') {\n        $result = $soap\
->checkStatus($jobid);\n        print STDERR \"$re\
sult\\n\";\n        if($result eq 'RUNNING' || $re\
sult eq 'PENDING') {\n            # Wait before po\
lling again.\n            sleep $checkInterval;\n \
       }\n    }\n}\n\nsub getResults($) {\n    $jo\
bid = shift;\n    # Check status, and wait if not \
finished\n    clientPoll($jobid);\n    # Use JobId\
 if output file name is not defined\n    unless(de\
fined($outfile)) {\n        $outfile=$jobid;\n    \
}\n    # Get list of data types\n    my $resultTyp\
es = $soap->getResults($jobid);\n    # Get the dat\
a and write it to a file\n    if(defined($outforma\
t)) { # Specified data type\n        my $selResult\
Type;\n        foreach my $resultType (@$resultTyp\
es) {\n            if($resultType->{type} eq $outf\
ormat) {\n                $selResultType = $result\
Type;\n            }\n        }\n        $res=$soa\
p->poll($jobid, $selResultType->{type});\n        \
write_file($outfile.'.'.$selResultType->{ext}, $re\
s);\n    } else { # Data types available\n        \
# Write a file for each output type\n        for m\
y $resultType (@$resultTypes){\n            #print\
 \"Getting $resultType->{type}\\n\";\n            \
$res=$soap->poll($jobid, $resultType->{type});\n  \
          write_file($outfile.'.'.$resultType->{ex\
t}, $res);\n        }\n    }\n}\n\nsub read_file($\
) {\n    my $filename = shift;\n    open(FILE, $fi\
lename);\n    my $content;\n    my $buffer;\n    w\
hile(sysread(FILE, $buffer, 1024)) {\n	$content.= \
$buffer;\n    }\n    close(FILE);\n    return $con\
tent;\n}\n\nsub write_file($$) {\n    my ($tmp,$en\
tity) = @_;\n    print STDERR \"Creating result fi\
le: \".$tmp.\"\\n\";\n    unless(open (FILE, \">$t\
mp\")) {\n	return 0;\n    }\n    syswrite(FILE, $e\
ntity);\n    close (FILE);\n    return 1;\n}\n\nsu\
b usage {\n    print STDERR <<EOF\nDaliLite\n=====\
===\n\nPairwise comparison of protein structures\n\
\n[Required]\n\n  --pdb1                : str  : P\
DB ID for structure 1\n  --pdb2                : s\
tr  : PDB ID for structure 2\n\n[Optional]\n\n  --\
chain1              : str  : Chain identifer in st\
ructure 1\n  --chain2              : str  : Chain \
identifer in structure 2\n\n[General]\n\n  -h, --h\
elp            :      : prints this help text\n  -\
S, --email           : str  : user email address\n\
  -a, --async           :      : asynchronous subm\
ission\n      --status          :      : poll for \
the status of a job\n      --polljob         :    \
  : poll for the results of a job\n  -j, --jobid  \
         : str  : jobid for an asynchronous job\n \
 -O, --outfile         : str  : file name for resu\
lts (default is jobid)\n      --trace	        :   \
   : show SOAP messages being interchanged \n\nSyn\
chronous job:\n\n  The results/errors are returned\
 as soon as the job is finished.\n  Usage: $script\
Name --email <your\\@email> [options] pdbFile [--o\
utfile string]\n  Returns: saves the results to di\
sk\n\nAsynchronous job:\n\n  Use this if you want \
to retrieve the results at a later time. The resul\
ts \n  are stored for up to 24 hours. \n  The asyn\
chronous submission mode is recommended when users\
 are submitting \n  batch jobs or large database s\
earches	\n  Usage: $scriptName --email <your\\@ema\
il> --async [options] pdbFile\n  Returns: jobid\n\\
n  Use the jobid to query for the status of the jo\
b. \n  Usage: $scriptName --status --jobid <jobId>\
\n  Returns: string indicating the status of the j\
ob:\n    DONE - job has finished\n    RUNNING - jo\
b is running\n    NOT_FOUND - job cannot be found\\
n    ERROR - the jobs has encountered an error\n\n\
  When done, use the jobid to retrieve the status \
of the job. \n  Usage: $scriptName --polljob --job\
id <jobId> [--outfile string]\n\n[Help]\n\n  For m\
ore detailed help information refer to\n  http://w\
ww.ebi.ac.uk/DaliLite/\nEOF\n;\n}\n","my $WSDL = '\
http://www.ebi.ac.uk/Tools/webservices/wsdl/WSWUBl\
ast.wsdl';\n\nuse strict;\nuse SOAP::Lite;\nuse Ge\
topt::Long qw(:config no_ignore_case bundling);\nu\
se File::Basename;\n\nmy $checkInterval = 15;\n\nm\
y $numOpts = scalar(@ARGV);\nmy ($outfile, $outfor\
mat, $help, $async, $polljob, $status, $ids, $jobi\
d, $trace, $sequence);\nmy %params= ( # Defaults\n\
	      'async' => 1, # Force into async mode\n	   \
   'exp' => 10.0, # E-value threshold\n	      'num\
al' => 50, # Maximum number of alignments\n	      \
'scores' => 100, # Maximum number of scores\n     \
       );\nGetOptions( # Map the options into vari\
ables\n    \"program|p=s\"     => \\$params{progra\
m}, # BLAST program\n    \"database|D=s\"    => \\\
$params{database}, # Search database\n    \"matrix\
|m=s\"      => \\$params{matrix}, # Scoring matrix\
\n    \"exp|E=f\"         => \\$params{exp}, # E-v\
alue threshold\n    \"echofilter|e\"    => \\$para\
ms{echofilter}, # Display filtered sequence\n    \\
"filter|f=s\"      => \\$params{filter}, # Low com\
plexity filter name\n    \"alignments|b=i\"  => \\\
$params{numal}, # Number of alignments\n    \"scor\
es|s=i\"      => \\$params{scores}, # Number of sc\
ores\n    \"sensitivity|S=s\" => \\$params{sensiti\
vity}, # Search sensitivity\n    \"sort|t=s\"	    \
  => \\$params{sort}, # Sort hits by...\n    \"sta\
ts|T=s\"       => \\$params{stats}, # Scoring stat\
istic to use\n    \"strand|d=s\"      => \\$params\
{strand}, # Strand to use in DNA vs. DNA search\n \
   \"topcombon|c=i\"   => \\$params{topcombon}, # \
Consistent sets of HSPs\n    \"outfile=s\"       =\
> \\$outfile, # Output file\n    \"outformat|o=s\"\
   => \\$outformat, # Output format\n    \"help|h\\
"	      => \\$help, # Usage info\n    \"async|a\"	\
      => \\$async, # Asynchronous mode\n    \"poll\
job\"	      => \\$polljob, # Get results\n    \"st\
atus\"	      => \\$status, # Get job status\n    \\
"ids\"             => \\$ids, # Get ids from resul\
t\n    \"jobid|j=s\"       => \\$jobid, # JobId\n \
   \"email=s\"         => \\$params{email}, # E-ma\
il address\n    \"trace\"           => \\$trace, #\
 SOAP trace\n    \"sequence=s\"      => \\$sequenc\
e, # Query sequence\n    );\n\nmy $scriptName = ba\
sename($0, ());\nif($help || $numOpts == 0) {\n   \
 &usage();\n    exit(0);\n}\n\nif($trace){\n    pr\
int STDERR \"Tracing active\\n\";\n    SOAP::Lite-\
>import(+trace => 'debug');\n}\n\nmy $soap = SOAP:\
:Lite\n    ->service($WSDL)\n    ->proxy('http://l\
ocalhost/',\n    #proxy => ['http' => 'http://your\
.proxy.server/'], # HTTP proxy\n    timeout => 600\
, # HTTP connection timeout\n    )\n    ->on_fault\
(sub { # SOAP fault handler\n        my $soap = sh\
ift;\n        my $res = shift;\n        # Throw an\
 exception for all faults\n        if(ref($res) eq\
 '') {\n            die($res);\n        } else {\n\
            die($res->faultstring);\n        }\n  \
      return new SOAP::SOM;\n    }\n              \
 );\n\nif( !($polljob || $status || $ids) &&\n    \
!( defined($ARGV[0]) || defined($sequence) )\n    \
) {\n    print STDERR 'Error: bad option combinati\
on', \"\\n\";\n    &usage();\n    exit(1);\n}\nels\
if($polljob && defined($jobid)) {\n    print \"Get\
ting results for job $jobid\\n\";\n    getResults(\
$jobid);\n}\nelsif($status && defined($jobid)) {\n\
    print STDERR \"Getting status for job $jobid\\\
n\";\n    my $result = $soap->checkStatus($jobid);\
\n    print STDOUT \"$result\\n\";\n    if($result\
 eq 'DONE') {\n	print STDERR \"To get results: $sc\
riptName --polljob --jobid $jobid\\n\";\n    }\n} \
 \nelsif($ids && defined($jobid)) {\n    print STD\
ERR \"Getting ids from job $jobid\\n\";\n    getId\
s($jobid);\n}\nelse {\n    # Prepare input data\n \
   my $content;\n    my (@contents) = ();\n    if(\
-f $ARGV[0] || $ARGV[0] eq '-') {	\n	$content={typ\
e=>'sequence',content=>read_file($ARGV[0])};	\n   \
 }\n    if($sequence) {	\n	if(-f $sequence || $seq\
uence eq '-') {	\n	    $content={type=>'sequence',\
content=>read_file($ARGV[0])};	\n	} else {\n	    $\
content={type=>'sequence',content=>$sequence};\n	}\
\n    }\n    push @contents, $content;\n\n    # Su\
bmit the job\n    my $paramsData = SOAP::Data->nam\
e('params')->type(map=>\\%params);\n    my $conten\
tData = SOAP::Data->name('content')->value(\\@cont\
ents);\n    # For SOAP::Lite 0.60 and earlier para\
meters are passed directly\n    if($SOAP::Lite::VE\
RSION eq '0.60' || $SOAP::Lite::VERSION =~ /0\\.[1\
-5]/) {\n        $jobid = $soap->runWUBlast($param\
sData, $contentData);\n    }\n    # For SOAP::Lite\
 0.69 and later parameter handling is different, s\
o pass\n    # undef's for templated params, and th\
en pass the formatted args.\n    else {\n        $\
jobid = $soap->runWUBlast(undef, undef,\n				   $p\
aramsData, $contentData);\n    }\n\n    # Asynchro\
nous mode: output jobid and exit.\n    if (defined\
($async)) {\n	print STDOUT $jobid, \"\\n\";\n     \
   print STDERR \"To check status: $scriptName --s\
tatus --jobid $jobid\\n\";\n    }\n    # Synchrono\
us mode: try to get results\n    else {\n        p\
rint STDERR \"JobId: $jobid\\n\";\n        sleep 1\
;\n        getResults($jobid);\n    }\n}\n\nsub ge\
tIds($) {\n    my $jobid = shift;\n    my $results\
 = $soap->getIds($jobid);\n    for my $result (@$r\
esults){\n	print \"$result\\n\";\n    }\n}\n\nsub \
clientPoll($) {\n    my $jobid = shift;\n    my $r\
esult = 'PENDING';\n    # Check status and wait if\
 not finished\n    while($result eq 'RUNNING' || $\
result eq 'PENDING') {\n        $result = $soap->c\
heckStatus($jobid);\n        print STDERR \"$resul\
t\\n\";\n        if($result eq 'RUNNING' || $resul\
t eq 'PENDING') {\n            # Wait before polli\
ng again.\n            sleep $checkInterval;\n    \
    }\n    }\n}\n\nsub getResults($) {\n    my $jo\
bid = shift;\n    my $res;\n    # Check status, an\
d wait if not finished\n    clientPoll($jobid);\n \
   # Use JobId if output file name is not defined\\
n    unless(defined($outfile)) {\n        $outfile\
=$jobid;\n    }\n    # Get list of data types\n   \
 my $resultTypes = $soap->getResults($jobid);\n   \
 # Get the data and write it to a file\n    if(def\
ined($outformat)) { # Specified data type\n	if($ou\
tformat eq 'xml') {$outformat = 'toolxml';}\n	if($\
outformat eq 'txt') {$outformat = 'tooloutput';}\n\
        my $selResultType;\n        foreach my $re\
sultType (@$resultTypes) {\n            if($result\
Type->{type} eq $outformat) {\n                $se\
lResultType = $resultType;\n            }\n       \
 }\n        $res=$soap->poll($jobid, $selResultTyp\
e->{type});\n	if($outfile eq '-') {\n	     write_f\
ile($outfile, $res);\n	} else {\n	    write_file($\
outfile.'.'.$selResultType->{ext}, $res);\n	}\n   \
 } else { # Data types available\n        # Write \
a file for each output type\n        for my $resul\
tType (@$resultTypes){\n            #print STDERR \
\"Getting $resultType->{type}\\n\";\n            $\
res=$soap->poll($jobid, $resultType->{type});\n	  \
  if($outfile eq '-') {\n		write_file($outfile, $r\
es);\n	    } else {\n		write_file($outfile.'.'.$re\
sultType->{ext}, $res);\n	    }\n        }\n    }\\
n}\n\nsub read_file($) {\n    my $filename = shift\
;\n    my ($content, $buffer);\n    if($filename e\
q '-') {\n	while(sysread(STDIN, $buffer, 1024)) {\\
n	    $content .= $buffer;\n	}\n    }\n    else { \
# File\n	open(FILE, $filename) or die \"Error: una\
ble to open input file\";\n	while(sysread(FILE, $b\
uffer, 1024)) {\n	    $content .= $buffer;\n	}\n	c\
lose(FILE);\n    }\n    return $content;\n}\n\nsub\
 write_file($$) {\n    my ($filename, $data) = @_;\
\n    print STDERR 'Creating result file: ' . $fil\
ename . \"\\n\";\n    if($filename eq '-') {\n	pri\
nt STDOUT $data;\n    }\n    else {\n	open(FILE, \\
">$filename\") or die \"Error: unable to open outp\
ut file\";\n	syswrite(FILE, $data);\n	close(FILE);\
\n    }\n}\n\nsub usage {\n    print STDERR <<EOF\\
nWU-BLAST\n========\n\nRapid sequence database sea\
rch programs utilizing the BLAST algorithm.\n   \n\
[Required]\n\n      --email       : str  : user em\
ail address \n  -p, --program	    : str  : BLAST p\
rogram to use: blastn, blastp, blastx, \n         \
                    tblastn or tblastx\n  -D, --da\
tabase    : str  : database to search\n  seqFile  \
         : file : query sequence data file (\"-\" \
for STDIN)\n\n[Optional]\n\n  -m, --matrix	    : s\
tr  : scoring matrix\n  -E, --exp	    : real : 0<E\
<= 1000. Statistical significance threshold\n     \
                        for reporting database seq\
uence matches.\n  -e, --echofilter  :      : displ\
ay the filtered query sequence in the output\n  -f\
, --filter	    : str  : activates filtering of the\
 query sequence\n  -b, --alignments  : int  : numb\
er of alignments to be reported\n  -s, --scores	  \
  : int  : number of scores to be reported\n  -S, \
--sensitivity : str  :\n  -t, --sort	    : str  :\\
n  -T, --stats       : str  :\n  -d, --strand     \
 : str  : DNA strand to search with in DNA vs. DNA\
 searches \n  -c, --topcombon   :      :\n\n[Gener\
al]	\n\n  -h, --help       :      : prints this he\
lp text\n  -a, --async      :      : forces to mak\
e an asynchronous query\n      --status     :     \
 : poll for the status of a job\n      --polljob  \
  :      : poll for the results of a job\n  -j, --\
jobid      : str  : jobid that was returned when a\
n asynchronous job \n                            w\
as submitted.\n  -O, --outfile    : str  : name of\
 the file results should be written to \n         \
                   (default is based on the jobid;\
 \"-\" for STDOUT)\n  -o, --outformat  : str  : tx\
t or xml output (no file is written)\n      --trac\
e	   :      : show SOAP messages being interchange\
d \n\nSynchronous job:\n\n  The results/errors are\
 returned as soon as the job is finished.\n  Usage\
: $scriptName --email <your\\@email> [options...] \
seqFile\n  Returns: saves the results to disk\n\nA\
synchronous job:\n\n  Use this if you want to retr\
ieve the results at a later time. The results \n  \
are stored for up to 24 hours. \n  The asynchronou\
s submission mode is recommended when users are su\
bmitting \n  batch jobs or large database searches\
	\n  Usage: $scriptName --async --email <your\\@em\
ail> [options...] seqFile\n  Returns : jobid\n\n  \
Use the jobid to query for the status of the job. \
\n  Usage: $scriptName --status --jobid <jobId>\n \
 Returns : string indicating the status of the job\
:\n    DONE - job has finished\n    RUNNING - job \
is running\n    NOT_FOUND - job cannot be found\n \
   ERROR - the jobs has encountered an error\n\n  \
When done, use the jobid to retrieve the status of\
 the job. \n  Usage: $scriptName --polljob --jobid\
 <jobId> [--outfile string]\n  Returns: saves the \
results to disk\n\n[Help]\n\nFor more detailed hel\
p information refer to \nhttp://www.ebi.ac.uk/blas\
t2/WU-Blast2_Help_frame.html\n \nEOF\n;\n}\n","\nm\
y $WSDL = 'http://www.ebi.ac.uk/Tools/webservices/\
wsdl/WSBlastpgp.wsdl';\n\nuse SOAP::Lite;\nuse Get\
opt::Long qw(:config no_ignore_case bundling);\nus\
e File::Basename;\n\nmy $checkInterval = 15;\n\nmy\
 %params=(\n	    'async' => '1', # Use async mode \
and simulate sync mode in client\n	    );\nGetOpti\
ons(\n    \"mode=s\"           => \\$params{mode},\
 # Search mode: PSI-Blast or PHI-Blast\n    \"data\
base|d=s\"     => \\$params{database}, # Database \
to search\n    \"matrix|M=s\"       => \\$params{m\
atrix},# Scoring maxtrix\n    \"exp|e=f\"         \
 => \\$params{exp}, # E-value\n    \"expmulti|h=f\\
"     => \\$params{expmulti}, # E-value\n    \"fil\
ter|F=s\"       => \\$params{filter}, # Low comple\
xity filter\n    \"dropoff|X=i\"      => \\$params\
{dropoff}, # Dropoff score\n    \"finaldropoff|Z=i\
\" => \\$params{finaldropoff}, # Final dropoff sco\
re\n    \"scores|v=i\"       => \\$params{scores},\
 # Max number of scores\n    \"align=i\"          \
=> \\$params{align}, # Alignment view\n    \"start\
region|S=i\"  => \\$params{startregion}, # Start o\
f region in query\n    \"endregion|H=i\"    => \\$\
params{endregion}, # End of region in query\n    \\
"maxpasses|j=i\"    => \\$params{maxpasses}, # Num\
ber of PSI iterations\n    \"opengap|G=i\"      =>\
 \\$params{opengap}, # Gap open penalty\n    \"ext\
endgap|E=i\"    => \\$params{extendgap}, # Gap ext\
ension penalty\n    \"pattern=s\"        => \\$par\
ams{pattern}, # PHI-BLAST pattern\n    \"usagemode\
|p=s\"    => \\$params{usagemode}, # PHI-BLAST pro\
gram\n    \"appxml=s\"         => \\$params{appxml\
}, # Application XML\n    \"sequence=s\"       => \
\\$sequence, # Query sequence\n    \"help\"	      \
 => \\$help, # Usage info\n    \"polljob\"	       \
=> \\$polljob, # Get results\n    \"status\"	     \
  => \\$status, # Get status\n    \"ids\"      	  \
     => \\$ids, # Get ids from result\n    \"jobid\
=s\"          => \\$jobid, # JobId\n    \"outfile=\
s\"        => \\$outfile, # Output filename\n    \\
"outformat|o=s\"    => \\$outformat, # Output file\
 format\n    \"async|a\"	       => \\$async, # Asy\
nc submission\n    \"email=s\"          => \\$para\
ms{email}, # User e-mail address\n    \"trace\"   \
         => \\$trace, # Show SOAP messages\n    );\
\n\nmy $scriptName = basename($0, ());\nif($help) \
{\n    &usage();\n    exit(0);\n}\n\nif ($trace){\\
n    print \"Tracing active\\n\";\n    SOAP::Lite-\
>import(+trace => 'debug');\n}\n\nmy $soap = SOAP:\
:Lite\n    ->service($WSDL)\n    ->on_fault(sub {\\
n        my $soap = shift;\n        my $res = shif\
t;\n        # Throw an exception for all faults\n \
       if(ref($res) eq '') {\n            die($res\
);\n        } else {\n            die($res->faults\
tring);\n        }\n        return new SOAP::SOM;\\
n    }\n               );\n\nif( !($polljob || $st\
atus || $ids) &&\n    !( (defined($ARGV[0]) && -f \
$ARGV[0]) || defined($sequence) )\n    ) {\n    pr\
int STDERR 'Error: bad option combination', \"\\n\\
";\n    &usage();\n    exit(1);\n}\nelsif($polljob\
 && defined($jobid)) {\n    print \"Getting result\
s for job $jobid\\n\";\n    getResults($jobid);\n}\
\nelsif($status && defined($jobid)) {\n    print S\
TDERR \"Getting status for job $jobid\\n\";\n    m\
y $result = $soap->checkStatus($jobid);\n    print\
 STDOUT $result, \"\\n\";\n    if($result eq 'DONE\
') {\n	print STDERR \"To get results: $scriptName \
--polljob --jobid $jobid\\n\";\n    }\n}  \nelsif(\
$ids && defined($jobid)) {\n    print STDERR \"Get\
ting ids from job $jobid\\n\";\n    getIds($jobid)\
;\n}\nelse {\n    if(-f $ARGV[0]) {	\n	$content={t\
ype=>'sequence', content=>read_file($ARGV[0])};	\n\
    }\n    if($sequence) {	\n	if(-f $sequence) {\n\
	    $content={type=>'sequence', content=>read_fil\
e($sequence)};	\n	} else {\n	    $content={type=>'\
sequence', content=>$sequence};\n	}\n    }\n    pu\
sh @content, $content;\n\n    my $jobid;\n    my $\
paramsData = SOAP::Data->name('params')->type(map=\
>\\%params);\n    my $contentData = SOAP::Data->na\
me('content')->value(\\@content);\n    # For SOAP:\
:Lite 0.60 and earlier parameters are passed direc\
tly\n    if($SOAP::Lite::VERSION eq '0.60' || $SOA\
P::Lite::VERSION =~ /0\\.[1-5]/) {\n        $jobid\
 = $soap->runBlastpgp($paramsData, $contentData);\\
n    }\n    # For SOAP::Lite 0.69 and later parame\
ter handling is different, so pass\n    # undef's \
for templated params, and then pass the formatted \
args.\n    else {\n        $jobid = $soap->runBlas\
tpgp(undef, undef,\n				    $paramsData, $contentD\
ata);\n    }\n\n    if (defined($async)) {\n	print\
 STDOUT $jobid, \"\\n\";\n        print STDERR \"T\
o check status: $scriptName --status --jobid $jobi\
d\\n\";\n    } else { # Synchronous mode\n        \
print STDERR \"JobId: $jobid\\n\";\n        sleep \
1;\n        getResults($jobid);\n    }\n}\n\nsub g\
etIds($) {\n    $jobid = shift;\n    my $results =\
 $soap->getIds($jobid);\n    for $result (@$result\
s){\n	print \"$result\\n\";\n    }\n}\n\nsub clien\
tPoll($) {\n    my $jobid = shift;\n    my $result\
 = 'PENDING';\n    # Check status and wait if not \
finished\n    #print STDERR \"Checking status: $jo\
bid\\n\";\n    while($result eq 'RUNNING' || $resu\
lt eq 'PENDING') {\n        $result = $soap->check\
Status($jobid);\n        print STDERR \"$result\\n\
\";\n        if($result eq 'RUNNING' || $result eq\
 'PENDING') {\n            # Wait before polling a\
gain.\n            sleep $checkInterval;\n        \
}\n    }\n}\n\nsub getResults($) {\n    $jobid = s\
hift;\n    # Check status, and wait if not finishe\
d\n    clientPoll($jobid);\n    # Use JobId if out\
put file name is not defined\n    unless(defined($\
outfile)) {\n        $outfile=$jobid;\n    }\n    \
# Get list of data types\n    my $resultTypes = $s\
oap->getResults($jobid);\n    # Get the data and w\
rite it to a file\n    if(defined($outformat)) { #\
 Specified data type\n        my $selResultType;\n\
        foreach my $resultType (@$resultTypes) {\n\
            if($resultType->{type} eq $outformat) \
{\n                $selResultType = $resultType;\n\
            }\n        }\n        $res=$soap->poll\
($jobid, $selResultType->{type});\n        write_f\
ile($outfile.'.'.$selResultType->{ext}, $res);\n  \
  } else { # Data types available\n        # Write\
 a file for each output type\n        for my $resu\
ltType (@$resultTypes){\n            #print \"Gett\
ing $resultType->{type}\\n\";\n            $res=$s\
oap->poll($jobid, $resultType->{type});\n         \
   write_file($outfile.'.'.$resultType->{ext}, $re\
s);\n        }\n    }\n}\n\nsub read_file($) {\n  \
  my $filename = shift;\n    open(FILE, $filename)\
;\n    my $content;\n    my $buffer;\n    while(sy\
sread(FILE, $buffer, 1024)) {\n	$content.= $buffer\
;\n    }\n    close(FILE);  \n    return $content;\
\n}\n\nsub write_file($$) {\n    my ($tmp,$entity)\
 = @_;\n    print STDERR \"Creating result file: \\
".$tmp.\"\\n\";\n    unless(open (FILE, \">$tmp\")\
) {\n	return 0;\n    }\n    syswrite(FILE, $entity\
);\n    close (FILE);\n    return 1;\n}\n\nsub usa\
ge {\n    print STDERR <<EOF\nBlastpgp\n========\n\
   \nThe blastpgp program implements the PSI-BLAST\
 and PHI-BLAST variations\nof NCBI BLAST.\n\nFor m\
ore detailed help information refer to\nhttp://www\
.ebi.ac.uk/blastpgp/blastpsi_help_frame.html\n \nB\
lastpgp specific options:\n\n[Required]\n\n      -\
-mode            : str  : search mode to use: PSI-\
Blast or PHI-Blast\n  -d, --database        : str \
 : protein database to search\n  seqFile          \
     : file : query sequence\n\n[Optional]\n\n  -M\
, --matrix          : str  : scoring matrix\n  -e,\
 --exp             : real : Expectation value\n  -\
h, --expmulti        : real : threshold (multipass\
 model)\n  -F, --filter          : str  : filter q\
uery sequence with SEG [T,F]\n  -m, --align       \
    : int  : alignment view option:\n             \
                    0 - pairwise, 1 - M/S identiti\
es,\n                                 2 - M/S non-\
identities, 3 - Flat identities,\n                \
                 4 - Flat non-identities\n  -G, --\
opengap         : int  : cost to open a gap\n  -E,\
 --extendgap       : int  : cost to extend a gap\n\
  -g, --gapalign        : str  : Gapped [T,F]\n  -\
v, --scores          : int  : number of scores to \
be reported\n  -j, --maxpasses       : int  : numb\
er of iterations\n  -X, --dropoff         : int  :\
 Dropoff score\n  -Z, --finaldropoff    : int  : D\
ropoff for final alignment\n  -S, --startregion   \
  : int  : Start of required region in query\n  -H\
, --endregion       : int  : End of required regio\
n in query\n  -k, --pattern         : str  : Hit F\
ile (PHI-BLAST only)\n  -p, --usagemode       : st\
r  : Program option (PHI-BLAST only):\n           \
                      blastpgp, patseedp, seedp\n\\
n[General]\n\n      --help            :      : pri\
nts this help text\n  -a, --async           :     \
 : forces to make an asynchronous query\n      --s\
tatus          :      : poll for the status of a j\
ob\n      --polljob         :      : poll for the \
results of a job\n      --jobid           : str  :\
 jobid of an asynchronous job\n      --ids        \
     :      : get hit identifiers for result \n  -\
O, --outfile         : str  : name of the file res\
ults should be written to\n                       \
          (default is based on the jobid)\n  -o, -\
-outformat       : str  : txt or xml output (no fi\
le is written)\n      --trace           :      : s\
how SOAP messages being interchanged\n\nSynchronou\
s job:\n\n  The results/errors are returned as soo\
n as the job is finished.\n  Usage: blastpgp.pl --\
email <your@email> [options...] seqfile\n  Returns\
: saves the results to disk\n\nAsynchronous job:\n\
\n  Use this if you want to retrieve the results a\
t a later time. The results\n  are stored for up t\
o 24 hours.\n  The asynchronous submission mode is\
 recommended when users are submitting\n  batch jo\
bs or large database searches\n  Usage: blastpgp.p\
l --email <your@email> --async [options...] seqFil\
e\n  Returns: jobid\n\n  Use the jobid to query fo\
r the status of the job.\n  Usage: blastpgp.pl --s\
tatus --jobid <jobId>\n  Returns: string indicatin\
g the status of the job\n    DONE - job has finish\
ed\n    RUNNING - job is running\n    NOT_FOUND - \
job cannot be found\n    ERROR - the jobs has enco\
untered an error\n\n  When done, use the jobid to \
retrieve the results of the job.\n  Usage: blastpg\
p.pl --polljob --jobid <jobId> [--outfile <fileNam\
e>]\n  Returns: saves the results to disk\nEOF\n;\\
n}\n","\n=head1 NAME\n\nncbiblast_lwp.pl\n\n=head1\
 DESCRIPTION\n\nNCBI BLAST (REST) web service Perl\
 client using L<LWP>.\n\nTested with:\n\n=over\n\n\
=item *\nL<LWP> 5.79, L<XML::Simple> 2.12 and Perl\
 5.8.3\n\n=item *\nL<LWP> 5.808, L<XML::Simple> 2.\
18 and Perl 5.8.8 (Ubuntu 8.04 LTS)\n\n=item *\nL<\
LWP> 5.834, L<XML::Simple> 2.18 and Perl 5.10.1 (U\
buntu 10.04 LTS)\n\n=item *\nL<LWP> 6.03, L<XML::S\
imple> 2.18 and Perl 5.14.2 (Ubuntu 12.04 LTS)\n\n\
=back\n\nFor further information see:\n\n=over\n\n\
=item *\nL<http://www.ebi.ac.uk/Tools/webservices/\
services/sss/ncbi_blast_rest>\n\n=item *\nL<http:/\
/www.ebi.ac.uk/Tools/webservices/tutorials/perl>\n\
\n=back\n\n=head1 LICENSE\n\nCopyright 2012-2013 E\
MBL - European Bioinformatics Institute\n\nLicense\
d under the Apache License, Version 2.0 (the \"Lic\
ense\");\nyou may not use this file except in comp\
liance with the License.\nYou may obtain a copy of\
 the License at\n\n    http://www.apache.org/licen\
ses/LICENSE-2.0\n\nUnless required by applicable l\
aw or agreed to in writing, software\ndistributed \
under the License is distributed on an \"AS IS\" B\
ASIS,\nWITHOUT WARRANTIES OR CONDITIONS OF ANY KIN\
D, either express or implied.\nSee the License for\
 the specific language governing permissions and\n\
limitations under the License.\n\n=head1 VERSION\n\
\n$Id: ncbiblast_lwp.pl 2560 2013-03-20 12:56:31Z \
hpm $\n\n=cut\n\nuse strict;\nuse warnings;\n\nuse\
 English;\nuse LWP;\nuse XML::Simple;\nuse Getopt:\
:Long qw(:config no_ignore_case bundling);\nuse Fi\
le::Basename;\nuse Data::Dumper;\n\nmy $baseUrl = \
'http://www.ebi.ac.uk/Tools/services/rest/ncbiblas\
t';\n\nmy $checkInterval = 3;\n\nmy $outputLevel =\
 1;\n\nmy $numOpts = scalar(@ARGV);\nmy %params = \
( 'debugLevel' => 0 );\n\nmy %tool_params = ();\nG\
etOptions(\n\n	# Tool specific options\n	'program|\
p=s'  => \\$tool_params{'program'},   # blastp, bl\
astn, blastx, etc.\n	'database|D=s' => \\$params{'\
database'},       # Database(s) to search\n	'matri\
x|m=s'   => \\$tool_params{'matrix'},    # Scoring\
 martix to use\n	'exp|E=f'      => \\$tool_params{\
'exp'},       # E-value threshold\n	'filter|f=s'  \
 => \\$tool_params{'filter'},    # Low complexity \
filter\n	'align|A=i'    => \\$tool_params{'align'}\
,     # Pairwise alignment format\n	'scores|s=i'  \
 => \\$tool_params{'scores'},    # Number of score\
s\n	'alignments|n=i' => \\$tool_params{'alignments\
'},   # Number of alignments\n	'dropoff|d=i'    =>\
 \\$tool_params{'dropoff'},      # Dropoff score\n\
	'match_scores=s' => \\$tool_params{'match_scores'\
}, # Match/missmatch scores\n	'match|u=i'      => \
\\$params{'match'},             # Match score\n	'm\
ismatch|v=i'   => \\$params{'mismatch'},          \
# Mismatch score\n	'gapopen|o=i'    => \\$tool_par\
ams{'gapopen'},      # Open gap penalty\n	'gapext|\
x=i'     => \\$tool_params{'gapext'},       # Gap \
extension penality\n	'gapalign|g'     => \\$tool_p\
arams{'gapalign'},     # Optimise gap alignments\n\
	'stype=s' => \\$tool_params{'stype'},    # Sequen\
ce type\n	'seqrange=s' => \\$tool_params{'seqrange\
'},    # Query subsequence\n	'sequence=s' => \\$pa\
rams{'sequence'},         # Query sequence\n	'mult\
ifasta' => \\$params{'multifasta'},       # Multip\
le fasta input\n\n	# Compatability options, old co\
mmand-line\n	'numal|n=i'     => \\$params{'numal'}\
,        # Number of alignments\n	'opengap|o=i'   \
=> \\$params{'opengap'},      # Open gap penalty\n\
	'extendgap|x=i' => \\$params{'extendgap'},    # G\
ap extension penality\n	\n	# Generic options\n	'em\
ail=s'       => \\$params{'email'},          # Use\
r e-mail address\n	'title=s'       => \\$params{'t\
itle'},          # Job title\n	'outfile=s'     => \
\\$params{'outfile'},        # Output file name\n	\
'outformat=s'   => \\$params{'outformat'},      # \
Output file type\n	'jobid=s'       => \\$params{'j\
obid'},          # JobId\n	'help|h'        => \\$p\
arams{'help'},           # Usage help\n	'async'   \
      => \\$params{'async'},          # Asynchrono\
us submission\n	'polljob'       => \\$params{'poll\
job'},        # Get results\n	'resultTypes'   => \\
\$params{'resultTypes'},    # Get result types\n	'\
status'        => \\$params{'status'},         # G\
et status\n	'params'        => \\$params{'params'}\
,         # List input parameters\n	'paramDetail=s\
' => \\$params{'paramDetail'},    # Get details fo\
r parameter\n	'quiet'         => \\$params{'quiet'\
},          # Decrease output level\n	'verbose'   \
    => \\$params{'verbose'},        # Increase out\
put level\n	'debugLevel=i'  => \\$params{'debugLev\
el'},     # Debug output level\n	'baseUrl=s'     =\
> \\$baseUrl,                  # Base URL for serv\
ice.\n);\nif ( $params{'verbose'} ) { $outputLevel\
++ }\nif ( $params{'quiet'} )  { $outputLevel-- }\\
n\n&print_debug_message( 'MAIN', 'LWP::VERSION: ' \
. $LWP::VERSION,\n	1 );\n\n&print_debug_message( '\
MAIN', \"params:\\n\" . Dumper( \\%params ),      \
     11 );\n&print_debug_message( 'MAIN', \"tool_p\
arams:\\n\" . Dumper( \\%tool_params ), 11 );\n\nm\
y $ua;\n\nmy $scriptName = basename( $0, () );\n\n\
if ( $params{'help'} || $numOpts == 0 ) {\n	&usage\
();\n	exit(0);\n}\n\n&print_debug_message( 'MAIN',\
 'baseUrl: ' . $baseUrl, 1 );\n\nif (\n	!(\n		   $\
params{'polljob'}\n		|| $params{'resultTypes'}\n		\
|| $params{'status'}\n		|| $params{'params'}\n		||\
 $params{'paramDetail'}\n	)\n	&& !( defined( $ARGV\
[0] ) || defined( $params{'sequence'} ) )\n  )\n{\\
n\n	# Bad argument combination, so print error mes\
sage and usage\n	print STDERR 'Error: bad option c\
ombination', \"\\n\";\n	&usage();\n	exit(1);\n}\n\\
nelsif ( $params{'params'} ) {\n	&print_tool_param\
s();\n}\n\nelsif ( $params{'paramDetail'} ) {\n	&p\
rint_param_details( $params{'paramDetail'} );\n}\n\
\nelsif ( $params{'status'} && defined( $params{'j\
obid'} ) ) {\n	&print_job_status( $params{'jobid'}\
 );\n}\n\nelsif ( $params{'resultTypes'} && define\
d( $params{'jobid'} ) ) {\n	&print_result_types( $\
params{'jobid'} );\n}\n\nelsif ( $params{'polljob'\
} && defined( $params{'jobid'} ) ) {\n	&get_result\
s( $params{'jobid'} );\n}\n\nelse {\n\n	# Multiple\
 input sequence mode, assume fasta format.\n	if ( \
$params{'multifasta'} ) {\n		&multi_submit_job();\\
n	}\n\n	# Entry identifier list file.\n	elsif (( d\
efined( $params{'sequence'} ) && $params{'sequence\
'} =~ m/^\\@/ )\n		|| ( defined( $ARGV[0] ) && $AR\
GV[0] =~ m/^\\@/ ) )\n	{\n		my $list_filename = $p\
arams{'sequence'} || $ARGV[0];\n		$list_filename =\
~ s/^\\@//;\n		&list_file_submit_job($list_filenam\
e);\n	}\n\n	# Default: single sequence/identifier.\
\n	else {\n\n		# Load the sequence data and submit\
.\n		&submit_job( &load_data() );\n	}\n}\n\n=head1\
 FUNCTIONS\n\n=cut\n\n\n=head2 rest_user_agent()\n\
\nGet a LWP UserAgent to use to perform REST reque\
sts.\n\n  my $ua = &rest_user_agent();\n\n=cut\n\n\
sub rest_user_agent() {\n	print_debug_message( 're\
st_user_agent', 'Begin', 21 );\n	# Create an LWP U\
serAgent for making HTTP calls.\n	my $ua = LWP::Us\
erAgent->new();\n	# Set 'User-Agent' HTTP header t\
o identifiy the client.\n	'$Revision: 2560 $' =~ m\
/(\\d+)/;\n	$ua->agent(\"EBI-Sample-Client/$1 ($sc\
riptName; $OSNAME) \" . $ua->agent());\n	# Configu\
re HTTP proxy support from environment.\n	$ua->env\
_proxy;\n	print_debug_message( 'rest_user_agent', \
'End', 21 );\n	return $ua;\n}\n\n=head2 rest_error\
()\n\nCheck a REST response for an error condition\
. An error is mapped to a die.\n\n  &rest_error($r\
esponse, $content_data);\n\n=cut\n\nsub rest_error\
() {\n	print_debug_message( 'rest_error', 'Begin',\
 21 );\n	my $response = shift;\n	my $contentdata;\\
n	if(scalar(@_) > 0) {\n		$contentdata = shift;\n	\
}\n	if(!defined($contentdata) || $contentdata eq '\
') {\n		$contentdata = $response->content();\n	}\n\
	# Check for HTTP error codes\n	if ( $response->is\
_error ) {\n		my $error_message = '';\n		# HTML re\
sponse.\n		if(	$contentdata =~ m/<h1>([^<]+)<\\/h1\
>/ ) {\n			$error_message = $1;\n		}\n		#  XML res\
ponse.\n		elsif($contentdata =~ m/<description>([^\
<]+)<\\/description>/) {\n			$error_message = $1;\\
n		}\n		die 'http status: ' . $response->code . ' \
' . $response->message . '  ' . $error_message;\n	\
}\n	print_debug_message( 'rest_error', 'End', 21 )\
;\n}\n\n=head2 rest_request()\n\nPerform a REST re\
quest (HTTP GET).\n\n  my $response_str = &rest_re\
quest($url);\n\n=cut\n\nsub rest_request {\n	print\
_debug_message( 'rest_request', 'Begin', 11 );\n	m\
y $requestUrl = shift;\n	print_debug_message( 'res\
t_request', 'URL: ' . $requestUrl, 11 );\n\n	# Get\
 an LWP UserAgent.\n	$ua = &rest_user_agent() unle\
ss defined($ua);\n	# Available HTTP compression me\
thods.\n	my $can_accept;\n	eval {\n	    $can_accep\
t = HTTP::Message::decodable();\n	};\n	$can_accept\
 = '' unless defined($can_accept);\n	# Perform the\
 request\n	my $response = $ua->get($requestUrl,\n	\
	'Accept-Encoding' => $can_accept, # HTTP compress\
ion.\n	);\n	print_debug_message( 'rest_request', '\
HTTP status: ' . $response->code,\n		11 );\n	print\
_debug_message( 'rest_request',\n		'response lengt\
h: ' . length($response->content()), 11 );\n	print\
_debug_message( 'rest_request',\n		'request:' .\"\\
\n\" . $response->request()->as_string(), 32 );\n	\
print_debug_message( 'rest_request',\n		'response:\
 ' . \"\\n\" . $response->as_string(), 32 );\n	# U\
npack possibly compressed response.\n	my $retVal;\\
n	if ( defined($can_accept) && $can_accept ne '') \
{\n	    $retVal = $response->decoded_content();\n	\
}\n	# If unable to decode use orginal content.\n	$\
retVal = $response->content() unless defined($retV\
al);\n	# Check for an error.\n	&rest_error($respon\
se, $retVal);\n	print_debug_message( 'rest_request\
', 'retVal: ' . $retVal, 12 );\n	print_debug_messa\
ge( 'rest_request', 'End', 11 );\n\n	# Return the \
response data\n	return $retVal;\n}\n\n=head2 rest_\
get_parameters()\n\nGet list of tool parameter nam\
es.\n\n  my (@param_list) = &rest_get_parameters()\
;\n\n=cut\n\nsub rest_get_parameters {\n	print_deb\
ug_message( 'rest_get_parameters', 'Begin', 1 );\n\
	my $url                = $baseUrl . '/parameters/\
';\n	my $param_list_xml_str = rest_request($url);\\
n	my $param_list_xml     = XMLin($param_list_xml_s\
tr);\n	my (@param_list)       = @{ $param_list_xml\
->{'id'} };\n	print_debug_message( 'rest_get_param\
eters', 'End', 1 );\n	return (@param_list);\n}\n\n\
=head2 rest_get_parameter_details()\n\nGet details\
 of a tool parameter.\n\n  my $paramDetail = &rest\
_get_parameter_details($param_name);\n\n=cut\n\nsu\
b rest_get_parameter_details {\n	print_debug_messa\
ge( 'rest_get_parameter_details', 'Begin', 1 );\n	\
my $parameterId = shift;\n	print_debug_message( 'r\
est_get_parameter_details',\n		'parameterId: ' . $\
parameterId, 1 );\n	my $url                  = $ba\
seUrl . '/parameterdetails/' . $parameterId;\n	my \
$param_detail_xml_str = rest_request($url);\n	my $\
param_detail_xml     = XMLin($param_detail_xml_str\
);\n	print_debug_message( 'rest_get_parameter_deta\
ils', 'End', 1 );\n	return ($param_detail_xml);\n}\
\n\n=head2 rest_run()\n\nSubmit a job.\n\n  my $jo\
b_id = &rest_run($email, $title, \\%params );\n\n=\
cut\n\nsub rest_run {\n	print_debug_message( 'rest\
_run', 'Begin', 1 );\n	my $email  = shift;\n	my $t\
itle  = shift;\n	my $params = shift;\n	print_debug\
_message( 'rest_run', 'email: ' . $email, 1 );\n	i\
f ( defined($title) ) {\n		print_debug_message( 'r\
est_run', 'title: ' . $title, 1 );\n	}\n	print_deb\
ug_message( 'rest_run', 'params: ' . Dumper($param\
s), 1 );\n\n	# Get an LWP UserAgent.\n	$ua = &rest\
_user_agent() unless defined($ua);\n\n	# Clean up \
parameters\n	my (%tmp_params) = %{$params};\n	$tmp\
_params{'email'} = $email;\n	$tmp_params{'title'} \
= $title;\n	foreach my $param_name ( keys(%tmp_par\
ams) ) {\n		if ( !defined( $tmp_params{$param_name\
} ) ) {\n			delete $tmp_params{$param_name};\n		}\\
n	}\n\n	# Submit the job as a POST\n	my $url = $ba\
seUrl . '/run';\n	my $response = $ua->post( $url, \
\\%tmp_params );\n	print_debug_message( 'rest_run'\
, 'HTTP status: ' . $response->code, 11 );\n	print\
_debug_message( 'rest_run',\n		'request:' .\"\\n\"\
 . $response->request()->as_string(), 11 );\n	prin\
t_debug_message( 'rest_run',\n		'response: ' . len\
gth($response->as_string()) . \"\\n\" . $response-\
>as_string(), 11 );\n\n	# Check for an error.\n	&r\
est_error($response);\n\n	# The job id is returned\
\n	my $job_id = $response->content();\n	print_debu\
g_message( 'rest_run', 'End', 1 );\n	return $job_i\
d;\n}\n\n=head2 rest_get_status()\n\nCheck the sta\
tus of a job.\n\n  my $status = &rest_get_status($\
job_id);\n\n=cut\n\nsub rest_get_status {\n	print_\
debug_message( 'rest_get_status', 'Begin', 1 );\n	\
my $job_id = shift;\n	print_debug_message( 'rest_g\
et_status', 'jobid: ' . $job_id, 2 );\n	my $status\
_str = 'UNKNOWN';\n	my $url        = $baseUrl . '/\
status/' . $job_id;\n	$status_str = &rest_request(\
$url);\n	print_debug_message( 'rest_get_status', '\
status_str: ' . $status_str, 2 );\n	print_debug_me\
ssage( 'rest_get_status', 'End', 1 );\n	return $st\
atus_str;\n}\n\n=head2 rest_get_result_types()\n\n\
Get list of result types for finished job.\n\n  my\
 (@result_types) = &rest_get_result_types($job_id)\
;\n\n=cut\n\nsub rest_get_result_types {\n	print_d\
ebug_message( 'rest_get_result_types', 'Begin', 1 \
);\n	my $job_id = shift;\n	print_debug_message( 'r\
est_get_result_types', 'jobid: ' . $job_id, 2 );\n\
	my (@resultTypes);\n	my $url                     \
 = $baseUrl . '/resulttypes/' . $job_id;\n	my $res\
ult_type_list_xml_str = &rest_request($url);\n	my \
$result_type_list_xml     = XMLin($result_type_lis\
t_xml_str);\n	(@resultTypes) = @{ $result_type_lis\
t_xml->{'type'} };\n	print_debug_message( 'rest_ge\
t_result_types',\n		scalar(@resultTypes) . ' resul\
t types', 2 );\n	print_debug_message( 'rest_get_re\
sult_types', 'End', 1 );\n	return (@resultTypes);\\
n}\n\n=head2 rest_get_result()\n\nGet result data \
of a specified type for a finished job.\n\n  my $r\
esult = rest_get_result($job_id, $result_type);\n\\
n=cut\n\nsub rest_get_result {\n	print_debug_messa\
ge( 'rest_get_result', 'Begin', 1 );\n	my $job_id \
= shift;\n	my $type   = shift;\n	print_debug_messa\
ge( 'rest_get_result', 'jobid: ' . $job_id, 1 );\n\
	print_debug_message( 'rest_get_result', 'type: ' \
. $type,    1 );\n	my $url    = $baseUrl . '/resul\
t/' . $job_id . '/' . $type;\n	my $result = &rest_\
request($url);\n	print_debug_message( 'rest_get_re\
sult', length($result) . ' characters',\n		1 );\n	\
print_debug_message( 'rest_get_result', 'End', 1 )\
;\n	return $result;\n}\n\n\n=head2 print_debug_mes\
sage()\n\nPrint debug message at specified debug l\
evel.\n\n  &print_debug_message($method_name, $mes\
sage, $level);\n\n=cut\n\nsub print_debug_message \
{\n	my $function_name = shift;\n	my $message      \
 = shift;\n	my $level         = shift;\n	if ( $lev\
el <= $params{'debugLevel'} ) {\n		print STDERR '[\
', $function_name, '()] ', $message, \"\\n\";\n	}\\
n}\n\n=head2 print_tool_params()\n\nPrint list of \
tool parameters.\n\n  &print_tool_params();\n\n=cu\
t\n\nsub print_tool_params {\n	print_debug_message\
( 'print_tool_params', 'Begin', 1 );\n	my (@param_\
list) = &rest_get_parameters();\n	foreach my $para\
m ( sort(@param_list) ) {\n		print $param, \"\\n\"\
;\n	}\n	print_debug_message( 'print_tool_params', \
'End', 1 );\n}\n\n=head2 print_param_details()\n\n\
Print details of a tool parameter.\n\n  &print_par\
am_details($param_name);\n\n=cut\n\nsub print_para\
m_details {\n	print_debug_message( 'print_param_de\
tails', 'Begin', 1 );\n	my $paramName = shift;\n	p\
rint_debug_message( 'print_param_details', 'paramN\
ame: ' . $paramName, 2 );\n	my $paramDetail = &res\
t_get_parameter_details($paramName);\n	print $para\
mDetail->{'name'}, \"\\t\", $paramDetail->{'type'}\
, \"\\n\";\n	print $paramDetail->{'description'}, \
\"\\n\";\n	if(defined($paramDetail->{'values'}->{'\
value'})) {\n		if(ref($paramDetail->{'values'}->{'\
value'}) eq 'ARRAY') {\n			foreach my $value ( @{ \
$paramDetail->{'values'}->{'value'} } ) {\n				&pr\
int_param_value($value);\n			}\n		}\n		else {\n			\
	&print_param_value($paramDetail->{'values'}->{'va\
lue'});\n		}\n	}\n	print_debug_message( 'print_par\
am_details', 'End', 1 );\n}\n\n=head2 print_param_\
value()\n\nPrint details of a tool parameter value\
.\n\n  &print_param_details($param_value);\n\nUsed\
 by print_param_details() to handle both singluar \
and array values.\n\n=cut\n\nsub print_param_value\
 {\n	my $value = shift;\n	print $value->{'value'};\
\n	if ( $value->{'defaultValue'} eq 'true' ) {\n		\
print \"\\t\", 'default';\n	}\n	print \"\\n\";\n	p\
rint \"\\t\", $value->{'label'}, \"\\n\";\n	if ( d\
efined( $value->{'properties'} ) ) {\n		foreach\n	\
	  my $key ( sort( keys( %{ $value->{'properties'}\
{'property'} } ) ) )\n		{\n			if ( ref( $value->{'\
properties'}{'property'}{$key} ) eq 'HASH'\n				&&\
 defined( $value->{'properties'}{'property'}{$key}\
{'value'} )\n			  )\n			{\n				print \"\\t\", $key\
, \"\\t\",\n				  $value->{'properties'}{'property\
'}{$key}{'value'}, \"\\n\";\n			}\n			else {\n				\
print \"\\t\", $value->{'properties'}{'property'}{\
'key'},\n				  \"\\t\", $value->{'properties'}{'pr\
operty'}{'value'}, \"\\n\";\n				last;\n			}\n		}\\
n	}\n}\n\n=head2 print_job_status()\n\nPrint statu\
s of a job.\n\n  &print_job_status($job_id);\n\n=c\
ut\n\nsub print_job_status {\n	print_debug_message\
( 'print_job_status', 'Begin', 1 );\n	my $jobid = \
shift;\n	print_debug_message( 'print_job_status', \
'jobid: ' . $jobid, 1 );\n	if ( $outputLevel > 0 )\
 {\n		print STDERR 'Getting status for job ', $job\
id, \"\\n\";\n	}\n	my $result = &rest_get_status($\
jobid);\n	print \"$result\\n\";\n	if ( $result eq \
'FINISHED' && $outputLevel > 0 ) {\n		print STDERR\
 \"To get results: $scriptName --polljob --jobid \\
" . $jobid\n		  . \"\\n\";\n	}\n	print_debug_messa\
ge( 'print_job_status', 'End', 1 );\n}\n\n=head2 p\
rint_result_types()\n\nPrint available result type\
s for a job.\n\n  &print_result_types($job_id);\n\\
n=cut\n\nsub print_result_types {\n	print_debug_me\
ssage( 'result_types', 'Begin', 1 );\n	my $jobid =\
 shift;\n	print_debug_message( 'result_types', 'jo\
bid: ' . $jobid, 1 );\n	if ( $outputLevel > 0 ) {\\
n		print STDERR 'Getting result types for job ', $\
jobid, \"\\n\";\n	}\n	my $status = &rest_get_statu\
s($jobid);\n	if ( $status eq 'PENDING' || $status \
eq 'RUNNING' ) {\n		print STDERR 'Error: Job statu\
s is ', $status,\n		  '. To get result types the j\
ob must be finished.', \"\\n\";\n	}\n	else {\n		my\
 (@resultTypes) = &rest_get_result_types($jobid);\\
n		if ( $outputLevel > 0 ) {\n			print STDOUT 'Ava\
ilable result types:', \"\\n\";\n		}\n		foreach my\
 $resultType (@resultTypes) {\n			print STDOUT $re\
sultType->{'identifier'}, \"\\n\";\n			if ( define\
d( $resultType->{'label'} ) ) {\n				print STDOUT \
\"\\t\", $resultType->{'label'}, \"\\n\";\n			}\n	\
		if ( defined( $resultType->{'description'} ) ) {\
\n				print STDOUT \"\\t\", $resultType->{'descrip\
tion'}, \"\\n\";\n			}\n			if ( defined( $resultTy\
pe->{'mediaType'} ) ) {\n				print STDOUT \"\\t\",\
 $resultType->{'mediaType'}, \"\\n\";\n			}\n			if\
 ( defined( $resultType->{'fileSuffix'} ) ) {\n			\
	print STDOUT \"\\t\", $resultType->{'fileSuffix'}\
, \"\\n\";\n			}\n		}\n		if ( $status eq 'FINISHED\
' && $outputLevel > 0 ) {\n			print STDERR \"\\n\"\
, 'To get results:', \"\\n\",\n			  \"  $scriptNam\
e --polljob --jobid \" . $params{'jobid'} . \"\\n\\
",\n			  \"  $scriptName --polljob --outformat <ty\
pe> --jobid \"\n			  . $params{'jobid'} . \"\\n\";\
\n		}\n	}\n	print_debug_message( 'result_types', '\
End', 1 );\n}\n\n=head2 submit_job()\n\nSubmit a j\
ob to the service.\n\n  &submit_job($seq);\n\n=cut\
\n\nsub submit_job {\n	print_debug_message( 'submi\
t_job', 'Begin', 1 );\n\n	# Set input sequence\n	$\
tool_params{'sequence'} = shift;\n\n	# Load parame\
ters\n	&load_params();\n\n	# Submit the job\n	my $\
jobid = &rest_run( $params{'email'}, $params{'titl\
e'}, \\%tool_params );\n\n	# Simulate sync/async m\
ode\n	if ( defined( $params{'async'} ) ) {\n		prin\
t STDOUT $jobid, \"\\n\";\n		if ( $outputLevel > 0\
 ) {\n			print STDERR\n			  \"To check status: $sc\
riptName --status --jobid $jobid\\n\";\n		}\n	}\n	\
else {\n		if ( $outputLevel > 0 ) {\n			print STDE\
RR \"JobId: $jobid\\n\";\n		}\n		sleep 1;\n		&get_\
results($jobid);\n	}\n	print_debug_message( 'submi\
t_job', 'End', 1 );\n}\n\n=head2 multi_submit_job(\
)\n\nSubmit multiple jobs assuming input is a coll\
ection of fasta formatted sequences.\n\n  &multi_s\
ubmit_job();\n\n=cut\n\nsub multi_submit_job {\n	p\
rint_debug_message( 'multi_submit_job', 'Begin', 1\
 );\n	my $jobIdForFilename = 1;\n	$jobIdForFilenam\
e = 0 if ( defined( $params{'outfile'} ) );\n	my (\
@filename_list) = ();\n\n	# Query sequence\n	if ( \
defined( $ARGV[0] ) ) {    # Bare option\n		if ( -\
f $ARGV[0] || $ARGV[0] eq '-' ) {    # File\n			pu\
sh( @filename_list, $ARGV[0] );\n		}\n		else {\n		\
	warn 'Warning: Input file \"' . $ARGV[0] . '\" do\
es not exist'\n		}\n	}\n	if ( $params{'sequence'} \
) {                   # Via --sequence\n		if ( -f \
$params{'sequence'} || $params{'sequence'} eq '-' \
) {    # File\n			push( @filename_list, $params{'s\
equence'} );\n		}\n		else {\n			warn 'Warning: Inp\
ut file \"' . $params{'sequence'} . '\" does not e\
xist'\n		}\n	}\n\n	$/ = '>';\n	foreach my $filenam\
e (@filename_list) {\n		my $INFILE;\n		if($filenam\
e eq '-') { # STDIN.\n			open( $INFILE, '<-' )\n		\
	  or die 'Error: unable to STDIN (' . $! . ')';\n\
		} else { # File.\n			open( $INFILE, '<', $filena\
me )\n			  or die 'Error: unable to open file ' . \
$filename . ' (' . $! . ')';\n		}\n		while (<$INFI\
LE>) {\n			my $seq = $_;\n			$seq =~ s/>$//;\n			i\
f ( $seq =~ m/(\\S+)/ ) {\n				print STDERR \"Subm\
itting job for: $1\\n\"\n				  if ( $outputLevel >\
 0 );\n				$seq = '>' . $seq;\n				&print_debug_me\
ssage( 'multi_submit_job', $seq, 11 );\n				&submi\
t_job($seq);\n				$params{'outfile'} = undef if ( \
$jobIdForFilename == 1 );\n			}\n		}\n		close $INF\
ILE;\n	}\n	print_debug_message( 'multi_submit_job'\
, 'End', 1 );\n}\n\n=head2 list_file_submit_job()\\
n\nSubmit multiple jobs using a file containing a \
list of entry identifiers as \ninput.\n\n  &list_f\
ile_submit_job($list_filename)\n\n=cut\n\nsub list\
_file_submit_job {\n	my $filename         = shift;\
\n	my $jobIdForFilename = 1;\n	$jobIdForFilename =\
 0 if ( defined( $params{'outfile'} ) );\n\n	# Ite\
rate over identifiers, submitting each job\n	my $L\
ISTFILE;\n	if($filename eq '-') { # STDIN.\n		open\
( $LISTFILE, '<-' )\n		  or die 'Error: unable to \
STDIN (' . $! . ')';\n	} else { # File.\n		open( $\
LISTFILE, '<', $filename )\n		  or die 'Error: una\
ble to open file ' . $filename . ' (' . $! . ')';\\
n	}\n	while (<$LISTFILE>) {\n		my $line = $_;\n		c\
homp($line);\n		if ( $line ne '' ) {\n			&print_de\
bug_message( 'list_file_submit_job', 'line: ' . $l\
ine, 2 );\n			if ( $line =~ m/\\w:\\w/ ) {    # Ch\
eck this is an identifier\n				print STDERR \"Subm\
itting job for: $line\\n\"\n				  if ( $outputLeve\
l > 0 );\n				&submit_job($line);\n			}\n			else {\
\n				print STDERR\n\"Warning: line \\\"$line\\\" \
is not recognised as an identifier\\n\";\n			}\n		\
}\n		$params{'outfile'} = undef if ( $jobIdForFile\
name == 1 );\n	}\n	close $LISTFILE;\n}\n\n=head2 l\
oad_data()\n\nLoad sequence data from file or opti\
on specified on the command-line.\n\n  &load_data(\
);\n\n=cut\n\nsub load_data {\n	print_debug_messag\
e( 'load_data', 'Begin', 1 );\n	my $retSeq;\n\n	# \
Query sequence\n	if ( defined( $ARGV[0] ) ) {    #\
 Bare option\n		if ( -f $ARGV[0] || $ARGV[0] eq '-\
' ) {    # File\n			$retSeq = &read_file( $ARGV[0]\
 );\n		}\n		else {                                \
     # DB:ID or sequence\n			$retSeq = $ARGV[0];\n\
		}\n	}\n	if ( $params{'sequence'} ) {            \
       # Via --sequence\n		if ( -f $params{'sequen\
ce'} || $params{'sequence'} eq '-' ) {    # File\n\
			$retSeq = &read_file( $params{'sequence'} );\n	\
	}\n		else {    # DB:ID or sequence\n			$retSeq = \
$params{'sequence'};\n		}\n	}\n	print_debug_messag\
e( 'load_data', 'End', 1 );\n	return $retSeq;\n}\n\
\n=head2 load_params()\n\nLoad job parameters from\
 command-line options.\n\n  &load_params();\n\n=cu\
t\n\nsub load_params {\n	print_debug_message( 'loa\
d_params', 'Begin', 1 );\n\n	# Database(s) to sear\
ch\n	my (@dbList) = split /[ ,]/, $params{'databas\
e'};\n	$tool_params{'database'} = \\@dbList;\n\n	#\
 Match/missmatch\n	if ( $params{'match'} && $param\
s{'missmatch'} ) {\n		$tool_params{'match_scores'}\
 =\n		  $params{'match'} . ',' . $params{'missmatc\
h'};\n	}\n	\n	# Compatability options, old command\
-line\n	if(!$tool_params{'alignments'} && $params{\
'numal'}) {\n		$tool_params{'alignments'} = $param\
s{'numal'};\n	}\n	if(!$tool_params{'gapopen'} && $\
params{'opengap'}) {\n		$tool_params{'gapopen'} = \
$params{'opengap'};\n	}\n	if(!$tool_params{'gapext\
'} && $params{'extendgap'}) {\n		$tool_params{'gap\
ext'} = $params{'extendgap'};\n	}\n\n	print_debug_\
message( 'load_params', 'End', 1 );\n}\n\n=head2 c\
lient_poll()\n\nClient-side job polling.\n\n  &cli\
ent_poll($job_id);\n\n=cut\n\nsub client_poll {\n	\
print_debug_message( 'client_poll', 'Begin', 1 );\\
n	my $jobid  = shift;\n	my $status = 'PENDING';\n\\
n	my $errorCount = 0;\n	while ($status eq 'RUNNING\
'\n		|| $status eq 'PENDING'\n		|| ( $status eq 'E\
RROR' && $errorCount < 2 ) )\n	{\n		$status = rest\
_get_status($jobid);\n		print STDERR \"$status\\n\\
" if ( $outputLevel > 0 );\n		if ( $status eq 'ERR\
OR' ) {\n			$errorCount++;\n		}\n		elsif ( $errorC\
ount > 0 ) {\n			$errorCount--;\n		}\n		if (   $st\
atus eq 'RUNNING'\n			|| $status eq 'PENDING'\n			\
|| $status eq 'ERROR' )\n		{\n\n			# Wait before p\
olling again.\n			sleep $checkInterval;\n		}\n	}\n\
	print_debug_message( 'client_poll', 'End', 1 );\n\
	return $status;\n}\n\n=head2 get_results()\n\nGet\
 the results for a job identifier.\n\n  &get_resul\
ts($job_id);\n\n=cut\n\nsub get_results {\n	print_\
debug_message( 'get_results', 'Begin', 1 );\n	my $\
jobid = shift;\n	print_debug_message( 'get_results\
', 'jobid: ' . $jobid, 1 );\n\n	# Verbose\n	if ( $\
outputLevel > 1 ) {\n		print 'Getting results for \
job ', $jobid, \"\\n\";\n	}\n\n	# Check status, an\
d wait if not finished\n	client_poll($jobid);\n\n	\
# Use JobId if output file name is not defined\n	u\
nless ( defined( $params{'outfile'} ) ) {\n		$para\
ms{'outfile'} = $jobid;\n	}\n\n	# Get list of data\
 types\n	my (@resultTypes) = rest_get_result_types\
($jobid);\n\n	# Get the data and write it to a fil\
e\n	if ( defined( $params{'outformat'} ) ) {    # \
Specified data type\n		my $selResultType;\n		forea\
ch my $resultType (@resultTypes) {\n			if ( $resul\
tType->{'identifier'} eq $params{'outformat'} ) {\\
n				$selResultType = $resultType;\n			}\n		}\n		i\
f ( defined($selResultType) ) {\n			my $result =\n\
			  rest_get_result( $jobid, $selResultType->{'id\
entifier'} );\n			if ( $params{'outfile'} eq '-' )\
 {\n				write_file( $params{'outfile'}, $result );\
\n			}\n			else {\n				write_file(\n					$params{'\
outfile'} . '.'\n					  . $selResultType->{'identi\
fier'} . '.'\n					  . $selResultType->{'fileSuffi\
x'},\n					$result\n				);\n			}\n		}\n		else {\n	\
		die 'Error: unknown result format \"' . $params{\
'outformat'} . '\"';\n		}\n	}\n	else {    # Data t\
ypes available\n		      # Write a file for each ou\
tput type\n		for my $resultType (@resultTypes) {\n\
			if ( $outputLevel > 1 ) {\n				print STDERR 'Ge\
tting ', $resultType->{'identifier'}, \"\\n\";\n		\
	}\n			my $result = rest_get_result( $jobid, $resu\
ltType->{'identifier'} );\n			if ( $params{'outfil\
e'} eq '-' ) {\n				write_file( $params{'outfile'}\
, $result );\n			}\n			else {\n				write_file(\n		\
			$params{'outfile'} . '.'\n					  . $resultType-\
>{'identifier'} . '.'\n					  . $resultType->{'fil\
eSuffix'},\n					$result\n				);\n			}\n		}\n	}\n	\
print_debug_message( 'get_results', 'End', 1 );\n}\
\n\n=head2 read_file()\n\nRead a file into a scala\
r. The special filename '-' can be used to read fr\
om \nstandard input (STDIN).\n\n  my $data = &read\
_file($filename);\n\n=cut\n\nsub read_file {\n	pri\
nt_debug_message( 'read_file', 'Begin', 1 );\n	my \
$filename = shift;\n	print_debug_message( 'read_fi\
le', 'filename: ' . $filename, 2 );\n	my ( $conten\
t, $buffer );\n	if ( $filename eq '-' ) {\n		while\
 ( sysread( STDIN, $buffer, 1024 ) ) {\n			$conten\
t .= $buffer;\n		}\n	}\n	else {    # File\n		open(\
 my $FILE, '<', $filename )\n		  or die \"Error: u\
nable to open input file $filename ($!)\";\n		whil\
e ( sysread( $FILE, $buffer, 1024 ) ) {\n			$conte\
nt .= $buffer;\n		}\n		close($FILE);\n	}\n	print_d\
ebug_message( 'read_file', 'End', 1 );\n	return $c\
ontent;\n}\n\n=head2 write_file()\n\nWrite data to\
 a file. The special filename '-' can be used to w\
rite to \nstandard output (STDOUT).\n\n  &write_fi\
le($filename, $data);\n\n=cut\n\nsub write_file {\\
n	print_debug_message( 'write_file', 'Begin', 1 );\
\n	my ( $filename, $data ) = @_;\n	print_debug_mes\
sage( 'write_file', 'filename: ' . $filename, 2 );\
\n	if ( $outputLevel > 0 ) {\n		print STDERR 'Crea\
ting result file: ' . $filename . \"\\n\";\n	}\n	i\
f ( $filename eq '-' ) {\n		print STDOUT $data;\n	\
}\n	else {\n		open( my $FILE, '>', $filename )\n		\
  or die \"Error: unable to open output file $file\
name ($!)\";\n		syswrite( $FILE, $data );\n		close\
($FILE);\n	}\n	print_debug_message( 'write_file', \
'End', 1 );\n}\n\n=head2 usage()\n\nPrint program \
usage message.\n\n  &usage();\n\n=cut\n\nsub usage\
 {\n	print STDERR <<EOF\nNCBI BLAST\n==========\n \
  \nRapid sequence database search programs utiliz\
ing the BLAST algorithm\n    \n[Required]\n\n  -p,\
 --program      : str  : BLAST program to use, see\
 --paramDetail program\n  -D, --database     : str\
  : database(s) to search, space separated. See\n \
                             --paramDetail databas\
e\n      --stype        : str  : query sequence ty\
pe, see --paramDetail stype\n  seqFile            \
: file : query sequence (\"-\" for STDIN, \\@filen\
ame for\n                              identifier \
list file)\n\n[Optional]\n\n  -m, --matrix       :\
 str  : scoring matrix, see --paramDetail matrix\n\
  -e, --exp          : real : 0<E<= 1000. Statisti\
cal significance threshold \n                     \
         for reporting database sequence matches.\\
n  -f, --filter       :      : filter the query se\
quence for low complexity \n                      \
        regions, see --paramDetail filter\n  -A, -\
-align        : int  : pairwise alignment format, \
see --paramDetail align\n  -s, --scores       : in\
t  : number of scores to be reported\n  -n, --alig\
nments   : int  : number of alignments to report\n\
  -u, --match        : int  : Match score (BLASTN \
only)\n  -v, --mismatch     : int  : Mismatch scor\
e (BLASTN only)\n  -o, --gapopen      : int  : Gap\
 open penalty\n  -x, --gapext       : int  : Gap e\
xtension penalty\n  -d, --dropoff      : int  : Dr\
op-off\n  -g, --gapalign     :      : Optimise gap\
ped alignments\n      --seqrange     : str  : regi\
on within input to use as query\n      --multifast\
a   :      : treat input as a set of fasta formatt\
ed sequences\n\n[General]\n\n  -h, --help         \
:      : prints this help text\n      --async     \
   :      : forces to make an asynchronous query\n\
      --email        : str  : e-mail address\n    \
  --title        : str  : title for job\n      --s\
tatus       :      : get job status\n      --resul\
tTypes  :      : get available result types for jo\
b\n      --polljob      :      : poll for the stat\
us of a job\n      --jobid        : str  : jobid t\
hat was returned when an asynchronous job \n      \
                        was submitted.\n      --ou\
tfile      : str  : file name for results (default\
 is jobid;\n                              \"-\" fo\
r STDOUT)\n      --outformat    : str  : result fo\
rmat to retrieve\n      --params       :      : li\
st input parameters\n      --paramDetail  : str  :\
 display details for input parameter\n      --quie\
t        :      : decrease output\n      --verbose\
      :      : increase output\n   \nSynchronous j\
ob:\n\n  The results/errors are returned as soon a\
s the job is finished.\n  Usage: $scriptName --ema\
il <your\\@email> [options...] seqFile\n  Returns:\
 results as an attachment\n\nAsynchronous job:\n\n\
  Use this if you want to retrieve the results at \
a later time. The results \n  are stored for up to\
 24 hours. 	\n  Usage: $scriptName --async --email\
 <your\\@email> [options...] seqFile\n  Returns: j\
obid\n\n  Use the jobid to query for the status of\
 the job. If the job is finished, \n  it also retu\
rns the results/errors.\n  Usage: $scriptName --po\
lljob --jobid <jobId> [--outfile string]\n  Return\
s: string indicating the status of the job and if \
applicable, results \n  as an attachment.\n\nFurth\
er information:\n\n  http://www.ebi.ac.uk/Tools/we\
bservices/services/sss/ncbi_blast_rest\n  http://w\
ww.ebi.ac.uk/Tools/webservices/tutorials/perl\n\nS\
upport/Feedback:\n\n  http://www.ebi.ac.uk/support\
/\nEOF\n}\n\n=head1 FEEDBACK/SUPPORT\n\nPlease con\
tact us at L<http://www.ebi.ac.uk/support/> if you\
 have any \nfeedback, suggestions or issues with t\
he service or this client.\n\n=cut\n","\n=head1 NA\
ME\n\nwublast_lwp.pl\n\n=head1 DESCRIPTION\n\nWU-B\
LAST (REST) web service Perl client using L<LWP>.\\
n\nTested with:\n\n=over\n\n=item *\nL<LWP> 5.79, \
L<XML::Simple> 2.12 and Perl 5.8.3\n\n=item *\nL<L\
WP> 5.808, L<XML::Simple> 2.18 and Perl 5.8.8 (Ubu\
ntu 8.04 LTS)\n\n=item *\nL<LWP> 5.834, L<XML::Sim\
ple> 2.18 and Perl 5.10.1 (Ubuntu 10.04 LTS)\n\n=i\
tem *\nL<LWP> 6.03, L<XML::Simple> 2.18 and Perl 5\
.14.2 (Ubuntu 12.04 LTS)\n\n=back\n\nFor further i\
nformation see:\n\n=over\n\n=item *\nL<http://www.\
ebi.ac.uk/Tools/webservices/services/sss/wu_blast_\
rest>\n\n=item *\nL<http://www.ebi.ac.uk/Tools/web\
services/tutorials/perl>\n\n=back\n\n=head1 LICENS\
E\n\nCopyright 2012-2013 EMBL - European Bioinform\
atics Institute\n\nLicensed under the Apache Licen\
se, Version 2.0 (the \"License\");\nyou may not us\
e this file except in compliance with the License.\
\nYou may obtain a copy of the License at\n\n    h\
ttp://www.apache.org/licenses/LICENSE-2.0\n\nUnles\
s required by applicable law or agreed to in writi\
ng, software\ndistributed under the License is dis\
tributed on an \"AS IS\" BASIS,\nWITHOUT WARRANTIE\
S OR CONDITIONS OF ANY KIND, either express or imp\
lied.\nSee the License for the specific language g\
overning permissions and\nlimitations under the Li\
cense.\n\n=head1 VERSION\n\n$Id: wublast_lwp.pl 25\
60 2013-03-20 12:56:31Z hpm $\n\n=cut\n\nuse stric\
t;\nuse warnings;\n\nuse English;\nuse LWP;\nuse X\
ML::Simple;\nuse Getopt::Long qw(:config no_ignore\
_case bundling);\nuse File::Basename;\nuse Data::D\
umper;\n\nmy $baseUrl = 'http://www.ebi.ac.uk/Tool\
s/services/rest/wublast';\n\nmy $checkInterval = 3\
;\n\nmy $outputLevel = 1;\n\nmy $numOpts = scalar(\
@ARGV);\nmy %params = ( 'debugLevel' => 0 );\n\nmy\
 %tool_params = ();\nGetOptions(\n\n	# Tool specif\
ic options\n	'program|p=s'     => \\$tool_params{'\
program'},      # BLAST program\n	'database|D=s'  \
  => \\$params{'database'},     # Search database\\
n	'matrix|m=s'      => \\$tool_params{'matrix'},  \
     # Scoring matrix\n	'exp|E=f'         => \\$to\
ol_params{'exp'},          # E-value threshold\n	'\
viewfilter|e'    => \\$tool_params{'viewfilter'}, \
  # Display filtered sequence\n	'filter|f=s'      \
=> \\$tool_params{'filter'},       # Low complexit\
y filter name\n	'alignments|n=i'  => \\$tool_param\
s{'alignments'},   # Number of alignments\n	'score\
s|s=i'      => \\$tool_params{'scores'},       # N\
umber of scores\n	'sensitivity|S=s' => \\$tool_par\
ams{'sensitivity'},  # Search sensitivity\n	'sort|\
t=s'        => \\$tool_params{'sort'},         # S\
ort hits by...\n	'stats|T=s'       => \\$tool_para\
ms{'stats'},        # Scoring statistic to use\n	'\
strand|d=s'      => \\$tool_params{'strand'},     \
  # Strand to use\n	'topcombon|c=i'   => \\$tool_p\
arams{'topcombon'},    # Consistent sets of HSPs\n\
	'align|A=i'       => \\$tool_params{'align'},   #\
 Pairwise alignment format\n	'stype=s' => \\$tool_\
params{'stype'},    # Sequence type 'protein' or '\
dna'\n	'sequence=s' => \\$params{'sequence'},     \
    # Query sequence file or DB:ID\n	'multifasta' \
=> \\$params{'multifasta'},       # Multiple fasta\
 input\n\n	# Compatability options, old command-li\
ne.\n	'echofilter|e'    => \\$params{'echofilter'}\
,   # Display filtered sequence\n	'b=i'  => \\$par\
ams{'numal'},        # Number of alignments\n	'app\
xml=s'        => \\$params{'appxml'},       # Appl\
ication XML\n\n	# Generic options\n	'email=s'     \
  => \\$params{'email'},          # User e-mail ad\
dress\n	'title=s'       => \\$params{'title'},    \
      # Job title\n	'outfile=s'     => \\$params{'\
outfile'},        # Output file name\n	'outformat=\
s'   => \\$params{'outformat'},      # Output file\
 type\n	'jobid=s'       => \\$params{'jobid'},    \
      # JobId\n	'help|h'        => \\$params{'help\
'},           # Usage help\n	'async'         => \\\
$params{'async'},          # Asynchronous submissi\
on\n	'polljob'       => \\$params{'polljob'},     \
   # Get results\n	'resultTypes'   => \\$params{'r\
esultTypes'},    # Get result types\n	'status'    \
    => \\$params{'status'},         # Get status\n\
	'params'        => \\$params{'params'},         #\
 List input parameters\n	'paramDetail=s' => \\$par\
ams{'paramDetail'},    # Get details for parameter\
\n	'quiet'         => \\$params{'quiet'},         \
 # Decrease output level\n	'verbose'       => \\$p\
arams{'verbose'},        # Increase output level\n\
	'debugLevel=i'  => \\$params{'debugLevel'},     #\
 Debug output level\n	'baseUrl=s'     => \\$baseUr\
l,                  # Base URL for service.\n);\ni\
f ( $params{'verbose'} ) { $outputLevel++ }\nif ( \
$params{'quiet'} )  { $outputLevel-- }\n\n&print_d\
ebug_message( 'MAIN', 'LWP::VERSION: ' . $LWP::VER\
SION,\n	1 );\n\n&print_debug_message( 'MAIN', \"pa\
rams:\\n\" . Dumper( \\%params ),           11 );\\
n&print_debug_message( 'MAIN', \"tool_params:\\n\"\
 . Dumper( \\%tool_params ), 11 );\n\nmy $ua;\n\nm\
y $scriptName = basename( $0, () );\n\nif ( $param\
s{'help'} || $numOpts == 0 ) {\n	&usage();\n	exit(\
0);\n}\n\n&print_debug_message( 'MAIN', 'baseUrl: \
' . $baseUrl, 1 );\n\nif (\n	!(\n		   $params{'pol\
ljob'}\n		|| $params{'resultTypes'}\n		|| $params{\
'status'}\n		|| $params{'params'}\n		|| $params{'p\
aramDetail'}\n	)\n	&& !( defined( $ARGV[0] ) || de\
fined( $params{'sequence'} ) )\n  )\n{\n\n	# Bad a\
rgument combination, so print error message and us\
age\n	print STDERR 'Error: bad option combination'\
, \"\\n\";\n	&usage();\n	exit(1);\n}\n\nelsif ( $p\
arams{'params'} ) {\n	&print_tool_params();\n}\n\n\
elsif ( $params{'paramDetail'} ) {\n	&print_param_\
details( $params{'paramDetail'} );\n}\n\nelsif ( $\
params{'status'} && defined( $params{'jobid'} ) ) \
{\n	&print_job_status( $params{'jobid'} );\n}\n\ne\
lsif ( $params{'resultTypes'} && defined( $params{\
'jobid'} ) ) {\n	&print_result_types( $params{'job\
id'} );\n}\n\nelsif ( $params{'polljob'} && define\
d( $params{'jobid'} ) ) {\n	&get_results( $params{\
'jobid'} );\n}\n\nelse {\n\n	# Multiple input sequ\
ence mode, assume fasta format.\n	if ( $params{'mu\
ltifasta'} ) {\n		&multi_submit_job();\n	}\n\n	# E\
ntry identifier list file.\n	elsif (( defined( $pa\
rams{'sequence'} ) && $params{'sequence'} =~ m/^\\\
@/ )\n		|| ( defined( $ARGV[0] ) && $ARGV[0] =~ m/\
^\\@/ ) )\n	{\n		my $list_filename = $params{'sequ\
ence'} || $ARGV[0];\n		$list_filename =~ s/^\\@//;\
\n		&list_file_submit_job($list_filename);\n	}\n\n\
	# Default: single sequence/identifier.\n	else {\n\
\n		# Load the sequence data and submit.\n		&submi\
t_job( &load_data() );\n	}\n}\n\n=head1 FUNCTIONS\\
n\n=cut\n\n\n=head2 rest_user_agent()\n\nGet a LWP\
 UserAgent to use to perform REST requests.\n\n  m\
y $ua = &rest_user_agent();\n\n=cut\n\nsub rest_us\
er_agent() {\n	print_debug_message( 'rest_user_age\
nt', 'Begin', 21 );\n	# Create an LWP UserAgent fo\
r making HTTP calls.\n	my $ua = LWP::UserAgent->ne\
w();\n	# Set 'User-Agent' HTTP header to identifiy\
 the client.\n	'$Revision: 2560 $' =~ m/(\\d+)/;\n\
	$ua->agent(\"EBI-Sample-Client/$1 ($scriptName; $\
OSNAME) \" . $ua->agent());\n	# Configure HTTP pro\
xy support from environment.\n	$ua->env_proxy;\n	p\
rint_debug_message( 'rest_user_agent', 'End', 21 )\
;\n	return $ua;\n}\n\n=head2 rest_error()\n\nCheck\
 a REST response for an error condition. An error \
is mapped to a die.\n\n  &rest_error($response, $c\
ontent_data);\n\n=cut\n\nsub rest_error() {\n	prin\
t_debug_message( 'rest_error', 'Begin', 21 );\n	my\
 $response = shift;\n	my $contentdata;\n	if(scalar\
(@_) > 0) {\n		$contentdata = shift;\n	}\n	if(!def\
ined($contentdata) || $contentdata eq '') {\n		$co\
ntentdata = $response->content();\n	}\n	# Check fo\
r HTTP error codes\n	if ( $response->is_error ) {\\
n		my $error_message = '';\n		# HTML response.\n		\
if(	$contentdata =~ m/<h1>([^<]+)<\\/h1>/ ) {\n			\
$error_message = $1;\n		}\n		#  XML response.\n		e\
lsif($contentdata =~ m/<description>([^<]+)<\\/des\
cription>/) {\n			$error_message = $1;\n		}\n		die\
 'http status: ' . $response->code . ' ' . $respon\
se->message . '  ' . $error_message;\n	}\n	print_d\
ebug_message( 'rest_error', 'End', 21 );\n}\n\n=he\
ad2 rest_request()\n\nPerform a REST request (HTTP\
 GET).\n\n  my $response_str = &rest_request($url)\
;\n\n=cut\n\nsub rest_request {\n	print_debug_mess\
age( 'rest_request', 'Begin', 11 );\n	my $requestU\
rl = shift;\n	print_debug_message( 'rest_request',\
 'URL: ' . $requestUrl, 11 );\n\n	# Get an LWP Use\
rAgent.\n	$ua = &rest_user_agent() unless defined(\
$ua);\n	# Available HTTP compression methods.\n	my\
 $can_accept;\n	eval {\n	    $can_accept = HTTP::M\
essage::decodable();\n	};\n	$can_accept = '' unles\
s defined($can_accept);\n	# Perform the request\n	\
my $response = $ua->get($requestUrl,\n		'Accept-En\
coding' => $can_accept, # HTTP compression.\n	);\n\
	print_debug_message( 'rest_request', 'HTTP status\
: ' . $response->code,\n		11 );\n	print_debug_mess\
age( 'rest_request',\n		'response length: ' . leng\
th($response->content()), 11 );\n	print_debug_mess\
age( 'rest_request',\n		'request:' .\"\\n\" . $res\
ponse->request()->as_string(), 32 );\n	print_debug\
_message( 'rest_request',\n		'response: ' . \"\\n\\
" . $response->as_string(), 32 );\n	# Unpack possi\
bly compressed response.\n	my $retVal;\n	if ( defi\
ned($can_accept) && $can_accept ne '') {\n	    $re\
tVal = $response->decoded_content();\n	}\n	# If un\
able to decode use orginal content.\n	$retVal = $r\
esponse->content() unless defined($retVal);\n	# Ch\
eck for an error.\n	&rest_error($response, $retVal\
);\n	print_debug_message( 'rest_request', 'retVal:\
 ' . $retVal, 12 );\n	print_debug_message( 'rest_r\
equest', 'End', 11 );\n\n	# Return the response da\
ta\n	return $retVal;\n}\n\n=head2 rest_get_paramet\
ers()\n\nGet list of tool parameter names.\n\n  my\
 (@param_list) = &rest_get_parameters();\n\n=cut\n\
\nsub rest_get_parameters {\n	print_debug_message(\
 'rest_get_parameters', 'Begin', 1 );\n	my $url   \
             = $baseUrl . '/parameters/';\n	my $pa\
ram_list_xml_str = rest_request($url);\n	my $param\
_list_xml     = XMLin($param_list_xml_str);\n	my (\
@param_list)       = @{ $param_list_xml->{'id'} };\
\n	print_debug_message( 'rest_get_parameters', 'En\
d', 1 );\n	return (@param_list);\n}\n\n=head2 rest\
_get_parameter_details()\n\nGet details of a tool \
parameter.\n\n  my $paramDetail = &rest_get_parame\
ter_details($param_name);\n\n=cut\n\nsub rest_get_\
parameter_details {\n	print_debug_message( 'rest_g\
et_parameter_details', 'Begin', 1 );\n	my $paramet\
erId = shift;\n	print_debug_message( 'rest_get_par\
ameter_details',\n		'parameterId: ' . $parameterId\
, 1 );\n	my $url                  = $baseUrl . '/p\
arameterdetails/' . $parameterId;\n	my $param_deta\
il_xml_str = rest_request($url);\n	my $param_detai\
l_xml     = XMLin($param_detail_xml_str);\n	print_\
debug_message( 'rest_get_parameter_details', 'End'\
, 1 );\n	return ($param_detail_xml);\n}\n\n=head2 \
rest_run()\n\nSubmit a job.\n\n  my $job_id = &res\
t_run($email, $title, \\%params );\n\n=cut\n\nsub \
rest_run {\n	print_debug_message( 'rest_run', 'Beg\
in', 1 );\n	my $email  = shift;\n	my $title  = shi\
ft;\n	my $params = shift;\n	print_debug_message( '\
rest_run', 'email: ' . $email, 1 );\n	if ( defined\
($title) ) {\n		print_debug_message( 'rest_run', '\
title: ' . $title, 1 );\n	}\n	print_debug_message(\
 'rest_run', 'params: ' . Dumper($params), 1 );\n\\
n	# Get an LWP UserAgent.\n	$ua = &rest_user_agent\
() unless defined($ua);\n\n	# Clean up parameters\\
n	my (%tmp_params) = %{$params};\n	$tmp_params{'em\
ail'} = $email;\n	$tmp_params{'title'} = $title;\n\
	foreach my $param_name ( keys(%tmp_params) ) {\n	\
	if ( !defined( $tmp_params{$param_name} ) ) {\n		\
	delete $tmp_params{$param_name};\n		}\n	}\n\n	# S\
ubmit the job as a POST\n	my $url = $baseUrl . '/r\
un';\n	my $response = $ua->post( $url, \\%tmp_para\
ms );\n	print_debug_message( 'rest_run', 'HTTP sta\
tus: ' . $response->code, 11 );\n	print_debug_mess\
age( 'rest_run',\n		'request:' .\"\\n\" . $respons\
e->request()->as_string(), 11 );\n	print_debug_mes\
sage( 'rest_run',\n		'response: ' . length($respon\
se->as_string()) . \"\\n\" . $response->as_string(\
), 11 );\n\n	# Check for an error.\n	&rest_error($\
response);\n\n	# The job id is returned\n	my $job_\
id = $response->content();\n	print_debug_message( \
'rest_run', 'End', 1 );\n	return $job_id;\n}\n\n=h\
ead2 rest_get_status()\n\nCheck the status of a jo\
b.\n\n  my $status = &rest_get_status($job_id);\n\\
n=cut\n\nsub rest_get_status {\n	print_debug_messa\
ge( 'rest_get_status', 'Begin', 1 );\n	my $job_id \
= shift;\n	print_debug_message( 'rest_get_status',\
 'jobid: ' . $job_id, 2 );\n	my $status_str = 'UNK\
NOWN';\n	my $url        = $baseUrl . '/status/' . \
$job_id;\n	$status_str = &rest_request($url);\n	pr\
int_debug_message( 'rest_get_status', 'status_str:\
 ' . $status_str, 2 );\n	print_debug_message( 'res\
t_get_status', 'End', 1 );\n	return $status_str;\n\
}\n\n=head2 rest_get_result_types()\n\nGet list of\
 result types for finished job.\n\n  my (@result_t\
ypes) = &rest_get_result_types($job_id);\n\n=cut\n\
\nsub rest_get_result_types {\n	print_debug_messag\
e( 'rest_get_result_types', 'Begin', 1 );\n	my $jo\
b_id = shift;\n	print_debug_message( 'rest_get_res\
ult_types', 'jobid: ' . $job_id, 2 );\n	my (@resul\
tTypes);\n	my $url                      = $baseUrl\
 . '/resulttypes/' . $job_id;\n	my $result_type_li\
st_xml_str = &rest_request($url);\n	my $result_typ\
e_list_xml     = XMLin($result_type_list_xml_str);\
\n	(@resultTypes) = @{ $result_type_list_xml->{'ty\
pe'} };\n	print_debug_message( 'rest_get_result_ty\
pes',\n		scalar(@resultTypes) . ' result types', 2\
 );\n	print_debug_message( 'rest_get_result_types'\
, 'End', 1 );\n	return (@resultTypes);\n}\n\n=head\
2 rest_get_result()\n\nGet result data of a specif\
ied type for a finished job.\n\n  my $result = res\
t_get_result($job_id, $result_type);\n\n=cut\n\nsu\
b rest_get_result {\n	print_debug_message( 'rest_g\
et_result', 'Begin', 1 );\n	my $job_id = shift;\n	\
my $type   = shift;\n	print_debug_message( 'rest_g\
et_result', 'jobid: ' . $job_id, 1 );\n	print_debu\
g_message( 'rest_get_result', 'type: ' . $type,   \
 1 );\n	my $url    = $baseUrl . '/result/' . $job_\
id . '/' . $type;\n	my $result = &rest_request($ur\
l);\n	print_debug_message( 'rest_get_result', leng\
th($result) . ' characters',\n		1 );\n	print_debug\
_message( 'rest_get_result', 'End', 1 );\n	return \
$result;\n}\n\n\n=head2 print_debug_message()\n\nP\
rint debug message at specified debug level.\n\n  \
&print_debug_message($method_name, $message, $leve\
l);\n\n=cut\n\nsub print_debug_message {\n	my $fun\
ction_name = shift;\n	my $message       = shift;\n\
	my $level         = shift;\n	if ( $level <= $para\
ms{'debugLevel'} ) {\n		print STDERR '[', $functio\
n_name, '()] ', $message, \"\\n\";\n	}\n}\n\n=head\
2 print_tool_params()\n\nPrint list of tool parame\
ters.\n\n  &print_tool_params();\n\n=cut\n\nsub pr\
int_tool_params {\n	print_debug_message( 'print_to\
ol_params', 'Begin', 1 );\n	my (@param_list) = &re\
st_get_parameters();\n	foreach my $param ( sort(@p\
aram_list) ) {\n		print $param, \"\\n\";\n	}\n	pri\
nt_debug_message( 'print_tool_params', 'End', 1 );\
\n}\n\n=head2 print_param_details()\n\nPrint detai\
ls of a tool parameter.\n\n  &print_param_details(\
$param_name);\n\n=cut\n\nsub print_param_details {\
\n	print_debug_message( 'print_param_details', 'Be\
gin', 1 );\n	my $paramName = shift;\n	print_debug_\
message( 'print_param_details', 'paramName: ' . $p\
aramName, 2 );\n	my $paramDetail = &rest_get_param\
eter_details($paramName);\n	print $paramDetail->{'\
name'}, \"\\t\", $paramDetail->{'type'}, \"\\n\";\\
n	print $paramDetail->{'description'}, \"\\n\";\n	\
if(defined($paramDetail->{'values'}->{'value'})) {\
\n		if(ref($paramDetail->{'values'}->{'value'}) eq\
 'ARRAY') {\n			foreach my $value ( @{ $paramDetai\
l->{'values'}->{'value'} } ) {\n				&print_param_v\
alue($value);\n			}\n		}\n		else {\n				&print_par\
am_value($paramDetail->{'values'}->{'value'});\n		\
}\n	}\n	print_debug_message( 'print_param_details'\
, 'End', 1 );\n}\n\n=head2 print_param_value()\n\n\
Print details of a tool parameter value.\n\n  &pri\
nt_param_details($param_value);\n\nUsed by print_p\
aram_details() to handle both singluar and array v\
alues.\n\n=cut\n\nsub print_param_value {\n	my $va\
lue = shift;\n	print $value->{'value'};\n	if ( $va\
lue->{'defaultValue'} eq 'true' ) {\n		print \"\\t\
\", 'default';\n	}\n	print \"\\n\";\n	print \"\\t\\
", $value->{'label'}, \"\\n\";\n	if ( defined( $va\
lue->{'properties'} ) ) {\n		foreach\n		  my $key \
( sort( keys( %{ $value->{'properties'}{'property'\
} } ) ) )\n		{\n			if ( ref( $value->{'properties'\
}{'property'}{$key} ) eq 'HASH'\n				&& defined( $\
value->{'properties'}{'property'}{$key}{'value'} )\
\n			  )\n			{\n				print \"\\t\", $key, \"\\t\",\\
n				  $value->{'properties'}{'property'}{$key}{'v\
alue'}, \"\\n\";\n			}\n			else {\n				print \"\\t\
\", $value->{'properties'}{'property'}{'key'},\n		\
		  \"\\t\", $value->{'properties'}{'property'}{'v\
alue'}, \"\\n\";\n				last;\n			}\n		}\n	}\n}\n\n=\
head2 print_job_status()\n\nPrint status of a job.\
\n\n  &print_job_status($job_id);\n\n=cut\n\nsub p\
rint_job_status {\n	print_debug_message( 'print_jo\
b_status', 'Begin', 1 );\n	my $jobid = shift;\n	pr\
int_debug_message( 'print_job_status', 'jobid: ' .\
 $jobid, 1 );\n	if ( $outputLevel > 0 ) {\n		print\
 STDERR 'Getting status for job ', $jobid, \"\\n\"\
;\n	}\n	my $result = &rest_get_status($jobid);\n	p\
rint \"$result\\n\";\n	if ( $result eq 'FINISHED' \
&& $outputLevel > 0 ) {\n		print STDERR \"To get r\
esults: $scriptName --polljob --jobid \" . $jobid\\
n		  . \"\\n\";\n	}\n	print_debug_message( 'print_\
job_status', 'End', 1 );\n}\n\n=head2 print_result\
_types()\n\nPrint available result types for a job\
.\n\n  &print_result_types($job_id);\n\n=cut\n\nsu\
b print_result_types {\n	print_debug_message( 'res\
ult_types', 'Begin', 1 );\n	my $jobid = shift;\n	p\
rint_debug_message( 'result_types', 'jobid: ' . $j\
obid, 1 );\n	if ( $outputLevel > 0 ) {\n		print ST\
DERR 'Getting result types for job ', $jobid, \"\\\
n\";\n	}\n	my $status = &rest_get_status($jobid);\\
n	if ( $status eq 'PENDING' || $status eq 'RUNNING\
' ) {\n		print STDERR 'Error: Job status is ', $st\
atus,\n		  '. To get result types the job must be \
finished.', \"\\n\";\n	}\n	else {\n		my (@resultTy\
pes) = &rest_get_result_types($jobid);\n		if ( $ou\
tputLevel > 0 ) {\n			print STDOUT 'Available resu\
lt types:', \"\\n\";\n		}\n		foreach my $resultTyp\
e (@resultTypes) {\n			print STDOUT $resultType->{\
'identifier'}, \"\\n\";\n			if ( defined( $resultT\
ype->{'label'} ) ) {\n				print STDOUT \"\\t\", $r\
esultType->{'label'}, \"\\n\";\n			}\n			if ( defi\
ned( $resultType->{'description'} ) ) {\n				print\
 STDOUT \"\\t\", $resultType->{'description'}, \"\\
\n\";\n			}\n			if ( defined( $resultType->{'media\
Type'} ) ) {\n				print STDOUT \"\\t\", $resultTyp\
e->{'mediaType'}, \"\\n\";\n			}\n			if ( defined(\
 $resultType->{'fileSuffix'} ) ) {\n				print STDO\
UT \"\\t\", $resultType->{'fileSuffix'}, \"\\n\";\\
n			}\n		}\n		if ( $status eq 'FINISHED' && $outpu\
tLevel > 0 ) {\n			print STDERR \"\\n\", 'To get r\
esults:', \"\\n\",\n			  \"  $scriptName --polljob\
 --jobid \" . $params{'jobid'} . \"\\n\",\n			  \"\
  $scriptName --polljob --outformat <type> --jobid\
 \"\n			  . $params{'jobid'} . \"\\n\";\n		}\n	}\n\
	print_debug_message( 'result_types', 'End', 1 );\\
n}\n\n=head2 submit_job()\n\nSubmit a job to the s\
ervice.\n\n  &submit_job($seq);\n\n=cut\n\nsub sub\
mit_job {\n	print_debug_message( 'submit_job', 'Be\
gin', 1 );\n\n	# Set input sequence\n	$tool_params\
{'sequence'} = shift;\n\n	# Load parameters\n	&loa\
d_params();\n\n	# Submit the job\n	my $jobid = &re\
st_run( $params{'email'}, $params{'title'}, \\%too\
l_params );\n\n	# Simulate sync/async mode\n	if ( \
defined( $params{'async'} ) ) {\n		print STDOUT $j\
obid, \"\\n\";\n		if ( $outputLevel > 0 ) {\n			pr\
int STDERR\n			  \"To check status: $scriptName --\
status --jobid $jobid\\n\";\n		}\n	}\n	else {\n		i\
f ( $outputLevel > 0 ) {\n			print STDERR \"JobId:\
 $jobid\\n\";\n		}\n		sleep 1;\n		&get_results($jo\
bid);\n	}\n	print_debug_message( 'submit_job', 'En\
d', 1 );\n}\n\n=head2 multi_submit_job()\n\nSubmit\
 multiple jobs assuming input is a collection of f\
asta formatted sequences.\n\n  &multi_submit_job()\
;\n\n=cut\n\nsub multi_submit_job {\n	print_debug_\
message( 'multi_submit_job', 'Begin', 1 );\n	my $j\
obIdForFilename = 1;\n	$jobIdForFilename = 0 if ( \
defined( $params{'outfile'} ) );\n	my (@filename_l\
ist) = ();\n\n	# Query sequence\n	if ( defined( $A\
RGV[0] ) ) {    # Bare option\n		if ( -f $ARGV[0] \
|| $ARGV[0] eq '-' ) {    # File\n			push( @filena\
me_list, $ARGV[0] );\n		}\n		else {\n			warn 'Warn\
ing: Input file \"' . $ARGV[0] . '\" does not exis\
t'\n		}\n	}\n	if ( $params{'sequence'} ) {        \
           # Via --sequence\n		if ( -f $params{'se\
quence'} || $params{'sequence'} eq '-' ) {    # Fi\
le\n			push( @filename_list, $params{'sequence'} )\
;\n		}\n		else {\n			warn 'Warning: Input file \"'\
 . $params{'sequence'} . '\" does not exist'\n		}\\
n	}\n\n	$/ = '>';\n	foreach my $filename (@filenam\
e_list) {\n		my $INFILE;\n		if($filename eq '-') {\
 # STDIN.\n			open( $INFILE, '<-' )\n			  or die '\
Error: unable to STDIN (' . $! . ')';\n		} else { \
# File.\n			open( $INFILE, '<', $filename )\n			  \
or die 'Error: unable to open file ' . $filename .\
 ' (' . $! . ')';\n		}\n		while (<$INFILE>) {\n			\
my $seq = $_;\n			$seq =~ s/>$//;\n			if ( $seq =~\
 m/(\\S+)/ ) {\n				print STDERR \"Submitting job \
for: $1\\n\"\n				  if ( $outputLevel > 0 );\n				\
$seq = '>' . $seq;\n				&print_debug_message( 'mul\
ti_submit_job', $seq, 11 );\n				&submit_job($seq)\
;\n				$params{'outfile'} = undef if ( $jobIdForFi\
lename == 1 );\n			}\n		}\n		close $INFILE;\n	}\n	\
print_debug_message( 'multi_submit_job', 'End', 1 \
);\n}\n\n=head2 list_file_submit_job()\n\nSubmit m\
ultiple jobs using a file containing a list of ent\
ry identifiers as \ninput.\n\n  &list_file_submit_\
job($list_filename)\n\n=cut\n\nsub list_file_submi\
t_job {\n	print_debug_message( 'list_file_submit_j\
ob', 'Begin', 11 );\n	my $filename         = shift\
;\n	my $jobIdForFilename = 1;\n	$jobIdForFilename \
= 0 if ( defined( $params{'outfile'} ) );\n\n	# It\
erate over identifiers, submitting each job\n	my $\
LISTFILE;\n	if($filename eq '-') { # STDIN.\n		ope\
n( $LISTFILE, '<-' )\n		  or die 'Error: unable to\
 STDIN (' . $! . ')';\n	} else { # File.\n		open( \
$LISTFILE, '<', $filename )\n		  or die 'Error: un\
able to open file ' . $filename . ' (' . $! . ')';\
\n	}\n	while (<$LISTFILE>) {\n		my $line = $_;\n		\
chomp($line);\n		if ( $line ne '' ) {\n			&print_d\
ebug_message( 'list_file_submit_job', 'line: ' . $\
line, 2 );\n			if ( $line =~ m/\\w:\\w/ ) {    # C\
heck this is an identifier\n				print STDERR \"Sub\
mitting job for: $line\\n\"\n				  if ( $outputLev\
el > 0 );\n				&submit_job($line);\n			}\n			else \
{\n				print STDERR\n\"Warning: line \\\"$line\\\"\
 is not recognised as an identifier\\n\";\n			}\n	\
	}\n		$params{'outfile'} = undef if ( $jobIdForFil\
ename == 1 );\n	}\n	close $LISTFILE;\n	print_debug\
_message( 'list_file_submit_job', 'End', 11 );\n}\\
n\n=head2 load_data()\n\nLoad sequence data from f\
ile or option specified on the command-line.\n\n  \
&load_data();\n\n=cut\n\nsub load_data {\n	print_d\
ebug_message( 'load_data', 'Begin', 1 );\n	my $ret\
Seq;\n\n	# Query sequence\n	if ( defined( $ARGV[0]\
 ) ) {    # Bare option\n		if ( -f $ARGV[0] || $AR\
GV[0] eq '-' ) {    # File\n			$retSeq = &read_fil\
e( $ARGV[0] );\n		}\n		else {                     \
                # DB:ID or sequence\n			$retSeq = \
$ARGV[0];\n		}\n	}\n	if ( $params{'sequence'} ) { \
                  # Via --sequence\n		if ( -f $par\
ams{'sequence'} || $params{'sequence'} eq '-' ) { \
   # File\n			$retSeq = &read_file( $params{'seque\
nce'} );\n		}\n		else {    # DB:ID or sequence\n		\
	$retSeq = $params{'sequence'};\n		}\n	}\n	print_d\
ebug_message( 'load_data', 'End', 1 );\n	return $r\
etSeq;\n}\n\n=head2 load_params()\n\nLoad job para\
meters from command-line options.\n\n  &load_param\
s();\n\n=cut\n\nsub load_params {\n	print_debug_me\
ssage( 'load_params', 'Begin', 1 );\n\n	# Database\
(s) to search\n	my (@dbList) = split /[ ,]/, $para\
ms{'database'};\n	$tool_params{'database'} = \\@db\
List;\n\n	# Compatability options, old command-lin\
e.\n	if(!$tool_params{'viewfilter'} && $params{'ec\
hofilter'}) {\n		$tool_params{'viewfilter'} = 'tru\
e';\n	}\n	if(!$tool_params{'alignments'} && $param\
s{'numal'}) {\n		$tool_params{'alignments'} = $par\
ams{'numal'};\n	}\n	# TODO: set alignment format o\
ption to get NCBI BLAST XML.\n	if($params{'appxml'\
}) {\n		$tool_params{'align'} = '';\n	}\n\n	print_\
debug_message( 'load_params', 'End', 1 );\n}\n\n=h\
ead2 client_poll()\n\nClient-side job polling.\n\n\
  &client_poll($job_id);\n\n=cut\n\nsub client_pol\
l {\n	print_debug_message( 'client_poll', 'Begin',\
 1 );\n	my $jobid  = shift;\n	my $status = 'PENDIN\
G';\n\n	my $errorCount = 0;\n	while ($status eq 'R\
UNNING'\n		|| $status eq 'PENDING'\n		|| ( $status\
 eq 'ERROR' && $errorCount < 2 ) )\n	{\n		$status \
= rest_get_status($jobid);\n		print STDERR \"$stat\
us\\n\" if ( $outputLevel > 0 );\n		if ( $status e\
q 'ERROR' ) {\n			$errorCount++;\n		}\n		elsif ( $\
errorCount > 0 ) {\n			$errorCount--;\n		}\n		if (\
   $status eq 'RUNNING'\n			|| $status eq 'PENDING\
'\n			|| $status eq 'ERROR' )\n		{\n\n			# Wait be\
fore polling again.\n			sleep $checkInterval;\n		}\
\n	}\n	print_debug_message( 'client_poll', 'End', \
1 );\n	return $status;\n}\n\n=head2 get_results()\\
n\nGet the results for a job identifier.\n\n  &get\
_results($job_id);\n\n=cut\n\nsub get_results {\n	\
print_debug_message( 'get_results', 'Begin', 1 );\\
n	my $jobid = shift;\n	print_debug_message( 'get_r\
esults', 'jobid: ' . $jobid, 1 );\n\n	# Verbose\n	\
if ( $outputLevel > 1 ) {\n		print 'Getting result\
s for job ', $jobid, \"\\n\";\n	}\n\n	# Check stat\
us, and wait if not finished\n	client_poll($jobid)\
;\n\n	# Use JobId if output file name is not defin\
ed\n	unless ( defined( $params{'outfile'} ) ) {\n	\
	$params{'outfile'} = $jobid;\n	}\n\n	# Get list o\
f data types\n	my (@resultTypes) = rest_get_result\
_types($jobid);\n\n	# Get the data and write it to\
 a file\n	if ( defined( $params{'outformat'} ) ) {\
    # Specified data type\n		my $selResultType;\n	\
	foreach my $resultType (@resultTypes) {\n			if ( \
$resultType->{'identifier'} eq $params{'outformat'\
} ) {\n				$selResultType = $resultType;\n			}\n		\
}\n		if ( defined($selResultType) ) {\n			my $resu\
lt =\n			  rest_get_result( $jobid, $selResultType\
->{'identifier'} );\n			if ( $params{'outfile'} eq\
 '-' ) {\n				write_file( $params{'outfile'}, $res\
ult );\n			}\n			else {\n				write_file(\n					$pa\
rams{'outfile'} . '.'\n					  . $selResultType->{'\
identifier'} . '.'\n					  . $selResultType->{'fil\
eSuffix'},\n					$result\n				);\n			}\n		}\n		els\
e {\n			die 'Error: unknown result format \"' . $p\
arams{'outformat'} . '\"';\n		}\n	}\n	else {    # \
Data types available\n		      # Write a file for e\
ach output type\n		for my $resultType (@resultType\
s) {\n			if ( $outputLevel > 1 ) {\n				print STDE\
RR 'Getting ', $resultType->{'identifier'}, \"\\n\\
";\n			}\n			my $result = rest_get_result( $jobid,\
 $resultType->{'identifier'} );\n			if ( $params{'\
outfile'} eq '-' ) {\n				write_file( $params{'out\
file'}, $result );\n			}\n			else {\n				write_fil\
e(\n					$params{'outfile'} . '.'\n					  . $resul\
tType->{'identifier'} . '.'\n					  . $resultType-\
>{'fileSuffix'},\n					$result\n				);\n			}\n		}\\
n	}\n	print_debug_message( 'get_results', 'End', 1\
 );\n}\n\n=head2 read_file()\n\nRead a file into a\
 scalar. The special filename '-' can be used to r\
ead from \nstandard input (STDIN).\n\n  my $data =\
 &read_file($filename);\n\n=cut\n\nsub read_file {\
\n	print_debug_message( 'read_file', 'Begin', 1 );\
\n	my $filename = shift;\n	print_debug_message( 'r\
ead_file', 'filename: ' . $filename, 2 );\n	my ( $\
content, $buffer );\n	if ( $filename eq '-' ) {\n	\
	while ( sysread( STDIN, $buffer, 1024 ) ) {\n			$\
content .= $buffer;\n		}\n	}\n	else {    # File\n	\
	open( my $FILE, '<', $filename )\n		  or die \"Er\
ror: unable to open input file $filename ($!)\";\n\
		while ( sysread( $FILE, $buffer, 1024 ) ) {\n			\
$content .= $buffer;\n		}\n		close($FILE);\n	}\n	p\
rint_debug_message( 'read_file', 'End', 1 );\n	ret\
urn $content;\n}\n\n=head2 write_file()\n\nWrite d\
ata to a file. The special filename '-' can be use\
d to write to \nstandard output (STDOUT).\n\n  &wr\
ite_file($filename, $data);\n\n=cut\n\nsub write_f\
ile {\n	print_debug_message( 'write_file', 'Begin'\
, 1 );\n	my ( $filename, $data ) = @_;\n	print_deb\
ug_message( 'write_file', 'filename: ' . $filename\
, 2 );\n	if ( $outputLevel > 0 ) {\n		print STDERR\
 'Creating result file: ' . $filename . \"\\n\";\n\
	}\n	if ( $filename eq '-' ) {\n		print STDOUT $da\
ta;\n	}\n	else {\n		open( my $FILE, '>', $filename\
 )\n		  or die \"Error: unable to open output file\
 $filename ($!)\";\n		syswrite( $FILE, $data );\n	\
	close($FILE);\n	}\n	print_debug_message( 'write_f\
ile', 'End', 1 );\n}\n\n=head2 usage()\n\nPrint pr\
ogram usage message.\n\n  &usage();\n\n=cut\n\nsub\
 usage {\n	print STDERR <<EOF\nWU-BLAST\n========\\
n   \nRapid sequence database search programs util\
izing the BLAST algorithm\n    \n[Required]\n\n  -\
p, --program      : str  : BLAST program to use, s\
ee --paramDetail program\n  -D, --database     : s\
tr  : database(s) to search, space separated. See\\
n                              --paramDetail datab\
ase\n      --stype        : str  : query sequence \
type, see --paramDetail stype\n  seqFile          \
  : file : query sequence (\"-\" for STDIN, \\@fil\
ename for\n                              identifie\
r list file)\n\n[Optional]\n\n  -m, --matrix      \
 : str  : scoring matrix, see --paramDetail matrix\
\n  -e, --exp          : real : 0<E<= 1000. Statis\
tical significance threshold \n                   \
           for reporting database sequence matches\
.\n  -e, --viewfilter   :      : display the filte\
red query sequence\n  -f, --filter       : str  : \
filter the query sequence for low complexity \n   \
                           regions, see --paramDet\
ail filter\n  -A, --align        : int  : pairwise\
 alignment format, see --paramDetail align\n  -s, \
--scores       : int  : number of scores to be rep\
orted\n  -b, --alignments   : int  : number of ali\
gnments to report\n  -S, --sensitivity  : str  : s\
ensitivity of the search, \n                      \
        see --paramDetail sensitivity\n  -t, --sor\
t	     : str  : sort order for hits, see --paramDe\
tail sort\n  -T, --stats        : str  : statistic\
al model, see --paramDetail stats\n  -d, --strand \
      : str  : DNA strand to search with,\n       \
                       see --paramDetail strand\n \
 -c, --topcombon    : str  : consistent sets of HS\
Ps\n      --multifasta   :      : treat input as a\
 set of fasta formatted sequences\n\n[General]\n\n\
  -h, --help         :      : prints this help tex\
t\n      --async        :      : forces to make an\
 asynchronous query\n      --email        : str  :\
 e-mail address\n      --title        : str  : tit\
le for job\n      --status       :      : get job \
status\n      --resultTypes  :      : get availabl\
e result types for job\n      --polljob      :    \
  : poll for the status of a job\n      --jobid   \
     : str  : jobid that was returned when an asyn\
chronous job \n                              was s\
ubmitted.\n      --outfile      : str  : file name\
 for results (default is jobid;\n                 \
             \"-\" for STDOUT)\n      --outformat \
   : str  : result format to retrieve\n      --par\
ams       :      : list input parameters\n      --\
paramDetail  : str  : display details for input pa\
rameter\n      --quiet        :      : decrease ou\
tput\n      --verbose      :      : increase outpu\
t\n   \nSynchronous job:\n\n  The results/errors a\
re returned as soon as the job is finished.\n  Usa\
ge: $scriptName --email <your\\@email> [options...\
] seqFile\n  Returns: results as an attachment\n\n\
Asynchronous job:\n\n  Use this if you want to ret\
rieve the results at a later time. The results \n \
 are stored for up to 24 hours. 	\n  Usage: $scrip\
tName --async --email <your\\@email> [options...] \
seqFile\n  Returns: jobid\n\n  Use the jobid to qu\
ery for the status of the job. If the job is finis\
hed, \n  it also returns the results/errors.\n  Us\
age: $scriptName --polljob --jobid <jobId> [--outf\
ile string]\n  Returns: string indicating the stat\
us of the job and if applicable, results \n  as an\
 attachment.\n\nFurther information:\n\n  http://w\
ww.ebi.ac.uk/Tools/webservices/services/sss/wu_bla\
st_rest\n  http://www.ebi.ac.uk/Tools/webservices/\
tutorials/perl\n\nSupport/Feedback:\n\n  http://ww\
w.ebi.ac.uk/support/\nEOF\n}\n\n=head1 FEEDBACK/SU\
PPORT\n\nPlease contact us at L<http://www.ebi.ac.\
uk/support/> if you have any \nfeedback, suggestio\
ns or issues with the service or this client.\n\n=\
cut\n","\n\n\nmy $PROBTRESH = 0.3;# base pairs bel\
ow this prob threshold will be ignored\nmy $WEIGHT\
 = 100.0; # float!!\nmy $NUCALPH = \"ACGTUNRYMKSWH\
BVD\";\nuse vars qw($NUCALPH $WEIGHT);\n\nmy $myna\
me = basename($0);\n\nuse strict;\nuse warnings;\n\
\nuse File::Basename;\nuse Getopt::Long;\nuse File\
::Glob ':glob';\nuse File::Spec;\nuse File::Temp q\
w/ tempfile tempdir /;\n\n\n\n\nsub tcoffeelib_hea\
der($;$)\n{\n    my ($nseq, $fd) = @_;\n    if (! \
defined($fd)) {\n        $fd = *STDOUT;\n    }\n  \
  printf $fd \"! TC_LIB_FORMAT_01\\n\";\n    print\
f $fd \"%d\\n\", $nseq;\n}\n\n\nsub tcoffeelib_hea\
der_addseq($$;$)\n{\n    my ($id, $seq, $fd) = @_;\
\n    if (! defined($fd)) {\n        $fd = *STDOUT\
;\n    }\n    printf $fd \"%s %d %s\\n\", $id, len\
gth($seq), $seq;\n}\n\n\nsub tcoffeelib_comment($;\
$)\n{\n    my ($comment, $fd) = @_;\n    if (! def\
ined($fd)) {\n        $fd = *STDOUT;\n    }\n    p\
rintf $fd \"!\" . $comment . \"\\n\";\n}\n\n\nsub \
tcoffeelib_struct($$$;$)\n{\n    my ($nseq, $len, \
$bpm, $fd) = @_;\n\n    if (! defined($fd)) {\n   \
     $fd = *STDOUT;\n    }\n\n    # output basepai\
r indices with fixed weight\n    printf $fd \"#%d \
%d\\n\", $nseq, $nseq;\n    # output basepairs (on\
ly once) and with unit-offset\n    for (my $i=0; $\
i<$len; $i++) {\n        for (my $j=$i+1; $j<$len;\
 $j++) {\n            if (! defined($bpm->[$i][$j]\
)) {\n                print STDERR \"ERROR: \\$bpm\
->[$i][$j] undefined\\n\";\n            }\n       \
     if ($bpm->[$i][$j]>0) {\n                prin\
t $fd $i+1;\n                print $fd \" \";\n   \
             print $fd $j+1;\n                prin\
t $fd \" \" . $bpm->[$i][$j] . \"\\n\";\n         \
   }\n        }\n    }\n}\n\n\nsub tcoffeelib_foot\
er(;$)\n{\n    my ($fd) = @_;\n    if (! defined($\
fd)) {\n        $fd = *STDOUT;\n    }\n    print $\
fd \"! SEQ_1_TO_N\\n\";\n}\n\n\n    \nsub plfold($\
$$)\n{    \n    my ($id, $seq, $probtresh) = @_;\n\
    my (@struct);# return\n    my ($templ, $fhtmp,\
 $fnametmp, $cmd, $ctr, $window_size);\n    our $n\
temp++;\n    \n    $templ = $myname . \".pid-\" . \
$$ .$ntemp .\".XXXXXX\";\n    ($fhtmp, $fnametmp) \
= tempfile($templ, UNLINK => 1); \n    print $fhtm\
p \">$id\\n$seq\\n\";\n\n    # --- init basepair a\
rray\n    #\n    for (my $i=0; $i<length($seq); $i\
++) {\n        for (my $j=$i+1; $j<length($seq); $\
j++) {\n            $struct[$i][$j]=0;\n        }\\
n    }\n\n\n    # --- call rnaplfold and drop a re\
adme\n    #\n    $window_size=(length($seq)<70)?le\
ngth($seq):70;\n    $cmd = \"RNAplfold -W $window_\
size < $fnametmp >/dev/null\";\n    system($cmd);\\
n    \n    if ($? != 0) {\n        printf STDERR \\
"ERROR: RNAplfold ($cmd) exited with error status \
%d\\n\", $? >> 8;\n        return;\n    }\n    #un\
link($fnametmp);\n    my $fps = sprintf(\"%s_dp.ps\
\", $id); # check long name\n    \n    if (! -s $f\
ps) {\n      {\n\n	$fps = sprintf(\"%s_dp.ps\", su\
bstr($id,0,12)); # check short name\n 	if (! -s $f\
ps)\n	  {\n	    die(\"couldn't find expected file \
$fps\\n\");\n	    return;\n	  }\n      }\n    }\n\\
n    \n    # --- read base pairs from created post\
script\n    #\n    open(FH, $fps);\n    while (my \
$line = <FH>) {\n        my ($nti, $ntj, $prob);\n\
        chomp($line);        \n        # line: bp \
bp sqrt-prob ubox\n        my @match = ($line =~ m\
/^([0-9]+) +([0-9]+) +([0-9\\.]+) +ubox$/);\n     \
   if (scalar(@match)) {\n            $nti=$1;\n  \
          $ntj=$2;\n            $prob=$3*$3;# prob\
 stored as square root\n\n            if ($prob>$p\
robtresh) {\n                #printf STDERR \"\\$s\
truct[$nti][$ntj] sqrtprob=$3 prob=$prob > $probtr\
esh\\n\";\n                $struct[$nti-1][$ntj-1]\
 = $WEIGHT\n            }\n            # store wit\
h zero-offset\n        }\n    }\n    close(FH);\n\\
n    # remove or gzi postscript\n    #\n    unlink\
($fps);\n    #\n    # or gzip\n    #$cmd = \"gzip \
-qf $fps\";\n    #system($cmd);\n    #if ($? != 0)\
 {\n    #    printf STDERR \"ERROR: gzip ($cmd) ex\
ited with error status %d\\n\", $? >> 8;\n    #}\n\
\n    return \\@struct;\n}\n\n\n\n\n\nsub rnaseqfm\
t($)\n{\n    my ($seq) = @_;\n    # remove gaps\n \
   $seq =~ s/-//g;\n    # uppercase RNA\n    $seq \
= uc($seq);\n    # T -> U\n    $seq =~ s/T/U/g;\n \
   # check for invalid charaters\n    $_ = $seq;\n\
    s/[^$NUCALPH]//g;\n    return $_;\n}\n\n\n\n\n\
sub usage(;$)\n{    \n    my ($errmsg) = @_;\n    \
if ($errmsg) {\n        print STDERR \"ERROR: $err\
msg\\n\";\n    }\n    print STDERR << \"EOF\";\n$m\
yname:\n Creates a T-Coffee RNA structure library \
from RNAplfold prediction.\n See FIXME:citation\nU\
sage:\n $myname -in seq_file -out tcoffee_lib\nEOF\
\n    exit(1);\n}\n\nsub read_fasta_seq \n  {\n   \
 my $f=$_[0];\n    my %hseq;\n    my (@seq, @com, \
@name);\n    my ($a, $s,$nseq);\n\n    open (F, $f\
);\n    while (<F>)\n      {\n	$s.=$_;\n      }\n \
   close (F);\n\n    \n    @name=($s=~/>(\\S*).*\\\
n[^>]*/g);\n    \n    @seq =($s=~/>.*.*\\n([^>]*)/\
g);\n    @com =($s=~/>(\\S*)(.*)\\n([^>]*)/g);\n\n\
\n    $nseq=$#name+1;\n  \n    for ($a=0; $a<$nseq\
; $a++)\n      {\n	my $n=$name[$a];\n	my $s;\n	$hs\
eq{$n}{name}=$n;\n	$s=$seq[$a];$s=~s/\\s//g;\n	\n	\
$hseq{$n}{seq}=$s;\n	$hseq{$n}{com}=$com[$a];\n   \
   }\n    return %hseq;\n  }\n\n\n\n\n\n\n\nmy $fm\
sq = \"\";\nmy $flib = \"\";\nmy %OPTS;\nmy %seq;\\
nmy ($id, $nseq, $i);\nmy @nl;\n\nGetOptions(\"in=\
s\" => \\$fmsq, \"out=s\" => \\$flib);\n\nif (! -s\
 $fmsq) {\n    usage(\"empty or non-existant file \
\\\"$fmsq\\\"\")\n}\nif (length($flib)==0) {\n    \
usage(\"empty out-filename\")\n}\n\n\n\n\n\n\n%seq\
=read_fasta_seq($fmsq);\n\n\n@nl=keys(%seq);\n\n$n\
seq=$#nl+1;\nopen FD_LIB, \">$flib\" or die \"can'\
t open $flib!\";\ntcoffeelib_header($nseq, *FD_LIB\
);\nforeach $id (keys (%seq))\n  {\n    my ($seq, \
$fmtseq);\n    \n    $seq = $seq{$id}{seq};\n    \\
n    $fmtseq = rnaseqfmt($seq);# check here, forma\
tting for folding important later\n    if (length(\
$seq)!=length($fmtseq)) {\n        print STDERR \"\
ERROR: invalid sequence $id is not an RNA sequence\
. read seq is: $seq\\n\";\n        exit\n      }\n\
   \n    tcoffeelib_header_addseq($id, uc($seq), *\
FD_LIB);\n  }\ntcoffeelib_comment(\"generated by $\
myname on \" . localtime(), *FD_LIB);\n\n\n\n$i=0;\
\nforeach $id (keys (%seq))\n  {\n    my ($cleanid\
, $seq, $bpm);\n    $seq=$seq{$id}{seq};\n    $cle\
anid = $id;\n    $cleanid =~ s,[/ ],_,g;# needed f\
or rnaplfold\n    $seq = rnaseqfmt($seq);\n    \n \
   $bpm = plfold($cleanid, rnaseqfmt($seq), $PROBT\
RESH);       \n    \n    tcoffeelib_struct($i+1, l\
ength($seq), $bpm, *FD_LIB);\n    $i++;\n}\n\n\ntc\
offeelib_footer(*FD_LIB);\nclose FD_LIB;\nexit (0)\
;\n\n","\n\n\n\n\n$cmd=join ' ', @ARGV;\nif ($cmd=\
~/-infile=(\\S+)/){ $seqfile=$1;}\nif ($cmd=~/-out\
file=(\\S+)/){ $libfile=$1;}\n\n\n\n%s=read_fasta_\
seq ($seqfile);\n\nopen (F, \">$libfile\");\nforea\
ch $name (keys (%s))\n  {\n    my $tclib=\"$name.R\
NAplfold_tclib\";\n    print (F \">$name _F_ $tcli\
b\\n\");\n    seq2RNAplfold2tclib ($name, $s{$name\
}{seq}, $tclib);\n  }\nclose (F);\nexit (EXIT_SUCC\
ESS);\n\nsub seq2RNAplfold2tclib\n  {\n    my ($na\
me, $seq, $tclib)=@_;\n    my ($tmp);\n    $n++;\n\
    $tmp=\"tmp4seq2RNAplfold_tclib.$$.$n.pep\";\n \
   open (RF, \">$tmp\");\n    print (RF \">$name\\\
n$seq\\n\");\n    close (RF);\n    \n    system \"\
t_coffee -other_pg RNAplfold2tclib.pl -in=$tmp -ou\
t=$tclib\";\n    \n    unlink ($tmp);\n    return \
$tclib;\n  }\n    \n    \nsub read_fasta_seq \n  {\
\n    my $f=@_[0];\n    my %hseq;\n    my (@seq, @\
com, @name);\n    my ($a, $s,$nseq);\n\n    open (\
F, $f);\n    while (<F>)\n      {\n	$s.=$_;\n     \
 }\n    close (F);\n\n    \n    @name=($s=~/>(\\S*\
).*\\n[^>]*/g);\n    \n    @seq =($s=~/>.*.*\\n([^\
>]*)/g);\n    @com =($s=~/>\\S*(.*)\\n([^>]*)/g);\\
n\n    \n    $nseq=$#name+1;\n    \n    for ($a=0;\
 $a<$nseq; $a++)\n      {\n	my $n=$name[$a];\n	$hs\
eq{$n}{name}=$n;\n	$hseq{$n}{seq}=$seq[$a];\n	$hse\
q{$n}{com}=$com[$a];\n      }\n    return %hseq;\n\
  }\n","use Getopt::Long;\nuse File::Path;\nuse En\
v;\nuse FileHandle;\nuse Cwd;\nuse Sys::Hostname;\\
nour $PIDCHILD;\nour $ERROR_DONE;\nour @TMPFILE_LI\
ST;\nour $EXIT_FAILURE=1;\nour $EXIT_SUCCESS=0;\n\\
nour $REFDIR=getcwd;\nour $EXIT_SUCCESS=0;\nour $E\
XIT_FAILURE=1;\n\nour $PROGRAM=\"tc_generic_method\
.pl\";\nour $CL=$PROGRAM;\n\nour $CLEAN_EXIT_START\
ED;\nour $debug_lock=$ENV{\"DEBUG_LOCK\"};\nour $L\
OCKDIR=$ENV{\"LOCKDIR_4_TCOFFEE\"};\nif (!$LOCKDIR\
){$LOCKDIR=getcwd();}\nour $ERRORDIR=$ENV{\"ERRORD\
IR_4_TCOFFEE\"};\nour $ERRORFILE=$ENV{\"ERRORFILE_\
4_TCOFFEE\"};\n&set_lock ($$);\nif (isshellpid(get\
ppid())){lock4tc(getppid(), \"LLOCK\", \"LSET\", \\
"$$\\n\");}\n      \nour $print;\nmy ($fmsq1, $fms\
q2, $output, $outfile, $arch, $psv, $hmmtop_home, \
$trim, $cov, $sample, $mode, $gor_home, $gor_seq, \
$gor_obs);\n\nGetOptions(\"-in=s\" => \\$fmsq1,\"-\
output=s\" =>\\$output ,\"-out=s\" => \\$outfile, \
\"-arch=s\" => \\$arch,\"-psv=s\" => \\$psv, \"-hm\
mtop_home=s\", \\$hmmtop_home,\"-trim=s\" =>\\$tri\
m ,\"-print=s\" =>\\$print,\"-cov=s\" =>\\$cov , \\
"-sample=s\" =>\\$sample, \"-mode=s\" =>\\$mode, \\
"-gor_home=s\"=>\\$gor_home, \"-gor_seq=s\"=>\\$go\
r_seq,\"-gor_obs=s\"=>\\$gor_obs);\n\n\nif (!$mode\
){$mode = \"hmmtop\"}\nelsif ($mode eq \"hmmtop\")\
{;}\nelsif ($mode eq \"gor\"){;}\nelse {myexit(flu\
sh_error (\"-mode=$mode is unknown\"));}\n\n\nour \
$HOME=$ENV{\"HOME\"};\nour $MCOFFEE=($ENV{\"MCOFFE\
E_4_TCOFFEE\"})?$ENV{\"MCOFFEE_4_TCOFFEE\"}:\"$HOM\
E/.t_coffee/mcoffee\";\n\nif ($mode eq \"hmmtop\")\
\n  {\n    \n    check_configuration (\"hmmtop\");\
\n    if (-e $arch){$ENV{'HMMTOP_ARCH'}=$arch;}\n \
   elsif (-e $ENV{HMMTOP_ARCH}){$arch=$ENV{HMMTOP_\
ARCH};}\n    elsif (-e \"$MCOFFEE/hmmtop.arch\"){$\
arch=$ENV{'HMMTOP_ARCH'}=\"$MCOFFEE/hmmtop.arch\";\
}\n    elsif (-e \"$hmmtop_home/hmmtop.arch\"){$ar\
ch=$ENV{'HMMTOP_ARCH'}=\"$hmmtop_home/hmmtop.arch\\
";}\n    else {myexit(flush_error ( \"Could not fi\
nd ARCH file for hmmtop\"));}\n    \n    \n    if \
(-e $psv){$ENV{'HMMTOP_PSV'}=$psv;}\n    elsif (-e\
 $ENV{HMMTOP_PSV}){$psv=$ENV{HMMTOP_PSV};}\n    el\
sif (-e \"$MCOFFEE/hmmtop.psv\"){$psv=$ENV{'HMMTOP\
_PSV'}=\"$MCOFFEE/hmmtop.psv\";}\n    elsif (-e \"\
$hmmtop_home/hmmtop.psv\"){$psv=$ENV{'HMMTOP_PSV'}\
=\"$hmmtop_home/hmmtop.psv\";}\n    else {myexit(f\
lush_error ( \"Could not find PSV file for hmmtop\\
"));}\n\n  }\nelsif ($mode eq \"gor\")\n  {\n    o\
ur $GOR_SEQ;\n    our $GOR_OBS;\n    \n    check_c\
onfiguration (\"gorIV\");\n    if (-e $gor_seq){$G\
OR_SEQ=$gor_seq;}\n    elsif (-e $ENV{GOR_SEQ}){$G\
OR_SEQ=$ENV{GOR_SEQ};}\n    elsif (-e \"$MCOFFEE/N\
ew_KS.267.seq\"){$GOR_SEQ=\"$MCOFFEE/New_KS.267.se\
q\";}\n    elsif (-e \"$gor_home/New_KS.267.seq\")\
{$GOR_SEQ=\"$gor_home/New_KS.267.seq\";}\n    else\
 {myexit(flush_error ( \"Could not find SEQ file f\
or gor\"));}\n\n    if (-e $gor_obs){$GOR_OBS=$gor\
_obs;}\n    elsif (-e $ENV{GOR_OBS}){$GOR_OBS=$ENV\
{GOR_OBS};}\n    elsif (-e \"$MCOFFEE/New_KS.267.o\
bs\"){$GOR_OBS=\"$MCOFFEE/New_KS.267.obs\";}\n    \
elsif (-e \"$gor_home/New_KS.267.obs\"){$GOR_OBS=\\
"$gor_home/New_KS.267.obs\";}\n    else {myexit(fl\
ush_error ( \"Could not find OBS file for gor\"));\
}\n  }\n\n\nif ( ! -e $fmsq1){myexit(flush_error (\
\"Could Not Read Input file $fmsq1\"));}\n\n\nmy $\
fmsq2=vtmpnam();\nmy $fmsq3=vtmpnam();\nmy $tmpfil\
e=vtmpnam();\nmy $predfile=vtmpnam();\n\nif ($trim\
){$trim_action=\" +trim _aln_%%$trim\\_K1 \";}\nif\
 ($cov) {$cov_action= \" +sim_filter _aln_c$cov \"\
;}\n&safe_system(\"t_coffee -other_pg seq_reformat\
 -in $fmsq1 -action +convert 'BOUJXZ-' $cov_action\
 $trim_action -output fasta_aln -out $fmsq2\");\nm\
y (%pred, %seq, %predA);\n\n\n%seq=read_fasta_seq(\
$fmsq2);\n%seq=fasta2sample(\\%seq, $sample);\n\ni\
f (1==2 &&$mode eq \"hmmtop\" && $output eq \"cons\
\")\n  {\n    fasta2hmmtop_cons($outfile,\\%seq);\\
n  }\nelse\n  {\n   \n    %pred=fasta2pred(\\%seq,\
 $mode);\n    %predA=pred2aln (\\%pred, \\%seq);\n\
    \n    \n    if (!$output || $output eq \"predi\
ction\"){output_fasta_seq (\\%predA, $outfile);}\n\
    elsif ($output eq \"color_html\"){pred2color (\
\\%pred,\\%seq, $outfile);}\n    elsif ($output eq\
 \"cons\"){pred2cons($outfile,\\%predA);}\n    els\
e {flush_error (\"$output is an unknown output mod\
e\");}\n  }\n\nsub fasta2sample\n  {\n    my $SR=s\
hift;\n    my $it=shift;\n    my %S=%$SR;\n    \n \
   my $seq=index2seq_name (\\%S, 1);\n    my $l=le\
ngth($S{$seq}{seq});\n    my @sl=keys(%S);\n    my\
 $nseq=$#sl+1;\n    my $index=$nseq;\n  \n    if (\
!$sample) {return %S;}\n    for (my $a=0; $a<$it; \
$a++)\n      {\n	my $newseq=\"\";\n	my $nname=\"$s\
eq\\_sampled_$index\";\n	for (my $p=0; $p<$l; $p++\
)\n	  {\n	    my $i=int(rand($nseq));\n	    \n	   \
 my $name = $sl[$i];\n	    my $seq=$S{$name}{seq};\
\n	    my $r=substr ($seq, $p, 1);\n	    $newseq.=\
$r;\n	  }\n	$S{$nname}{name}=$nname;\n	$S{$nname}{\
seq}=$newseq;\n	$S{$nname}{com}=\"sampled\";\n	$S{\
$nname}{index}=++$index;\n      }\n    return %S;\\
n  }\n	      \nsub fasta2pred\n  {\n    my $s=shif\
t;\n    my $mode=shift;\n\n    if ( $mode eq \"hmm\
top\"){return fasta2hmmtop_pred($s);}\n    elsif (\
$mode eq \"gor\"){return fasta2gor_pred ($s);}\n  \
}\nsub fasta2hmmtop_cons\n  {\n    my $outfile=shi\
ft;\n    my $SR=shift;\n    \n    my $o = new File\
Handle;\n    my $i = new FileHandle;\n    my $tmp_\
in =vtmpnam();\n    my $tmp_out=vtmpnam();\n    my\
 %seq=%$SR;\n    my %pred;\n    my $N=keys(%seq);\\
n    \n    output_fasta_seq (\\%seq,$tmp_in, \"seq\
\");\n    `hmmtop -pi=mpred -if=$tmp_in -sf=FAS -p\
l 2>/dev/null >$tmp_out`;\n    open ($o, \">$outfi\
le\");\n    open ($i, \"$tmp_out\");\n    while (<\
$i>)\n      {\n	my $l=$_;\n	if (($l=~/>HP\\:\\s+(\\
\d+)\\s+(.*)/)){my $line=\">$2 NSEQ: $N\\n\";print\
 $o \"$line\";}\n	elsif ( ($l=~/.*pred(.*)/))  {my\
 $line=\"$1\\n\";print $o \"$line\";}\n      }\n  \
  close ($o);\n    close ($i);\n    return read_fa\
sta_seq($tmp);\n  }\nsub fasta2hmmtop_pred\n  {\n \
   my $SR=shift;\n    my $o = new FileHandle;\n   \
 my $i = new FileHandle;\n    my $tmp    =vtmpnam(\
);\n    my $tmp_in =vtmpnam();\n    my $tmp_out=vt\
mpnam();\n    my %seq=%$SR;\n    my %pred;\n    \n\
\n    output_fasta_seq (\\%seq,$tmp_in, \"seq\");\\
n\n    \n    `hmmtop -if=$tmp_in -sf=FAS -pl 2>/de\
v/null >$tmp_out`;\n    \n\n    \n    \n    open (\
$o, \">$tmp\");\n    open ($i, \"$tmp_out\");\n   \
 while (<$i>)\n      {\n	my $l=$_;\n	if (($l=~/>HP\
\\:\\s+(\\d+)\\s+(.*)/)){my $line=\">$2\\n\";print\
 $o \"$line\";}\n	elsif ( ($l=~/.*pred(.*)/))  {my\
 $line=\"$1\\n\";print $o \"$line\";}\n      }\n  \
  close ($o);\n    close ($i);\n    return read_fa\
sta_seq($tmp);\n  }\n    \n	\n	\n	    \n	\n	\n\n	\\
nsub fasta2gor_pred\n  {\n    my $SR=shift;\n    m\
y $o = new FileHandle;\n    my $i = new FileHandle\
;\n    my $tmp    =vtmpnam();\n    my $tmp_in =vtm\
pnam();\n    my $tmp_out=vtmpnam();\n    my %seq=%\
$SR;\n    my %pred;\n    \n\n    output_fasta_seq \
(\\%seq,$tmp_in, \"seq\");\n    `gorIV -prd $tmp_i\
n -seq $GOR_SEQ -obs $GOR_OBS >$tmp_out`;\n    ope\
n ($o, \">$tmp\");\n    open ($i, \"$tmp_out\");\n\
    while (<$i>)\n      {\n	my $l=$_;\n\n	\n	if ( \
$l=~/>/){print $o \"$l\";}\n	elsif ( $l=~/Predicte\
d Sec. Struct./){$l=~s/Predicted Sec. Struct\\.//;\
print $o \"$l\";}\n      }\n    close ($o);\n    c\
lose ($i);\n    return read_fasta_seq($tmp);\n  }\\
n			\n			     \nsub index2seq_name\n  {\n    \n   \
 my $SR=shift;\n    my $index=shift;\n    \n    \n\
    my %S=%$SR;\n    \n    foreach my $s (%S)\n   \
   {\n	if ( $S{$s}{index}==$index){return $s;}\n  \
    }\n    return \"\";\n  }\n\nsub pred2cons\n  {\
\n    my $outfile=shift;\n    my $predR=shift;\n  \
  my $seq=shift;\n    my %P=%$predR;\n    my %C;\n\
    my ($s,@r,$nseq);\n    my $f= new FileHandle;\\
n\n    open ($f, \">$outfile\");\n\n    if (!$seq)\
{$seq=index2seq_name(\\%P,1);}\n    foreach my $s \
(keys(%P))\n      {\n	$nseq++;\n	$string= $P{$s}{s\
eq};\n	$string = uc $string;\n	my @r=split (//,$st\
ring);\n	for (my $a=0; $a<=$#r; $a++)\n	  {\n	    \
if (($r[$a]=~/[OHICE]/)){$C{$a}{$r[$a]}++;}\n	  }\\
n      }\n    @l=keys(%C);\n    \n    \n    $s=$P{\
$seq}{seq};\n    print $f \">$seq pred based on $n\
seq\\n\";\n    @r=split (//,$s);\n    \n    for (m\
y $x=0; $x<=$#r; $x++)\n      {\n	if ($r[$x] ne \"\
-\")\n	  {\n	    my $h=$C{$x}{H};\n	    my $i=$C{$\
x}{I};\n	    my $o=$C{$x}{O};\n	    my $c=$C{$x}{C\
};\n	    my $e=$C{$x}{E};\n	    my $l=$i+$o;\n	   \
 \n	    if ($h>=$i && $h>=$o && $h>=$c && $h>=$e){\
$r[$x]='H';}\n	    elsif ($i>=$o && $i>=$c && $i>=\
$e){$r[$x]='I';}\n	    elsif ($o>=$c && $o>=$e){$r\
[$x]='O';}\n	    elsif ($c>=$e){$r[$x]='C';}\n	   \
 else {$r[$x]='E';}\n	  }\n      }\n    $j=join ('\
', @r);\n    print $f \"$j\\n\";\n    close ($f);\\
n    return $j;\n  }\n\nsub pred2aln\n  {\n    my \
$PR=shift;\n    my $AR=shift;\n    \n    my $f=new\
 FileHandle;\n    my %P=%$PR;\n    my %A=%$AR;\n  \
  my %PA;\n    my $tmp=vtmpnam();\n    my $f= new \
FileHandle;\n    \n    open ($f, \">$tmp\");\n    \
foreach my $s (sort{$A{$a}{index}<=>$A{$b}{index}}\
(keys (%A)))\n      {\n	my (@list, $seq, @plist, @\
pseq, $L, $PL, $c, $w);\n	my $seq;\n	my $seq=$A{$s\
}{seq};\n	my $pred=$P{$s}{seq};\n	$seq=pred2alnS($\
P{$s}{seq},$A{$s}{seq});\n	print $f \">$s\\n$seq\\\
n\";\n      }\n    close ($f);\n    return read_fa\
sta_seq ($tmp);\n  }\nsub pred2alnS\n  {\n    my $\
pred=shift;\n    my $aln= shift;\n    my ($j,$a,$b\
);\n    my @P=split (//, $pred);\n    my @A=split \
(//, $aln);\n    for ($a=$b=0;$a<=$#A; $a++)\n    \
  {\n	if ($A[$a] ne \"-\"){$A[$a]=$P[$b++];}\n    \
  }\n    if ($b!= ($#P+1)){add_warning (\"Could no\
t thread sequence: $b $#P\");}\n    \n    $j= join\
 ('', @A);\n    return $j;\n  }\nsub pred2color\n \
 {\n    my $predP=shift;\n    my $alnP=shift;\n   \
 my $out=shift;\n    my $F=new FileHandle;\n    my\
 $struc=vtmpnam();\n    my $aln=vtmpnam();\n    \n\
\n    output_fasta_seq ($alnP, $aln);\n    my %p=%\
$predP;\n    \n    open ($F, \">$struc\");\n    \n\
    \n    foreach my $s (keys(%p))\n      {\n	\n	p\
rint $F \">$s\\n\";\n	my $s=uc($p{$s}{seq});\n	\n	\
$s=~s/[Oo]/0/g;\n	$s=~s/[Ee]/0/g;\n	\n	$s=~s/[Ii]/\
5/g;\n	$s=~s/[Cc]/5/g;\n	\n	$s=~s/[Hh]/9/g;\n	\n	p\
rint $F \"$s\\n\";\n      }\n    close ($F);\n    \
\n    \n    \n    safe_system ( \"t_coffee -other_\
pg seq_reformat -in $aln -struc_in $struc -struc_i\
n_f number_fasta -output color_html -out $out\");\\
n    return;\n  }\n	  \n    \nsub display_fasta_se\
q\n  {\n    my $SR=shift;\n    my %S=%$SR;\n    \n\
    foreach my $s (sort{$S{$a}{index}<=>$S{$b}{ind\
ex}}(keys (%S)))\n      {\n	print STDERR \">$s\\n$\
S{$s}{seq}\\n\";\n      }\n    close ($f);\n  }\ns\
ub output_fasta_seq\n  {\n    my $SR=shift;\n    m\
y $outfile=shift;\n    my $mode =shift;\n    my $f\
= new FileHandle;\n    my %S=%$SR;\n    \n    \n  \
  open ($f, \">$outfile\");\n    foreach my $s (so\
rt{$S{$a}{index}<=>$S{$b}{index}}(keys (%S)))\n   \
   {\n	my $seq=$S{$s}{seq};\n	if ( $mode eq \"seq\\
"){$seq=~s/\\-//g;}\n	print $f \">$s\\n$seq\\n\";\\
n      }\n    close ($f);\n  }\n      \nsub read_f\
asta_seq \n  {\n    my $f=$_[0];\n    my %hseq;\n \
   my (@seq, @com, @name);\n    my ($a, $s,$nseq);\
\n    my $index;\n    open (F, $f);\n    while (<F\
>)\n      {\n	$s.=$_;\n      }\n    close (F);\n\n\
    \n    @name=($s=~/>(\\S*).*\\n[^>]*/g);\n    \\
n    @seq =($s=~/>.*.*\\n([^>]*)/g);\n    @com =($\
s=~/>.*(.*)\\n([^>]*)/g);\n\n\n    $nseq=$#name+1;\
\n    \n  \n    for ($a=0; $a<$nseq; $a++)\n      \
{\n	my $n=$name[$a];\n	my $s;\n	$hseq{$n}{name}=$n\
;\n	$s=$seq[$a];$s=~s/\\s//g;\n	$hseq{$n}{index}=+\
+$index;\n	$hseq{$n}{seq}=$s;\n	$hseq{$n}{com}=$co\
m[$a];\n      }\n    return %hseq;\n  }\n\n\nsub f\
ile2head\n      {\n	my $file = shift;\n	my $size =\
 shift;\n	my $f= new FileHandle;\n	my $line;\n	ope\
n ($f,$file);\n	read ($f,$line, $size);\n	close ($\
f);\n	return $line;\n      }\nsub file2tail\n     \
 {\n	my $file = shift;\n	my $size = shift;\n	my $f\
= new FileHandle;\n	my $line;\n	\n	open ($f,$file)\
;\n	seek ($f,$size*-1, 2);\n	read ($f,$line, $size\
);\n	close ($f);\n	return $line;\n      }\n\n\nsub\
 vtmpnam\n      {\n	my $r=rand(100000);\n	my $f=\"\
file.$r.$$\";\n	while (-e $f)\n	  {\n	    $f=vtmpn\
am();\n	  }\n	push (@TMPFILE_LIST, $f);\n	return $\
f;\n      }\n\nsub myexit\n  {\n    my $code=@_[0]\
;\n    if ($CLEAN_EXIT_STARTED==1){return;}\n    e\
lse {$CLEAN_EXIT_STARTED=1;}\n    ### ONLY BARE EX\
IT\n    exit ($code);\n  }\nsub set_error_lock\n  \
  {\n      my $name = shift;\n      my $pid=$$;\n\\
n      \n      &lock4tc ($$,\"LERROR\", \"LSET\", \
\"$$ -- ERROR: $name $PROGRAM\\n\");\n      return\
;\n    }\nsub set_lock\n  {\n    my $pid=shift;\n \
   my $msg= shift;\n    my $p=getppid();\n    &loc\
k4tc ($pid,\"LLOCK\",\"LRESET\",\"$p$msg\\n\");\n \
 }\nsub unset_lock\n   {\n     \n    my $pid=shift\
;\n    &lock4tc ($pid,\"LLOCK\",\"LRELEASE\",\"\")\
;\n  }\nsub shift_lock\n  {\n    my $from=shift;\n\
    my $to=shift;\n    my $from_type=shift;\n    m\
y $to_type=shift;\n    my $action=shift;\n    my $\
msg;\n    \n    if (!&lock4tc($from, $from_type, \\
"LCHECK\", \"\")){return 0;}\n    $msg=&lock4tc ($\
from, $from_type, \"LREAD\", \"\");\n    &lock4tc \
($from, $from_type,\"LRELEASE\", $msg);\n    &lock\
4tc ($to, $to_type, $action, $msg);\n    return;\n\
  }\nsub isshellpid\n  {\n    my $p=shift;\n    if\
 (!lock4tc ($p, \"LLOCK\", \"LCHECK\")){return 0;}\
\n    else\n      {\n	my $c=lock4tc($p, \"LLOCK\",\
 \"LREAD\");\n	if ( $c=~/-SHELL-/){return 1;}\n   \
   }\n    return 0;\n  }\nsub isrootpid\n  {\n    \
if(lock4tc (getppid(), \"LLOCK\", \"LCHECK\")){ret\
urn 0;}\n    else {return 1;}\n  }\nsub lock4tc\n	\
{\n	  my ($pid,$type,$action,$value)=@_;\n	  my $f\
name;\n	  my $host=hostname;\n	  \n	  if ($type eq\
 \"LLOCK\"){$fname=\"$LOCKDIR/.$pid.$host.lock4tco\
ffee\";}\n	  elsif ( $type eq \"LERROR\"){ $fname=\
\"$LOCKDIR/.$pid.$host.error4tcoffee\";}\n	  elsif\
 ( $type eq \"LWARNING\"){ $fname=\"$LOCKDIR/.$pid\
.$host.warning4tcoffee\";}\n	  \n	  if ($debug_loc\
k)\n	    {\n	      print STDERR \"\\n\\t---lock4tc\
(tcg): $action => $fname =>$value (RD: $LOCKDIR)\\\
n\";\n	    }\n\n	  if    ($action eq \"LCHECK\") {\
return -e $fname;}\n	  elsif ($action eq \"LREAD\"\
){return file2string($fname);}\n	  elsif ($action \
eq \"LSET\") {return string2file ($value, $fname, \
\">>\");}\n	  elsif ($action eq \"LRESET\") {retur\
n string2file ($value, $fname, \">\");}\n	  elsif \
($action eq \"LRELEASE\") \n	    {\n	      if ( $d\
ebug_lock)\n		{\n		  my $g=new FileHandle;\n		  op\
en ($g, \">>$fname\");\n		  print $g \"\\nDestroye\
d by $$\\n\";\n		  close ($g);\n		  safe_system (\\
"mv $fname $fname.old\");\n		}\n	      else\n		{\n\
		  unlink ($fname);\n		}\n	    }\n	  return \"\";\
\n	}\n	\nsub file2string\n	{\n	  my $file=@_[0];\n\
	  my $f=new FileHandle;\n	  my $r;\n	  open ($f, \
\"$file\");\n	  while (<$f>){$r.=$_;}\n	  close ($\
f);\n	  return $r;\n	}\nsub string2file \n    {\n \
   my ($s,$file,$mode)=@_;\n    my $f=new FileHand\
le;\n    \n    open ($f, \"$mode$file\");\n    pri\
nt $f  \"$s\";\n    close ($f);\n  }\n\nBEGIN\n   \
 {\n      srand;\n    \n      $SIG{'SIGUP'}='signa\
l_cleanup';\n      $SIG{'SIGINT'}='signal_cleanup'\
;\n      $SIG{'SIGQUIT'}='signal_cleanup';\n      \
$SIG{'SIGILL'}='signal_cleanup';\n      $SIG{'SIGT\
RAP'}='signal_cleanup';\n      $SIG{'SIGABRT'}='si\
gnal_cleanup';\n      $SIG{'SIGEMT'}='signal_clean\
up';\n      $SIG{'SIGFPE'}='signal_cleanup';\n    \
  \n      $SIG{'SIGKILL'}='signal_cleanup';\n     \
 $SIG{'SIGPIPE'}='signal_cleanup';\n      $SIG{'SI\
GSTOP'}='signal_cleanup';\n      $SIG{'SIGTTIN'}='\
signal_cleanup';\n      $SIG{'SIGXFSZ'}='signal_cl\
eanup';\n      $SIG{'SIGINFO'}='signal_cleanup';\n\
      \n      $SIG{'SIGBUS'}='signal_cleanup';\n  \
    $SIG{'SIGALRM'}='signal_cleanup';\n      $SIG{\
'SIGTSTP'}='signal_cleanup';\n      $SIG{'SIGTTOU'\
}='signal_cleanup';\n      $SIG{'SIGVTALRM'}='sign\
al_cleanup';\n      $SIG{'SIGUSR1'}='signal_cleanu\
p';\n\n\n      $SIG{'SIGSEGV'}='signal_cleanup';\n\
      $SIG{'SIGTERM'}='signal_cleanup';\n      $SI\
G{'SIGCONT'}='signal_cleanup';\n      $SIG{'SIGIO'\
}='signal_cleanup';\n      $SIG{'SIGPROF'}='signal\
_cleanup';\n      $SIG{'SIGUSR2'}='signal_cleanup'\
;\n\n      $SIG{'SIGSYS'}='signal_cleanup';\n     \
 $SIG{'SIGURG'}='signal_cleanup';\n      $SIG{'SIG\
CHLD'}='signal_cleanup';\n      $SIG{'SIGXCPU'}='s\
ignal_cleanup';\n      $SIG{'SIGWINCH'}='signal_cl\
eanup';\n      \n      $SIG{'INT'}='signal_cleanup\
';\n      $SIG{'TERM'}='signal_cleanup';\n      $S\
IG{'KILL'}='signal_cleanup';\n      $SIG{'QUIT'}='\
signal_cleanup';\n      \n      our $debug_lock=$E\
NV{\"DEBUG_LOCK\"};\n      \n      \n      \n     \
 \n      foreach my $a (@ARGV){$CL.=\" $a\";}\n   \
   if ( $debug_lock ){print STDERR \"\\n\\n\\n****\
****** START PG: $PROGRAM *************\\n\";}\n  \
    if ( $debug_lock ){print STDERR \"\\n\\n\\n***\
*******(tcg) LOCKDIR: $LOCKDIR $$ *************\\n\
\";}\n      if ( $debug_lock ){print STDERR \"\\n \
--- $$ -- $CL\\n\";}\n      \n	     \n      \n    \
  \n    }\nsub flush_error\n  {\n    my $msg=shift\
;\n    return add_error ($EXIT_FAILURE,$$, $$,getp\
pid(), $msg, $CL);\n  }\nsub add_error \n  {\n    \
my $code=shift;\n    my $rpid=shift;\n    my $pid=\
shift;\n    my $ppid=shift;\n    my $type=shift;\n\
    my $com=shift;\n    \n    $ERROR_DONE=1;\n    \
lock4tc ($rpid, \"LERROR\",\"LSET\",\"$pid -- ERRO\
R: $type\\n\");\n    lock4tc ($$, \"LERROR\",\"LSE\
T\", \"$pid -- COM: $com\\n\");\n    lock4tc ($$, \
\"LERROR\",\"LSET\", \"$pid -- STACK: $ppid -> $pi\
d\\n\");\n   \n    return $code;\n  }\nsub add_war\
ning \n  {\n    my $rpid=shift;\n    my $pid =shif\
t;\n    my $command=shift;\n    my $msg=\"$$ -- WA\
RNING: $command\\n\";\n    print STDERR \"$msg\";\\
n    lock4tc ($$, \"LWARNING\", \"LSET\", $msg);\n\
  }\n\nsub signal_cleanup\n  {\n    print dtderr \\
"\\n**** $$ (tcg) was killed\\n\";\n    &cleanup;\\
n    exit ($EXIT_FAILURE);\n  }\nsub clean_dir\n  \
{\n    my $dir=@_[0];\n    if ( !-d $dir){return ;\
}\n    elsif (!($dir=~/tmp/)){return ;}#safety che\
ck 1\n    elsif (($dir=~/\\*/)){return ;}#safety c\
heck 2\n    else\n      {\n	`rm -rf $dir`;\n      \
}\n    return;\n  }\nsub cleanup\n  {\n    #print \
stderr \"\\n----tc: $$ Kills $PIDCHILD\\n\";\n    \
#kill (SIGTERM,$PIDCHILD);\n    my $p=getppid();\n\
    $CLEAN_EXIT_STARTED=1;\n    \n    \n    \n    \
if (&lock4tc($$,\"LERROR\", \"LCHECK\", \"\"))\n  \
    {\n	my $ppid=getppid();\n	if (!$ERROR_DONE) \n\
	  {\n	    &lock4tc($$,\"LERROR\", \"LSET\", \"$$ \
-- STACK: $p -> $$\\n\");\n	    &lock4tc($$,\"LERR\
OR\", \"LSET\", \"$$ -- COM: $CL\\n\");\n	  }\n   \
   }\n    my $warning=&lock4tc($$, \"LWARNING\", \\
"LREAD\", \"\");\n    my $error=&lock4tc($$,  \"LE\
RROR\", \"LREAD\", \"\");\n    #release error and \
warning lock if root\n    \n    if (isrootpid() &&\
 ($warning || $error) )\n      {\n	\n	print STDERR\
 \"**************** Summary *************\\n$error\
\\n$warning\\n\";\n\n	&lock4tc($$,\"LERROR\",\"REL\
EASE\",\"\");\n	&lock4tc($$,\"LWARNING\",\"RELEASE\
\",\"\");\n      } \n    \n    \n    foreach my $f\
 (@TMPFILE_LIST)\n      {\n	if (-e $f){unlink ($f)\
;} \n      }\n    foreach my $d (@TMPDIR_LIST)\n  \
    {\n	clean_dir ($d);\n      }\n    #No More Loc\
k Release\n    #&lock4tc($$,\"LLOCK\",\"LRELEASE\"\
,\"\"); #release lock \n\n    if ( $debug_lock ){p\
rint STDERR \"\\n\\n\\n********** END PG: $PROGRAM\
 ($$) *************\\n\";}\n    if ( $debug_lock )\
{print STDERR \"\\n\\n\\n**********(tcg) LOCKDIR: \
$LOCKDIR $$ *************\\n\";}\n  }\nEND \n  {\n\
    \n    &cleanup();\n  }\n   \n\nsub safe_system\
 \n{\n  my $com=shift;\n  my $ntry=shift;\n  my $c\
try=shift;\n  my $pid;\n  my $status;\n  my $ppid=\
getppid();\n  if ($com eq \"\"){return 1;}\n  \n  \
\n\n  if (($pid = fork ()) < 0){return (-1);}\n  i\
f ($pid == 0)\n    {\n      set_lock($$, \" -SHELL\
- $com (tcg)\");\n      exec ($com);\n    }\n  els\
e\n    {\n      lock4tc ($$, \"LLOCK\", \"LSET\", \
\"$pid\\n\");#update parent\n      $PIDCHILD=$pid;\
\n    }\n  if ($debug_lock){printf STDERR \"\\n\\t\
 .... safe_system (fasta_seq2hmm)  p: $$ c: $pid C\
OM: $com\\n\";}\n\n  waitpid ($pid,WTERMSIG);\n\n \
 shift_lock ($pid,$$, \"LWARNING\",\"LWARNING\", \\
"LSET\");\n\n  if ($? == $EXIT_FAILURE || lock4tc(\
$pid, \"LERROR\", \"LCHECK\", \"\"))\n    {\n     \
 if ($ntry && $ctry <$ntry)\n	{\n	  add_warning ($\
$,$$,\"$com failed [retry: $ctry]\");\n	  lock4tc \
($pid, \"LRELEASE\", \"LERROR\", \"\");\n	  return\
 safe_system ($com, $ntry, ++$ctry);\n	}\n      el\
sif ($ntry == -1)\n	{\n	  if (!shift_lock ($pid, $\
$, \"LERROR\", \"LWARNING\", \"LSET\"))\n	    {\n	\
      add_warning ($$,$$,\"$com failed\");\n	    }\
\n	  else\n	    {\n	      lock4tc ($pid, \"LRELEAS\
E\", \"LERROR\", \"\");\n	    }\n	  return $?;}\n \
     else\n	{\n	  if (!shift_lock ($pid,$$, \"LERR\
OR\",\"LERROR\", \"LSET\"))\n	    {\n	      myexit\
(add_error ($EXIT_FAILURE,$$,$pid,getppid(), \"UNS\
PECIFIED system\", $com));\n	    }\n	}\n    }\n  r\
eturn $?;\n}\n\nsub check_configuration \n    {\n \
     my @l=@_;\n      my $v;\n      foreach my $p \
(@l)\n	{\n	  \n	  if   ( $p eq \"EMAIL\")\n	    { \
\n	      if ( !($EMAIL=~/@/))\n		{\n		add_warning(\
$$,$$,\"Could Not Use EMAIL\");\n		myexit(add_erro\
r ($EXIT_FAILURE,$$,$$,getppid(),\"EMAIL\",\"$CL\"\
));\n	      }\n	    }\n	  elsif( $p eq \"INTERNET\\
")\n	    {\n	      if ( !&check_internet_connectio\
n())\n		{\n		  myexit(add_error ($EXIT_FAILURE,$$,\
$$,getppid(),\"INTERNET\",\"$CL\"));\n		}\n	    }\\
n	  elsif( $p eq \"wget\")\n	    {\n	      if (!&p\
g_is_installed (\"wget\") && !&pg_is_installed (\"\
curl\"))\n		{\n		  myexit(add_error ($EXIT_FAILURE\
,$$,$$,getppid(),\"PG_NOT_INSTALLED:wget\",\"$CL\"\
));\n		}\n	    }\n	  elsif( !(&pg_is_installed ($p\
)))\n	    {\n	      myexit(add_error ($EXIT_FAILUR\
E,$$,$$,getppid(),\"PG_NOT_INSTALLED:$p\",\"$CL\")\
);\n	    }\n	}\n      return 1;\n    }\nsub pg_is_\
installed\n  {\n    my @ml=@_;\n    my $r, $p, $m;\
\n    my $supported=0;\n    \n    my $p=shift (@ml\
);\n    if ($p=~/::/)\n      {\n	if (safe_system (\
\"perl -M$p -e 1\")==$EXIT_SUCCESS){return 1;}\n	e\
lse {return 0;}\n      }\n    else\n      {\n	$r=`\
which $p 2>/dev/null`;\n	if ($r eq \"\"){return 0;\
}\n	else {return 1;}\n      }\n  }\n\n\n\nsub chec\
k_internet_connection\n  {\n    my $internet;\n   \
 my $tmp;\n    &check_configuration ( \"wget\"); \\
n    \n    $tmp=&vtmpnam ();\n    \n    if     (&p\
g_is_installed    (\"wget\")){`wget www.google.com\
 -O$tmp >/dev/null 2>/dev/null`;}\n    elsif  (&pg\
_is_installed    (\"curl\")){`curl www.google.com \
-o$tmp >/dev/null 2>/dev/null`;}\n    \n    if ( !\
-e $tmp || -s $tmp < 10){$internet=0;}\n    else {\
$internet=1;}\n    if (-e $tmp){unlink $tmp;}\n\n \
   return $internet;\n  }\nsub check_pg_is_install\
ed\n  {\n    my @ml=@_;\n    my $r=&pg_is_installe\
d (@ml);\n    if (!$r && $p=~/::/)\n      {\n	prin\
t STDERR \"\\nYou Must Install the perl package $p\
 on your system.\\nRUN:\\n\\tsudo perl -MCPAN -e '\
install $pg'\\n\";\n      }\n    elsif (!$r)\n    \
  {\n	myexit(flush_error(\"\\nProgram $p Supported\
 but Not Installed on your system\"));\n      }\n \
   else\n      {\n	return 1;\n      }\n  }\n\n\n\n\
","\n\n\n\n\nmy $FMODEL =\"\"; \nmy $TMPDIR = \"/t\
mp\";\n\n\n\n\nmy $NUCALPH = \"ACGTUNRYMKSWHBVD\";\
\nmy $PRIMNUCALPH = \"ACGTUN\";\nuse vars qw($NUCA\
LPH $PRIMNUCALPH $TMPDIR);\n\n\nmy $errmsg;\nuse v\
ars qw($errmsg);\n\n\n\nuse Getopt::Long;\nuse Cwd\
;\nuse File::Basename;\nuse File::Temp qw/ tempfil\
e tempdir /;\nuse File::Copy;\nuse File::Path;\n\n\
\n\nsub usage(;$)\n{\n    my ($errmsg) = @_;\n    \
my $myname = basename($0);\n\n    if ($errmsg) {\n\
        print STDERR \"ERROR: $errmsg\\n\";\n    }\
\n\n    print STDERR << \"EOF\";\n    \n$myname: a\
lign two sequences by means of consan\\'s sfold\nU\
sage:\n $myname -i file -o file -d path\nOptions:\\
n -i|--in : pairwise input sequence file\n -o|--ou\
t: output alignment\n -d|--directory containing da\
ta\n\nEOF\n}\n\nsub read_stk_aln \n  {\n    my $f=\
$_[0];\n    my ($seq, $id);\n    \n    my %hseq;\n\
\n    open (STK, \"$f\");\n    while (<STK>)\n    \
  {\n	if ( /^#/ || /^\\/\\// || /^\\s*$/){;}\n	els\
e\n	  {\n	    ($id,$seq)=/(\\S+)\\s+(\\S+)/;\n	   \
 $hseq{$id}{'seq'}.=$seq;\n	  }\n      }\n    clos\
e (STK);\n    return %hseq;\n  }\nsub read_fasta_s\
eq \n  {\n    my $f=$_[0];\n    my %hseq;\n    my \
(@seq, @com, @name);\n    my ($a, $s,$nseq);\n\n  \
  open (F, $f);\n    while (<F>)\n      {\n	$s.=$_\
;\n      }\n    close (F);\n\n    \n    @name=($s=\
~/>(.*).*\\n[^>]*/g);\n    \n    @seq =($s=~/>.*.*\
\\n([^>]*)/g);\n    @com =($s=~/>.*(.*)\\n([^>]*)/\
g);\n\n    \n    $nseq=$#name+1;\n    \n    for ($\
a=0; $a<$nseq; $a++)\n      {\n	my $n=$name[$a];\n\
	$hseq{$n}{name}=$n;\n	$hseq{$n}{seq}=$seq[$a];\n	\
$hseq{$n}{com}=$com[$a];\n      }\n    return %hse\
q;\n  }\n\n\n\nsub sfold_parseoutput($$)\n{\n    m\
y ($frawout, $foutfa) = @_;\n    my %haln;\n    my\
 ($fstk, $cmd, $id);\n    open FOUTFA, \">$foutfa\\
";\n    \n    $fstk = $frawout . \".stk\";\n    \n\
    # first line of raw out contains info\n    # r\
emaining stuff is stockholm formatted\n    $cmd = \
\"sed -e '1d' $frawout\";\n    system(\"$cmd > $fs\
tk\");\n    if ($? != 0) {\n        $errmsg = \"co\
mmand failed with exit status $?.\";\n        $err\
msg .=  \"Command was \\\"$cmd\\\"\";\n        ret\
urn -1;\n    }\n\n    # this gives an error messag\
e. just ignore it...\n    %haln=read_stk_aln ( $fs\
tk);\n    foreach $i (keys (%haln))\n      {\n	my \
$s;\n	$s=$haln{$i}{'seq'};\n	$s =~ s/\\./-/g;\n	pr\
int FOUTFA \">$i\\n$s\\n\";\n      }\n    close FO\
UTFA;\n    return 0;\n}\n\n\n\n\nsub sfold_wrapper\
($$$$)\n{\n    \n    my ($fs1, $fs2, $fmodel, $fou\
tfa) = @_;\n    \n\n    my ($cmd, $frawout, $ferrl\
og, $freadme, $ftimelog, $fstk);\n\n    # add  bas\
ename($fmsqin) (unknown here!)\n    $frawout = \"s\
fold.log\";\n    $ferrlog = \"sfold.err\";\n    $f\
timelog = \"sfold.time\";\n    $freadme =  \"sfold\
.README\";\n    $fstk = \"sfold.stk\";\n    \n    \
# prepare execution...\n    #\n    # ./tmp is esse\
ntial for dswpalign\n    # otherwise you'll get a \
segfault\n    mkdir \"./tmp\";\n    \n    $cmd = \\
"sfold -m $fmodel $fs1 $fs2\";\n    open(FREADME,\\
">$freadme\");\n    print FREADME \"$cmd\\n\"; \n \
   close(FREADME);\n\n    # and go\n    #\n    sys\
tem(\"/usr/bin/time -p -o $ftimelog $cmd >$frawout\
 2>$ferrlog\");\n    if ($? != 0) {\n        $errm\
sg = \"command failed with exit status $?\";\n    \
    $errmsg .= \"command was \\\"$cmd\\\". See \" \
. getcwd . \"\\n\";\n        return -1;\n    }\n\n\
    return sfold_parseoutput($frawout, $foutfa);\n\
}\n\n\n\n\n\n\n\nmy ($help, $fmsqin, $fmsaout);\nG\
etOptions(\"help\"  => \\$help,\n           \"in=s\
\" => \\$fmsqin,\n           \"out=s\" => \\$fmsao\
ut,\n	   \"data=s\" => \\$ref_dir);\n\n\n\nif ($he\
lp) {\n    usage();\n    exit(0);\n}\nif (! define\
d($fmsqin)) {\n    usage('missing input filename')\
;\n    exit(1);\n}\nif (! defined($fmsaout)) {\n  \
  usage('missing output filename');\n    exit(1);\\
n\n}\nif (scalar(@ARGV)) {\n    usage('Unknown rem\
aining args');\n    exit(1);\n}\n\n$FMODEL = \"$re\
f_dir/mix80.mod\";\nif (! -e \"$FMODEL\") {\n    d\
ie(\"couldn't find sfold grammar model file. Expec\
ted $FMODEL\\n\");\n}\n\n\nmy %hseq=read_fasta_seq\
 ($fmsqin);\nmy $id;\n\nforeach $id (keys(%hseq))\\
n  {\n    push(@seq_array, $hseq{$id});\n  }\n\nif\
 ( scalar(@seq_array) != 2 ) {\n    die(\"Need *ex\
actly* two sequences as input (pairwise alignment!\
).\")\n}\n\n\n\nmy ($sec, $min, $hour, $mday, $mon\
, $year, $wday, $yday, $isdst) = localtime(time);\\
nmy $datei = sprintf(\"%4d-%02d-%02d\", $year+1900\
, $mon+1, $mday);\nmy $templ = basename($0) . \".\\
" . $datei . \".pid-\" . $$ . \".XXXXXX\";\nmy $wd\
 = tempdir ( $templ, DIR => $TMPDIR);\n\ncopy($fms\
qin, \"$wd/\" . basename($fmsqin) . \".org\"); # f\
or reproduction\ncopy($FMODEL, \"$wd\");\nmy $fmod\
el = basename($FMODEL);\nmy $orgwd = getcwd;\nchdi\
r $wd;\n\n\n\nmy @sepseqfiles;\nforeach $id (keys(\
%hseq)) {\n    my ($seq, $orgseq, $fname, $sout);\\
n    $seq=$hseq{$id}{'seq'};\n    \n    $fname = b\
asename($fmsqin) . \"_$id.fa\";\n    # replace fun\
nies in file/id name (e.g. \"/\" \" \" etc)\n    $\
fname =~ s,[/ ],_,g;\n    open (PF, \">$fname\");\\
n    print (PF \">$id\\n$seq\\n\");\n    close (PF\
);\n\n    push(@sepseqfiles, $fname);\n}\n\nmy ($f\
1, $f2, $fout);\n$f1 = $sepseqfiles[0];\n$f2 = $se\
pseqfiles[1];\n$fout = $wd . basename($fmsqin) . \\
".out.fa\";\nif (sfold_wrapper($f1, $f2, $fmodel, \
\"$fout\") != 0) {\n    printf STDERR \"ERROR: See\
 logs in $wd\\n\";\n    exit(1);\n} else {\n    ch\
dir $orgwd;\n    copy($fout, $fmsaout);\n    rmtre\
e($wd);\n   exit(0);\n}\n","\nuse Env qw(HOST);\nu\
se Env qw(HOME);\nuse Env qw(USER);\n\n\n$tmp=clea\
n_cr ($ARGV[0]);\nopen (F, $tmp);\n\nwhile ( <F>)\\
n  {\n    my $l=$_;\n    if ( $l=~/^# STOCKHOLM/){\
$stockholm=1;}\n    elsif ( $stockholm && $l=~/^#/\
)\n      {\n	$l=~/^#(\\S+)\\s+(\\S+)\\s+(\\S*)/g;\\
n	$l=\"_stockholmhasch_$1\\_stockholmspace_$2 $3\\\
n\";\n      }\n    $file.=$l;\n  }\nclose (F);\nun\
link($tmp);\n$file1=$file;\n\n$file=~s/\\#/_hash_s\
ymbol_/g;\n$file=~s/\\@/_arobase_symbol_/g;\n\n\n$\
file=~s/\\n[\\.:*\\s]+\\n/\\n\\n/g;\n\n$file=~s/\\\
n[ \\t\\r\\f]+(\\b)/\\n\\1/g;\n\n\n$file=~s/(\\n\\\
S+)(\\s+)(\\S)/\\1_blank_\\3/g;\n\n$file=~s/[ ]//g\
;\n$file=~s/_blank_/ /g;\n\n\n\n$file =~s/\\n\\s*\\
\n/#/g;\n\n$file.=\"#\";\n$file =~s/\\n/@/g;\n\n\n\
\n\n@blocks=split /\\#/, $file;\nshift (@blocks);\\
n@s=split /\\@/, $blocks[0];\n$nseq=$#s+1;\n\n\n\n\
$file=join '@', @blocks;\n@lines=split /\\@/,$file\
;\n\n$c=0;\n\nforeach $l (@lines)\n  {\n    if (!(\
$l=~/\\S/)){next;}\n    elsif ($stockholm && ($l=~\
/^\\/\\// || $l=~/STOCKHOLM/)){next;}#get read of \
STOCHOLM Terminator\n   \n    $l=~/(\\S+)\\s+(\\S*\
)/g;\n    $n=$1; $s=$2;\n    \n    $seq[$c].=$s;\n\
    $name[$c]=$n;\n    $c++;\n    \n    if ( $c==$\
nseq){$c=0;}\n    \n  } \n\nif ( $c!=0)\n      {\n\
	print STDERR \"ERROR: $ARGV[0] is NOT an MSA in C\
lustalw format: make sure there is no blank line w\
ithin a block [ERROR]\\n\";\n	exit (EXIT_FAILURE);\
\n      }\n\nfor ($a=0; $a< $nseq; $a++)\n  {\n   \
 $name[$a]=cleanstring ($name[$a]);\n    $seq[$a]=\
cleanstring ($seq[$a]);\n    $seq[$a]=breakstring(\
$seq[$a], 60);\n    \n    $line=\">$name[$a]\\n$se\
q[$a]\\n\";\n    \n    print \"$line\";\n  }\nexit\
 (EXIT_SUCCESS);\n\nsub cleanstring\n  {\n    my $\
s=@_[0];\n    $s=~s/_hash_symbol_/\\#/g;\n    $s=~\
s/_arobase_symbol_/\\@/g;\n    $s=~s/[ \\t]//g;\n \
   return $s;\n  }\nsub breakstring\n  {\n    my $\
s=@_[0];\n    my $size=@_[1];\n    my @list;\n    \
my $n,$ns, $symbol;\n    \n    @list=split //,$s;\\
n    $n=0;$ns=\"\";\n    foreach $symbol (@list)\n\
      {\n	if ( $n==$size)\n	  {\n	    $ns.=\"\\n\"\
;\n	    $n=0;\n	  }\n	$ns.=$symbol;\n	$n++;\n     \
 }\n    return $ns;\n    }\n\nsub clean_cr\n  {\n \
   my $f=@_[0];\n    my $file;\n    \n    $tmp=\"f\
$.$$\";\n    \n    \n    open (IN, $f);\n    open \
(OUT, \">$tmp\");\n    \n    while ( <IN>)\n      \
{\n	$file=$_;\n	$file=~s/\\r\\n/\\n/g;\n	$file=~s/\
\\n\\r/\\n/g;\n	$file=~s/\\r\\r/\\n/g;\n	$file=~s/\
\\r/\\n/g;\n	print OUT \"$file\";\n      }\n    \n\
    close (IN);\n    close (OUT);\n    return $tmp\
;\n  }\n","use strict;\nuse FileHandle;\nuse Env q\
w(HOST);\nuse Env qw(HOME);\nuse Env qw(USER);\n\n\
my $format=file2format ($ARGV[0]);\nif    ($format\
 eq \"clustalw\"){clustalw2name_seq($ARGV[0]);}\ne\
lsif ($format eq \"fasta\")   {fasta2name_seq($ARG\
V[0]);}\nelsif ($format eq \"msf\")   {msf2name_se\
q($ARGV[0]);}\nelsif ($format eq \"phylip\")   {ph\
ylip2name_seq($ARGV[0]);}\nelsif ($format eq \"nam\
eseq\") {display_file ($ARGV[0]);}\n \nexit (0);\n\
\nsub file2format\n  {\n    my $f=shift;\n    \n  \
  my $l=file2n_lines($f,2);\n    \n    if ( $l=~/^\
CLUSTAL/){return \"clustalw\";}\n    elsif ($l=~/^\
SAGA/){return \"clustalw\";}\n    elsif ($l=~/^>/)\
{return \"fasta\";}\n    elsif ($l=~/^PileUp/){ret\
urn \"msf\";}\n    elsif ($l=~/\\s+\\d+\\s+\\d+\\s\
/){return \"phylip\";}\n    elsif ($l=~/\\#NAMESEQ\
_01/){return \"nameseq\";}\n    else \n      {\n	p\
rint STDERR \"ERROR: $f FILE is NOT a supported fo\
rmat [ERROR]\\n\";\n	exit (1);\n      }\n  }\nsub \
display_file\n    {\n       my $file=shift;\n     \
  my $F= new FileHandle;\n       open ($F, $file);\
\n       while (<$F>){print \"$_\";}\n       close\
 ($F);\n     }\nsub phylip2name_seq\n    {\n      \
my $file=shift;\n      my $F= new FileHandle;\n   \
   my ($seq, $name,$seq);\n      my $query_start=-\
1;\n      my $query_end=-1;\n      my $in_aln=0;\n\
      my %list;\n      my ($first,$seq,$name, $cn,\
 $nseq, $l,%len);\n      \n      open ($F, $file);\
\n      <$F>;\n      $l=$_;\n      $l=~/\\s*(\\d+)\
\\s*(\\d+)/;\n      $first=1;\n      $cn=0;\n     \
 while (<$F>)\n	{\n	  my $l=$_;\n	  if (!($l=~/\\S\
/))\n	    {\n	      $cn=0;\n	      $first=0;\n	   \
 }\n	  elsif ($first==1)\n	    {\n	      $l=~/\\s*\
(\\S+)(.*)/;\n	      my $name=$1;\n	      my $seq=\
$2;\n	      chomp ($seq);\n	      $seq=~s/\\s//g;\\
n	      $list{$cn}{'name'}=$name;\n	      $list{$c\
n}{'seq'}.=$seq;\n	      $cn++;\n	      $nseq++;\n\
	    }\n	  else\n	    {\n	      chomp ($l);\n	    \
  $l=~s/\\s//g;\n	      $list{$cn}{'seq'}.=$l;\n	 \
     $cn++;\n	    }\n	}\n      close ($F);\n      \
\n      print \"#NAMESEQ_01\\n\";\n      print \"#\
 $nseq\\n\";\n      for (my $a=0; $a<$nseq; $a++)\\
n	{\n	  my $nl=length ($list{$a}{'name'});\n	  my \
$sl=length ($list{$a}{'seq'});\n	  print \">$nl $s\
l $list{$a}{'name'} $list{$a}{'seq'}\\n\";\n	}\n  \
  }\n      \nsub msf2name_seq\n    {\n      my $fi\
le=shift;\n      my $F= new FileHandle;\n      my \
($seq, $name,$seq);\n      my $query_start=-1;\n  \
    my $query_end=-1;\n      my $in_aln=0;\n      \
my %list;\n      my ($seq,$name, $n, $nseq, $l,%le\
n);\n      \n      open ($F, $file);\n      while \
(<$F>)\n	{\n	  if ( /\\/\\//){$in_aln=1;}\n	  elsi\
f ( $in_aln && /(\\S+)\\s+(.*)/)\n	    {\n	      $\
name=$1;\n	      $seq=$2;\n	      $seq=~s/\\s//g;\\
n	      $seq=~s/\\~/\\-/g;\n	      $seq=~s/\\./\\-\
/g;\n	      if ( $list{$n}{'name'} && $list{$n}{'n\
ame'} ne $name)\n		{\n		  print \"$list{$n}{'name'\
} Vs $name\";\n		  \n		  exit (1);\n		}\n	      el\
se\n		{\n		  $list{$n}{'name'}= $name;\n		}\n	    \
  \n	      $list{$n}{'seq'}=$list{$n}{'seq'}.$seq;\
\n	      \n	      $nseq=++$n;\n	      \n	    }\n	 \
 else\n	    {$n=0;}\n	}\n      close ($F);\n      \
print \"#NAMESEQ_01\\n\";\n      print \"# $nseq\\\
n\";\n      for (my $a=0; $a<$nseq; $a++)\n	{\n	  \
my $nl=length ($list{$a}{'name'});\n	  my $sl=leng\
th ($list{$a}{'seq'});\n	  print \">$nl $sl $list{\
$a}{'name'} $list{$a}{'seq'}\\n\";\n	}\n    }\n   \
 \nsub fasta2name_seq\n    {\n      my $file=shift\
;\n      my $F= new FileHandle;\n      my ($seq, $\
name,$n,$l,%len);\n      \n      open ($F, $file);\
\n      while (<$F>)\n	{\n	  if ( /^>(\\S+)/){$n++\
;$seq=\"\";$name=$1;}\n	  else\n	    {\n	      $l=\
$_;\n	      chomp ($l);\n	      $seq.=$l;\n	      \
$len{$name}=length($seq);\n	    }\n	}\n      close\
 ($F);\n      print \"#NAMESEQ_01\\n\";\n      pri\
nt \"# $n\";\n      \n      open ($F, $file);\n   \
   while (<$F>)\n	{\n	  if ( /^>(\\S+)(.*)\\n/)\n	\
    {\n	      my $name=$1;\n	      my $comment=$2;\
\n	      my $nl=length ($name);\n	      my $sl=$le\
n{$name};\n	      if ($comment)\n		{\n		  $comment\
=~s/^\\s+//g;\n		  my $cl=length ($comment);\n		  \
print \"\\n#$cl $comment\\n\";\n		}\n	      print \
\"\\n>$nl $sl $name \";\n	    }\n	  else\n	    {\n\
	      $l=$_;\n	      chomp ($l);\n	      print \"\
$l\";\n	    }\n	}\n      print \"\\n\";\n      clo\
se ($F);\n    }\nsub clustalw2name_seq\n  {\n    m\
y $fname=shift;\n    my ($file1, $file);\n    my (\
@blocks, @lines,@s, $n,$nseq, $c);\n    my (@name,\
 @seq);\n    my $F= new FileHandle;\n    my $stock\
holm;\n    \n    open ($F, $fname);\n    \n    whi\
le ( <$F>)\n      {\n	my $l=$_;\n	$l=clean_cr($l);\
\n	if ( $l=~/^# STOCKHOLM/){$stockholm=1;}\n	elsif\
 ( $stockholm && $l=~/^#/)\n	  {\n	    $l=~/^#(\\S\
+)\\s+(\\S+)\\s+(\\S*)/g;\n	    $l=\"_stockholmhas\
ch_$1\\_stockholmspace_$2 $3\\n\";\n	  }\n	$file.=\
$l;\n      }\n    close ($F);\n        \n    #Prot\
ect # and @\n    $file=~s/\\#/_hash_symbol_/g;\n  \
  $file=~s/\\@/_arobase_symbol_/g;\n    \n    \n  \
  #Remove annotation\n    $file=~s/\\n[\\.:*\\s]+\\
\n/\\n\\n/g;\n    \n    #Remove White spaces befor\
e the sequence name\n    $file=~s/\\n[ \\t\\r\\f]+\
(\\b)/\\n\\1/g;\n    \n    \n    #Remove Internal \
Blanks\n    $file=~s/(\\n\\S+)(\\s+)(\\S)/\\1_blan\
k_\\3/g;\n    \n    $file=~s/[ ]//g;\n    $file=~s\
/_blank_/ /g;\n    \n    \n    #Identify Double Bl\
ank lines\n    \n    $file =~s/\\n\\s*\\n/#/g;\n  \
  \n    $file.=\"#\";\n    $file =~s/\\n/@/g;\n   \
 \n    \n    \n    \n    #count nseq\n    @blocks=\
split /\\#/, $file;\n    shift (@blocks);\n    @s=\
split /\\@/, $blocks[0];\n    $nseq=$#s+1;\n    \n\
    #Merge all the sequences and split every Nseq\\
n    \n    \n    $file=join '@', @blocks;\n    @li\
nes=split /\\@/,$file;\n    \n    $c=0;\n    \n   \
 foreach my $l (@lines)\n      {\n	my ($n, $s);\n	\
\n	if (!($l=~/\\S/)){next;}\n	elsif ($stockholm &&\
 ($l=~/^\\/\\// || $l=~/STOCKHOLM/)){next;}#get re\
ad of STOCHOLM Terminator\n	\n	$l=~/(\\S+)\\s+(\\S\
*)/g;\n	$n=$1; $s=$2;\n	\n	$seq[$c].=$s;\n	$name[$\
c]=$n;\n	$c++;\n	\n	if ( $c==$nseq){$c=0;}\n	\n   \
   } \n    \n    if ( $c!=0)\n      {\n	print STDE\
RR \"ERROR: $fname is NOT an MSA in Clustalw forma\
t: make sure there is no blank line within a block\
 [ERROR]\\n\";\n	exit (1);\n      }\n    print \"#\
NAMESEQ_01\\n\";\n    print \"# $nseq\\n\";\n    f\
or (my $a=0; $a< $nseq; $a++)\n      {\n	$name[$a]\
=cleanstring ($name[$a]);\n	$seq[$a]=cleanstring (\
$seq[$a]);\n	my $ln=length ($name[$a]);\n	my $ls=l\
ength ($seq[$a]);\n	print \">$ln $ls $name[$a] $se\
q[$a]\\n\";\n      }\n  }\nsub cleanstring\n    {\\
n      my $s=@_[0];\n      $s=~s/_hash_symbol_/\\#\
/g;\n      $s=~s/_arobase_symbol_/\\@/g;\n      $s\
=~s/[ \\t]//g;\n      return $s;\n    }\n\nsub cle\
an_cr\n  {\n    my $f=shift;\n    $f=~s/\\r\\n/\\n\
/g;\n    $f=~s/\\n\\r/\\n/g;\n    $f=~s/\\r\\r/\\n\
/g;\n    $f=~s/\\r/\\n/g;\n    return $f;\n  }\n\n\
sub file2n_lines\n    {\n      my $file=shift;\n  \
    my $nl=shift;\n      my $ret;\n      my $F=new\
 FileHandle;\n      my $n=0;\n      open ($F, $fil\
e);\n\n      while (<$F>)\n	{\n	  $ret.=$_;\n	  $n\
++;\n	  \n	  if ($n>=$n){close ($F); return $ret;}\
\n	}\n      close ($F);\n      return $ret;\n    }\
\n","use strict;\nuse FileHandle;\nuse Env qw(HOST\
);\nuse Env qw(HOME);\nuse Env qw(USER);\nmy %name\
;\nmy $nseq;\nmy $fasta;\nif ($ARGV[2] eq \"-fasta\
\"){$fasta=1;}\nmy $F= new FileHandle;\n\nopen ($F\
, $ARGV[1]);\nwhile(<$F>)\n  {\n    my $l=$_;\n   \
 if ($l=~/^#/){;}\n    elsif (($l=~/\\d+\\s+\\d+\\\
s+(\\S+)\\s+(\\S+)/))\n      {\n	my $n=$1;\n	$name\
{$1}++;\n      }\n  }\nclose ($F);\n\nopen ($F, $A\
RGV[0]);\nwhile(<$F>)\n  {\n    my $l=$_;\n    if \
($l=~/^#/){;}\n    elsif ($l=~/\\d+\\s+\\d+\\s+(\\\
S+)\\s+(\\S+)/)\n      {\n	my $n=$1;\n	$name{$n}++\
;\n	if ($name{$n}==2){$nseq++;}\n      }\n  }\nclo\
se ($F);\n\nif (!$fasta && $nseq>0)\n  {\n    prin\
t \"#NAMESEQ_01\\n\";\n    print \"# $nseq\\n\";\n\
  }\nopen ($F, $ARGV[0]);\nwhile(<$F>)\n  {\n    m\
y $l=$_;\n    if ($l=~/^#/){;}\n    elsif ($l=~/.\\
\d+\\s+\\d+\\s+(\\S+)\\s+(\\S+)/)\n      {\n	my $n\
=$1;\n	my $s=$2;\n	if ($name{$n}==2)\n	  {\n	    i\
f ($fasta)\n	      {\n		print \">$n\\n$s\\n\";\n	 \
     }\n	    else\n	      {\n		print \"$l\";\n	   \
   }\n	  }\n      }\n  }\nclose ($F);\nexit (0);\n\
\n\n","use Env qw(HOST);\nuse Env qw(HOME);\nuse E\
nv qw(USER);\n\n\n$query_start=-1;\n$query_end=-1;\
\n\nwhile (<>)\n  {\n    if ( /\\/\\//){$in_aln=1;\
}\n    elsif ( $in_aln && /(\\S+)\\s+(.*)/)\n     \
 {\n\n\n	$name=$1;\n	\n\n	$seq=$2;\n	$seq=~s/\\s//\
g;\n        $seq=~s/\\~/\\-/g;\n	$seq=~s/\\./\\-/g\
;\n	if ( $list{$n}{'name'} && $list{$n}{'name'} ne\
 $name)\n	  {\n	    print \"$list{$n}{'name'} Vs $\
name\";\n	    \n	    exit (EXIT_FAILURE);\n	  }\n	\
else\n	  {\n	    $list{$n}{'name'}= $name;\n	  }\n\
\n	$list{$n}{'seq'}=$list{$n}{'seq'}.$seq;\n	\n	$n\
seq=++$n;\n	\n      }\n    else\n      {$n=0;}\n  \
}\n\n\nfor ($a=0; $a<$nseq; $a++)\n  {\n    print \
\">$list{$a}{'name'}\\n$list{$a}{'seq'}\\n\";\n  }\
\n      \n","$run_anyway=2;\nmy $msaf=\"msa.in.tmp\
.$$\";\nmy $msaoutf=\"msa.out.tmp.$$\";\nmy $err=\\
"msa.out.err.$$\";\nopen  (F, $ARGV[0]);\nopen  (O\
UT, \">$msaf\");\n$nseq=0;\nwhile (<F>)\n  {\n    \
$l=$_;\n    if ( $l=~/^>(\\S+)/)\n      {\n	$s=$se\
qname{$nseq++}=$1;\n	print OUT \"$l\";\n	\n      }\
\n    else \n      {\n	$l=uc($l);\n	print OUT \"$l\
\";\n      }\n  }\n\nclose (F);\nclose(OUT);\n\nsy\
stem (\"msa $msaf > $msaoutf 2>$err\");\nopen (F, \
\"$msaoutf\");\n$read=0;\n$cn=0;\nwhile (<F>)\n  {\
\n    $l=$_;\n    if ($read)\n      {\n	if ($l=~/E\
nd gaps not penalized/){$read=0;}\n	elsif (!($l=~/\
\\S/))\n	  {\n	    $cn=0;\n	  }\n	else\n	  {\n	   \
 \n	    chomp ($l);\n	    $seqal{$cn++}.=$l;\n	   \
 $tot++;\n	  }\n      }\n    elsif ($l=~/Optimal M\
ultiple Alignment/)\n      {\n	$read=1;\n      }\n\
  }\nclose (F);\n\nif ($tot<1 && $run_anyway==1)\n\
  {\n    print STDERR \"\\nWarning: MSA returned a\
 NULL file -- Use T-Coffee instead\\n\";\n    open\
 (F,$err);\n    while (<F>){print \"$_\";}\n      \
\n    system (\"t_coffee -seq $msaf -outfile $ARGV\
[1]  -quiet\");\n  }\nelsif ($tot<1 && $run_anyway\
==2)\n  {\n    \n    \n    $nseq/=2;\n    $nseq=in\
t ($nseq);\n    if ($nseq<2){$nseq=2;}\n    print \
\"RUN MSA with NSeq=$nseq\\n\";\n    #print (\"t_c\
offee -dpa -dpa_nseq $nseq -seq $ARGV[0] -dpa_tree\
 codnd -outfile $ARGV[1] -dpa_method msa_msa\");\n\
    system (\"t_coffee -dpa -dpa_nseq $nseq -seq $\
ARGV[0] -dpa_tree codnd -outfile $ARGV[1] -dpa_met\
hod msa_msa>/dev/null\");\n\n  }\nelsif ($tot<1)\n\
  {\n    exit (EXIT_FAILURE);\n  }\nelse\n  {\n   \
 open (OUT, \">$ARGV[1]\");\n    for ($a=0; $a<$ns\
eq;$a++)\n      {\n	print OUT \">$seqname{$a}\\n$s\
eqal{$a}\\n\";\n      }\n    close (OUT);\n  }\n\n\
\n\nunlink ($msaf);\nunlink ($msaoutf);\nunlink ($\
err);\n","use strict;\nuse Cwd;\nuse File::Basenam\
e;\nmy $test=0;\n\nmy $tmpdir=\"/tmp/tco/aligners/\
upp/\";\nmymkdir ($tmpdir);\n\n\n\nif ($ARGV[0] eq\
 \"one\")\n  {\n    seq2msa ($ARGV[1], $ARGV[2]);\\
n  }\nelsif ($ARGV[0] eq \"all\")\n  {\n    listse\
q2listmsa ($ARGV[1]);\n  }\n\nsub listseq2listmsa\\
n  {\n    my $list=shift;\n    my $cdir = getcwd;\\
n    my $dir=random_string(10);\n    $dir=\"$tmpdi\
r/$dir/\";\n    my %h;\n    my $n;\n    mkdir  ($d\
ir);\n\n    open (F, $list);\n    while (<F>)\n   \
   {\n        my $l=$_;\n\n        chomp($l);\n   \
     my @f=split (/\\s+/, $l);\n	if ( -e $f[0])\n \
         {\n            $h{$n}{in}=$f[0];\n       \
     ($h{$n}{name},$h{$n}{path})=fileparse ($f[0])\
;\n            $h{$n}{NFin}= \"$dir/$h{$n}{name}.s\
eq\";\n	    \n            $h{$n}{NFout}=\"$dir/$h{\
$n}{name}.aln\";\n\n            $h{$n}{out}=$f[1];\
\n\n            fasta2fastaupp ($h{$n}{in}, $h{$n}\
{NFin});\n            $n++;\n          }\n      }\\
n    close (F);\n    chdir ($dir);\n    \n    if (\
!$test)\n      {\n	system (\"fbname=\\$(basename `\
ls *.seq` .seq); \\\n             run_upp.py -s \\\
${fbname}.seq -m amino --cpu 1 -d outdir -o \\${fb\
name}.aln; \\\n             mv outdir/\\${fbname}.\
aln_alignment.fasta \\${fbname}.aln;\");\n      }\\
n    \n    foreach my $n (keys (%h))\n      {\n	if\
 ($test)\n	  {\n	    system (\"cp $h{$n}{NFin} $h{\
$n}{NFout}\");\n	    print \"$h{$n}{NFin} $h{$n}{N\
Fout} $h{$n}{out}\\n\";\n	  }\n        fastaupp2fa\
sta ($h{$n}{NFout},$h{$n}{out});\n      }\n    chd\
ir ($cdir);\n  }\n\nsub seq2msa\n    {\n      my (\
$in, $out)=@_;\n      my $cdir=getcwd;\n      \n  \
    \n      if (!($in=~/\\//)){$in=$cdir.\"/\".$in\
;}\n      if (!($out=~/\\//)){$out=$cdir.\"/\".$ou\
t;}\n      \n      my $file=random_string(10);\n  \
    $file=\"$tmpdir/$file\";\n      open (F, \">$f\
ile\");\n      print F \"$in $out\\n\";\n      clo\
se (F);\n      \n      return listseq2listmsa ($fi\
le);\n    }\n	\nsub fasta2fastaupp\n  {\n    my ($\
in, $out)=@_;\n    my ($name, $seq, $n);\n    \n  \
  if (!-e $in){return;}\n    \n    open (IN, \"$in\
\");\n    open (OUT, \">$out\");\n    local $/ = \\
"\\n>\";  # read by FASTA record\n    \n    while \
(<IN>)\n      {\n	my $l=$_;\n	$l=~s/>//g;\n	$l=\">\
\".$l;\n	\n	$l=~/^>(.*)/;\n	$name=$1;\n	\n	$l=~s/^\
>*.+\\n//;\n	$l=~s/\\n//g;\n	$seq=$l;\n	\n	$seq=~s\
/u/x/g;\n	$seq=~s/U/X/g;\n	print OUT \">$name\\n$s\
eq\\n\";\n	$n++;\n      }\n    if ($n==2)\n      {\
\n	print OUT \">fake_seq4upp\\n$seq\\n\";\n      }\
\n    close (IN);\n    close (OUT);\n    local $/=\
\"\\n\";\n  }\n\nsub fastaupp2fasta\n  {\n    my (\
$in, $out)=@_;\n    my ($name, $seq, $n);\n    \n \
   if (!-e $in){return;}\n    \n    open (IN, \"$i\
n\");\n    open (OUT, \">$out\");\n    local $/ = \
\"\\n>\";  # read by FASTA record\n    \n    while\
 (<IN>)\n      {\n	my $l=$_;\n	$l=~s/>//g;\n	$l=\"\
>\".$l;\n	\n	$l=~/^>(.*)/;\n	$name=$1;\n	\n	$l=~s/\
^>*.+\\n//;\n	$l=~s/\\n//g;\n	$seq=$l;\n	\n	$seq=~\
s/x/u/g;\n	$seq=~s/X/U/g;\n	\n	if (!($name=~/fake_\
seq4upp/))\n	  {\n	    print OUT \">$name\\n$seq\\\
n\";\n	  }\n      }\n    close (IN);\n    close (O\
UT);\n    local $/=\"\\n\";\n  }\n\nsub random_str\
ing\n    {\n      my $len=shift;\n      my @chars \
= (\"A\"..\"Z\", \"a\"..\"z\");\n      my $string;\
\n      $string .= $chars[rand @chars] for 1..$len\
;\n      return $string;\n    }\n\nsub mymkdir\n  \
    {\n	my $d=shift;\n	my $cd='/';\n	\n	foreach my\
 $e (split (/\\//, $d))\n	  {\n	    $cd.=\"$e/\";\\
n	    if ( !-d $cd){mkdir ($cd);}\n	  }\n	return;\\
n      }\n      \n			  \n      \n","use strict;\nu\
se Cwd;\nuse File::Basename;\n\n\nmy $tmpdir=\"/tm\
p/tco/aligners/clustalo/\";\nmymkdir ($tmpdir);\n\\
n\n\nif ($ARGV[0] eq \"one\")\n  {\n    seq2msa ($\
ARGV[1], $ARGV[2]);\n  }\nelsif ($ARGV[0] eq \"all\
\")\n  {\n    listseq2listmsa ($ARGV[1]);\n  }\n\n\
\n\nsub listseq2listmsa\n  {\n    my $list=shift;\\
n    my $cdir = getcwd;\n    my $dir=random_string\
(10);\n    $dir=\"$tmpdir/$dir/\";\n    my %h;\n  \
  my $n;\n    mkdir  ($dir);\n    \n    open (F, $\
list);\n    while (<F>)\n      {\n	my $l=$_;\n\n	c\
homp($l);\n	my @f=split (/\\s+/, $l);\n	#print \"$\
l: 0:$f[0], 1:$f[1]\\n\";\n	if ( -e $f[0])\n	  {\n\
	    $h{$n}{in}=$f[0];\n	    ($h{$n}{name},$h{$n}{\
path})=fileparse ($f[0]);\n	    $h{$n}{NFin}= \"$d\
ir/$h{$n}{name}.seq4nf\";\n	    $h{$n}{NFout}=\"$d\
ir/$h{$n}{name}.aln\";\n	    \n	    $h{$n}{out}=$f\
[1];\n	    \n	    translate_fasta_seq (\"uU\", \"X\
\",$h{$n}{in}, $h{$n}{NFin});\n	    $n++;\n	  }\n \
     }\n    close (F);\n    \n    \n    chdir ($di\
r);\n    dump_nf (\"nf\");\n    dump_config ();\n \
  \n    #system (\"nextflow run nf  --name \\'*.se\
q4nf\\' >/dev/null 2>/dev/null\");\n    system (\"\
nextflow run nf  --name \\'*.seq4nf\\'\");\n    fo\
reach my $n (keys (%h))\n      {\n	translate_fasta\
_seq (\"uU\", \"X\",$h{$n}{NFout},$h{$n}{out});\n \
     }\n    chdir ($cdir);\n  }\nsub seq2msa\n    \
{\n      my ($in, $out)=@_;\n      my $cdir=getcwd\
;\n      \n      \n      if (!($in=~/\\//)){$in=$c\
dir.\"/\".$in;}\n      if (!($out=~/\\//)){$out=$c\
dir.\"/\".$out;}\n      \n      my $file=random_st\
ring(10);\n      $file=\"$tmpdir/$file\";\n      o\
pen (F, \">$file\");\n      print F \"$in $out\\n\\
";\n      close (F);\n      \n      return listseq\
2listmsa ($file);\n    }\n	\nsub seq2msa_old\n  {\\
n    my ($in, $out)=@_;\n    my $cdir = getcwd;\n \
   my $dir=random_string(10);\n    $dir=\"/tmp/upp\
.nf4tcoffee/$dir\";\n    my $seq=random_string(10)\
;\n    $seq.=\".fa\";\n    my $aln=$seq;\n    $aln\
.=\".aln\";\n    \n    mkdir ($dir);\n    translat\
e_fasta_seq (\"uU\", \"X\",$in, \"$dir/$seq\");\n \
   chdir ($dir);\n    \n    dump_nf (\"nf\");\n   \
 dump_config ();\n    print \"IN: $in OUT: $cdir/$\
out\\nDIR: $dir\\nnextflow run nf  --name \\'*.fa\\
\' \\n\";\n    system (\"nextflow run nf  --name \\
\'*.fa\\' \");\n    print \"$dir/$aln $cdir/$out\\\
n\";\n    translate_fasta_seq (\"xX\", \"U\",$aln,\
 \"$cdir/$out\");\n    chdir ($cdir);\n   } \nsub \
translate_fasta_seq\n  {\n    my ($from, $to, $in,\
 $out)=@_;\n    my $n;\n    my $skip;\n    my $l;\\
n    my $cseq;\n    if (!-e $in){return;}\n    \n \
   open (IN, \"$in\");\n    open (OUT, \">$out\");\
\n   \n    while (<IN>)\n      {\n	$l=$_;\n	if ($l\
=~\">\"){$n++;$cseq=\"\";}\n	else { $l=~s/[$from]/\
$to/;$cseq.=$l;}\n\n	if ($skip){$skip=0;}\n	elsif \
($l=~/>fake_seq/){$skip=1;}\n	else\n	  {\n	    pri\
nt OUT \"$l\";\n	  }\n      }\n    if ($n==2 && $f\
rom eq \"uU\")\n      {\n	print OUT \">fake_seq\\n\
$cseq\\n\";\n      }\n    close (IN);\n    close (\
OUT);\n  }\n\nsub dump_config\n    {\n      open (\
F, \">nextflow.config\");\n\n      print F \"docke\
r.enabled = true\\n\";\n      print F \"process.co\
ntainer = \\'cbcrg/benchfam_large_scale\\'\\n\";\n\
      close (F);\n    }\n\nsub dump_nf\n  {\n    m\
y $nff=shift;\n    open (F,\">$nff\");\n    print \
F \"#!/usr/bin/env nextflow\\n\";\n    print F \"p\
arams.base_dir=\\\"./\\\"\\n\";\n    print F \"par\
ams.out_dir=\\\"./\\\"\\n\";\n    print F \"Channe\
l.fromPath(params.name)\\n\";\n    print F \"\\t.m\
ap{ tuple(it.baseName, it) }\\n\";\n    \n    prin\
t F \"\\t.set{ file_names_1 }\\n\";\n    print F \\
"process clustalo_align{\\n\";\n    print F \"\\tp\
ublishDir params.out_dir, mode: \\\"copy\\\"\\n\";\
\n    print F \"tag \\\"\\${name}\\\"\";\n    prin\
t F \"\\n\";\n    print F \"\\tinput:\\n\";\n    p\
rint F \"\\tset name, file(seq_file) from file_nam\
es_1\\n\";\n    print F \"\\toutput:\\n\";\n    pr\
int F \"\\tfile \\\"\\${name}.aln\\\"\\n\";\n    p\
rint F \"\\n\";\n    print F \" \\\"\\\"\\\"\\n\";\
\n    print F \" clustalo -i \\$seq_file -o \\${na\
me}.aln\\n\";\n    print F \"\\\"\\\"\\\"\\n\\n\";\
\n    print F \"}\\n\";\n    close (F);\n  }\n\nsu\
b random_string\n    {\n      my $len=shift;\n    \
  my @chars = (\"A\"..\"Z\", \"a\"..\"z\");\n     \
 my $string;\n      $string .= $chars[rand @chars]\
 for 1..$len;\n      return $string;\n    }\n\nsub\
 mymkdir\n      {\n	my $d=shift;\n	my $cd='/';\n	\\
n	foreach my $e (split (/\\//, $d))\n	  {\n	    $c\
d.=\"$e/\";\n	    if ( !-d $cd){mkdir ($cd);}\n	  \
}\n	return;\n      }\n      \n			  \n      \n","\n\
my $msaf=\"msa.in.tmp.$$\";\nmy $msaoutf=\"msa.out\
.tmp.$$\";\nmy $cost=\"blosum62.tmp.$$\";\n\nopen \
 (F, $ARGV[0]);\nopen  (OUT, \">$msaf\");\n$nseq=0\
;\nwhile (<F>)\n  {\n    $l=$_;\n    if ( $l=~/^>(\
\\S+)/)\n      {\n	my $simple=\"Seq$nseq\";\n	$s=$\
seqname{$nseq++}=$1;\n	$translate{$simple}=$s;\n	\\
n	print OUT \">$simple\\n\";\n	\n      }\n    else\
\n      {\n	$l=uc($l);\n	print OUT \"$l\";\n      \
}\n  }\nclose (F);\nclose(OUT);\n\ndump_blosum ($c\
ost);\nsystem (\"dca -c $cost -q $msaf> $msaoutf 2\
>/dev/null\");\nopen (F, \"$msaoutf\");\nopen (OUT\
, \">$ARGV[1]\");\n\n$read=0;\nwhile (<F>)\n  {\n \
   $l=$_;\n    if ($l=~/^>(\\S+)/)\n      {\n	$rea\
d=1;\n	$name=$translate{$1};\n	print OUT \">$name\\
\n\";\n      }\n    elsif ($read && ($l=~/\\S/))\n\
      {\n	print OUT \"$l\";\n      }\n    else\n  \
    {\n	$read=0;\n      }\n  }\nclose (F);\n\nunli\
nk ($cost);\nunlink ($msaf);\nunlink ($msaoutf);\n\
\nsub dump_blosum\n  {\n    my $f=shift;\n    open\
 (F, \">$f\");\n\n    print F \"6\\n\";\n    print\
 F \"- -   0\\n\";\n    print F \"W W   0\\n\";\n \
   print F \"Y Y   4\\n\";\n    print F \"F F   5\\
\n\";\n    print F \"V V   7\\n\";\n    print F \"\
L L   7\\n\";\n    print F \"I I   7\\n\";\n    pr\
int F \"M M   6\\n\";\n    print F \"K K   6\\n\";\
\nprint F \"R R   6\\n\";\n    print F \"H H   3\\\
n\";\n    print F \"Q Q   6\\n\";\n    print F \"E\
 E   6\\n\";\n    print F \"D D   5\\n\";\n    pri\
nt F \"N N   5\\n\";\n    print F \"G G   5\\n\";\\
n    print F \"A A   7\\n\";\n    print F \"P P   \
4\\n\";\n    print F \"T T   6\\n\";\n    print F \
\"S S   7\\n\";\n    print F \"C C   2\\n\";\n    \
print F \"- C  10 \\n\";\n    print F \"- S  10\\n\
\";\n    print F \"- T  10 \\n\";\n    print F \"-\
 P  10\\n\";\n    print F \"- A  10 \\n\";\n    pr\
int F \"- G  10\\n\";\n    print F \"- N  10 \\n\"\
;\n    print F \"- D  10\\n\";\n    print F \"- E \
 10 \\n\";\n    print F \"- Q  10\\n\";\nprint F \\
"- H  10 \\n\";\n    print F \"- R  10\\n\";\n    \
print F \"- K  10 \\n\";\n    print F \"- M  10\\n\
\";\n    print F \"- I  10 \\n\";\n    print F \"-\
 L  10\\n\";\n    print F \"- V  10 \\n\";\n    pr\
int F \"- F  10\\n\";\n    print F \"- Y  10 \\n\"\
;\n    print F \"- W  10\\n\";\n    print F \"W C \
 13 \\n\";\n    print F \"W S  14\\n\";\n    print\
 F \"W T  13 \\n\";\n    print F \"W P  15\\n\";\n\
    print F \"W A  14 \\n\";\n    print F \"W G  1\
3\\n\";\n    print F \"W N  15 \\n\";\n    print F\
 \"W D  15\\n\";\n    print F \"W E  14 \\n\";\n  \
  print F \"W Q  13\\n\";\n    print F \"W H  13 \\
\n\";\n    print F \"W R  14\\n\";\n    print F \"\
W K  14 \\n\";\n    print F \"W M  12\\n\";\n    p\
rint F \"W I  14 \\n\";\n    print F \"W L  13\\n\\
";\n    print F \"W V  14 \\n\";\n    print F \"W \
F  10\\n\";\n    print F \"W Y   9 \\n\";\n    pri\
nt F \"Y C  13\\n\";\n    print F \"Y S  13 \\n\";\
\n    print F \"Y T  13\\n\";\n    print F \"Y P  \
14 \\n\";\n    print F \"Y A  13\\n\";\n    print \
F \"Y G  14 \\n\";\n    print F \"Y N  13\\n\";\n \
   print F \"Y D  14 \\n\";\n    print F \"Y E  13\
\\n\";\n    print F \"Y Q  12 \\n\";\n    print F \
\"Y H   9\\n\";\n    print F \"Y R  13 \\n\";\n   \
 print F \"Y K  13\\n\";\n    print F \"Y M  12 \\\
n\";\n    print F \"Y I  12\\n\";\n    print F \"Y\
 L  12 \\n\";\n    print F \"Y V  12\\n\";\n    pr\
int F \"Y F   8 \\n\";\n    print F \"F C  13\\n\"\
;\nprint F \"F S  13 \\n\";\n    print F \"F T  13\
\\n\";\n    print F \"F P  15 \\n\";\n    print F \
\"F A  13\\n\";\n    print F \"F G  14 \\n\";\n   \
 print F \"F N  14\\n\";\n    print F \"F D  14 \\\
n\";\n    print F \"F E  14\\n\";\n    print F \"F\
 Q  14 \\n\";\n    print F \"F H  12\\n\";\n    pr\
int F \"F R  14 \\n\";\n    print F \"F K  14\\n\"\
;\n    print F \"F M  11 \\n\";\n    print F \"F I\
  11\\n\";\n    print F \"F L  11 \\n\";\n    prin\
t F \"F V  12\\n\";\n    print F \"V C  12 \\n\";\\
n    print F \"V S  13\\n\";\n    print F \"V T  1\
1 \\n\";\n    print F \"V P  13\\n\";\n    print F\
 \"V A  11 \\n\";\n    print F \"V G  14\\n\";\n  \
  print F \"V N  14 \\n\";\n    print F \"V D  14\\
\n\";\nprint F \"V E  13 \\n\";\nprint F \"V Q  13\
\\n\";\nprint F \"V H  14 \\n\";\nprint F \"V R  1\
4\\n\";\nprint F \"V K  13 \\n\";\nprint F \"V M  \
10\\n\";\nprint F \"V I   8 \\n\";\nprint F \"V L \
 10\\n\";\nprint F \"L C  12 \\n\";\nprint F \"L S\
  13\\n\";\nprint F \"L T  12 \\n\";\nprint F \"L \
P  14\\n\";\nprint F \"L A  12 \\n\";\nprint F \"L\
 G  15\\n\";\nprint F \"L N  14 \\n\";\nprint F \"\
L D  15\\n\";\nprint F \"L E  14 \\n\";\nprint F \\
"L Q  13\\n\";\nprint F \"L H  14 \\n\";\nprint F \
\"L R  13\\n\";\nprint F \"L K  13 \\n\";\nprint F\
 \"L M   9\\n\";\nprint F \"L I   9 \\n\";\nprint \
F \"I C  12\\n\";\nprint F \"I S  13 \\n\";\nprint\
 F \"I T  12\\n\";\nprint F \"I P  14 \\n\";\nprin\
t F \"I A  12\\n\";\nprint F \"I G  15 \\n\";\npri\
nt F \"I N  14\\n\";\nprint F \"I D  14 \\n\";\npr\
int F \"I E  14\\n\";\nprint F \"I Q  14 \\n\";\np\
rint F \"I H  14\\n\";\nprint F \"I R  14 \\n\";\n\
print F \"I K  14\\n\";\nprint F \"I M  10 \\n\";\\
nprint F \"M C  12\\n\";\nprint F \"M S  12 \\n\";\
\nprint F \"M T  12\\n\";\nprint F \"M P  13 \\n\"\
;\nprint F \"M A  12\\n\";\nprint F \"M G  14 \\n\\
";\nprint F \"M N  13\\n\";\nprint F \"M D  14 \\n\
\";\nprint F \"M E  13\\n\";\nprint F \"M Q  11 \\\
n\";\nprint F \"M H  13\\n\";\nprint F \"M R  12 \\
\n\";\nprint F \"M K  12\\n\";\nprint F \"K C  14 \
\\n\";\nprint F \"K S  11\\n\";\nprint F \"K T  12\
 \\n\";\nprint F \"K P  12\\n\";\nprint F \"K A  1\
2 \\n\";\nprint F \"K G  13\\n\";\nprint F \"K N  \
11 \\n\";\nprint F \"K D  12\\n\";\nprint F \"K E \
 10 \\n\";\nprint F \"K Q  10\\n\";\nprint F \"K H\
  12 \\n\";\nprint F \"K R   9\\n\";\nprint F \"R \
C  14 \\n\";\nprint F \"R S  12\\n\";\nprint F \"R\
 T  12 \\n\";\nprint F \"R P  13\\n\";\nprint F \"\
R A  12 \\n\";\nprint F \"R G  13\\n\";\nprint F \\
"R N  11 \\n\";\nprint F \"R D  13\\n\";\nprint F \
\"R E  11 \\n\";\nprint F \"R Q  10\\n\";\nprint F\
 \"R H  11 \\n\";\nprint F \"H C  14\\n\";\nprint \
F \"H S  12 \\n\";\nprint F \"H T  13\\n\";\nprint\
 F \"H P  13 \\n\";\nprint F \"H A  13\\n\";\nprin\
t F \"H G  13 \\n\";\nprint F \"H N  10\\n\";\npri\
nt F \"H D  12 \\n\";\nprint F \"H E  11\\n\";\npr\
int F \"H Q  11 \\n\";\nprint F \"Q C  14\\n\";\np\
rint F \"Q S  11 \\n\";\nprint F \"Q T  12\\n\";\n\
print F \"Q P  12 \\n\";\nprint F \"Q A  12\\n\";\\
nprint F \"Q G  13 \\n\";\nprint F \"Q N  11\\n\";\
\nprint F \"Q D  11 \\n\";\nprint F \"Q E   9\\n\"\
;\nprint F \"E C  15 \\n\";\nprint F \"E S  11\\n\\
";\nprint F \"E T  12 \\n\";\nprint F \"E P  12\\n\
\";\nprint F \"E A  12 \\n\";\nprint F \"E G  13\\\
n\";\nprint F \"E N  11 \\n\";\nprint F \"E D   9\\
\n\";\nprint F \"D C  14 \\n\";\nprint F \"D S  11\
\\n\";\nprint F \"D T  12 \\n\";\nprint F \"D P  1\
2\\n\";\nprint F \"D A  13 \\n\";\nprint F \"D G  \
12\\n\";\nprint F \"D N  10 \\n\";\nprint F \"N C \
 14\\n\";\nprint F \"N S  10 \\n\";\nprint F \"N T\
  11\\n\";\nprint F \"N P  13 \\n\";\nprint F \"N \
A  13\\n\";\nprint F \"N G  11 \\n\";\nprint F \"G\
 C  14\\n\";\nprint F \"G S  11 \\n\";\nprint F \"\
G T  13\\n\";\nprint F \"G P  13 \\n\";\nprint F \\
"G A  11\\n\";\nprint F \"A C  11 \\n\";\nprint F \
\"A S  10\\n\";\nprint F \"A T  11 \\n\";\nprint F\
 \"A P  12\\n\";\nprint F \"P C  14 \\n\";\nprint \
F \"P S  12\\n\";\nprint F \"P T  12 \\n\";\nprint\
 F \"T C  12\\n\";\nprint F \"T S  10 \\n\";\nprin\
t F \"S C  12\\n\";\nclose (F);\n    return;\n  }\\
n    \n","\nuse Env qw(HOST);\nuse Env qw(HOME);\n\
use Env qw(USER);\n\n                             \
                           \nuse strict;          \
                                   \nuse warnings;\
\nuse diagnostics;\n\nmy $in_hit_list, my $in_aln=\
0, my(%name_list)=(),my (%list)=(),my $n_seq=0; my\
 $test=0;\nmy($j)=0, my $n=0, my $nom, my $lg_quer\
y, my %vu=();\n\nopen (F, \">tmp\");\n\n$/=\"\\n\"\
;\nwhile (<>)\n{\n    print F $_;\n    if($_ =~ /Q\
uery=\\s*(.+?)\\s/i) { $nom=$1;}\n\n    if ( /Sequ\
ences producing significant alignments/){$in_hit_l\
ist=1;}\n    \n    if ($_=~ /^pdb\\|/i) { $_=~ s/p\
db\\|//g; }\n    if ($_=~ /^(1_\\d+)\\s+\\d+/) { $\
_=~ s/$1/QUERY/;}\n      \n    if ( /^(\\S+).+?\\s\
+[\\d.]+\\s+([\\de.-]+)\\s+$/ && $in_hit_list)	\n \
   {\n	my($id)=$1; # \n	$id=~ s/\\|/_/g; #\n	if ($\
id =~ /.+_$/) { chop($id) }; #\n	$name_list{$n_seq\
++}=$id;\n	$name_list{$n_seq-1}=~ s/.*\\|//g;     \
\n    }\n  \n    if (/query/i) {$in_aln=1;}\n    i\
f ( /^(\\S+)\\s+(\\d+)\\s+([a-zA-Z-]+)\\s+(\\d+)/ \
|| /^(\\S+)(\\s+)(\\-+)(\\s+)/ && ($in_aln == 1))\\
n    {\n	my $name=$1;\n	my $start=$2;\n	my $seq=$3\
;\n	my $end=$4;\n		\n	if ($name =~ /QUERY/i) { $lg\
_query=length($seq); }\n\n	unless ($test > $n) #m\\
n	{\n	    my(@seqq)= split('',$seq);\n	    my($gap\
_missing)= scalar(@seqq);\n	    \n	    while ($gap\
_missing != $lg_query)  { unshift (@seqq,\"-\"); $\
gap_missing= scalar(@seqq); }\n	    $seq=join('',@\
seqq);  #m\n	}\n	\n	if ($name =~ /QUERY/i)\n	{\n	 \
   $n=0; %vu=(); $j=0;\n	    $list{$n}{'real_name'\
}=\"$nom\";\n	}	\n	else\n	{\n	    unless (exists $\
vu{$name}) { ++$j;}	\n	    $list{$n}{'real_name'}=\
$name_list{$j-1};\n	}\n		\n	$list{$n}{'name'}=$nam\
e;\n\n	$seq=~tr/a-z/A-Z/;\n	$list{$n}{'seq'}=$list\
{$n}{'seq'};\n	$list{$n}{'seq'}.=$seq;\n\n	$n++;\n\
	$vu{$name}++;\n	$test++;\n   } \n    \n}\n\nmy @n\
umero=();\n\nfor (my $a=0; $a<$n; $a++) #m\n{\n   \
 my $long=length($list{0}{'seq'});  \n    my $long\
1= length($list{$a}{'seq'});\n  \n    while ($long\
1 ne $long)\n    {\n	$list{$a}{'seq'}.=\"-\";\n	$l\
ong1= length ($list{$a}{'seq'});\n    } \n \n    p\
ush (@numero,\"$list{$a}{'name'} $list{$a}{'real_n\
ame'}\\n\");\n}\n\nmy %dejavu=();\n\n\nfor (my $i=\
0; $i<=$#numero; $i++)\n{\n    my $s=\">$list{$i}{\
'real_name'}\\n$list{$i}{'seq'}\\n\";\n    my $k=0\
;\n    \n    if (exists $dejavu{$numero[$i]}) {nex\
t;}\n    else\n    {	\n	for ($j=0; $j<$n ; $j++)\n\
	{\n	    if (\"$numero[$i]\" eq \"$numero[$j]\" &&\
 $j != $i )\n	    {\n		++$k;\n		$s .=\">$list{$j}{\
'real_name'}\\n$list{$j}{'seq'}\\n\";\n	    }\n	}	\
\n    }\n    \n    if ($k>0) \n    {\n	my $cons;\n\
	open (SOR,\">tempo_aln2cons\"); print SOR $s;  cl\
ose SOR ;\n	open (COM,\"t_coffee -other_pg seq_ref\
ormat -in tempo_aln2cons -action +aln2cons +upper \
|\") ; \n     	while (<COM>)\n	{	\n	    if (/^>/) \
{ $cons =\">$list{$i}{'real_name'}\\n\"; next;}\n	\
    $_=~ s/\\n//g;\n	    $cons .=$_;\n	}\n	close C\
OM; unlink (\"tempo_aln2cons\");\n	print $cons,\"\\
\n\"; print F $cons,\"\\n\";\n    }	\n    else  { \
print $s;  print F $s; }\n    \n    $dejavu{$numer\
o[$i]}++;\n} #m\n\nexit;\n\n\n\n\n\n\n\n\n\n\n\n",\
"use Env;\n\n\n$tmp_dir=\"\";\n$init_dir=\"\";\n$p\
rogram=\"tc_generic_method.pl\";\n\n$blast=@ARGV[0\
];\n\n$name=\"query\";$seq=\"\";\n%p=blast_xml2pro\
file($name,$seq,100, 0, 0, $blast);\n&output_profi\
le (%p);\n\n\nsub output_profile\n  {\n    my (%pr\
ofile)=(@_);\n    my ($a);\n    for ($a=0; $a<$pro\
file{n}; $a++)\n      {\n	\n	print \">$profile{$a}\
{name} $profile{$a}{comment}\\n$profile{$a}{seq}\\\
n\";\n      }\n    return;\n  }\nsub file_contains\
 \n  {\n    my ($file, $tag, $max)=(@_);\n    my (\
$n);\n    $n=0;\n    \n    if ( !-e $file && ($fil\
e =~/$tag/)) {return 1;}\n    elsif ( !-e $file){r\
eturn 0;}\n    else \n      {\n	open (FC, \"$file\\
");\n	while ( <FC>)\n	  {\n	    if ( ($_=~/$tag/))\
\n	      {\n		close (FC);\n		return 1;\n	      }\n\
	    elsif ($max && $n>$max)\n	      {\n		close (F\
C);\n		return 0;\n	      }\n	    $n++;\n	  }\n    \
  }\n    close (FC);\n    return 0;\n  }\n	    \n	\
  \nsub file2string\n  {\n    my $f=@_[0];\n    my\
 $string, $l;\n    open (F,\"$f\");\n    while (<F\
>)\n      {\n\n	$l=$_;\n	#chomp ($l);\n	$string.=$\
l;\n      }\n    close (F);\n    $string=~s/\\r\\n\
//g;\n    $string=~s/\\n//g;\n    return $string;\\
n  }\n\n\n\nsub tag2value \n  {\n    \n    my $tag\
=(@_[0]);\n    my $word=(@_[1]);\n    my $return;\\
n    \n    $tag=~/$word=\"([^\"]+)\"/;\n    $retur\
n=$1;\n    return $return;\n  }\n      \nsub hit_t\
ag2pdbid\n  {\n    my $tag=(@_[0]);\n    my $pdbid\
;\n       \n    $tag=~/id=\"(\\S+)\"/;\n    $pdbid\
=$1;\n    $pdbid=~s/_//;\n    return $pdbid;\n  }\\
nsub id2pdbid \n  {\n    my $id=@_[0];\n  \n    if\
 ($id =~/pdb/)\n      {\n	$id=~/pdb(.*)/;\n	$id=$1\
;\n      }\n    $id=~s/[|¦_]//g;\n    return $id;\\
n  }\nsub set_blast_type \n  {\n    my $file =@_[0\
];\n    if (&file_contains ($file,\"EBIApplication\
Result\",100)){$BLAST_TYPE=\"EBI\";}\n    elsif (&\
file_contains ($file,\"NCBI_BlastOutput\",100)) {$\
BLAST_TYPE=\"NCBI\";}\n    else\n      {\n	$BLAST_\
TYPE=\"\";\n      }\n    return $BLAST_TYPE;\n  }\\
nsub blast_xml2profile \n  {\n    my ($name,$seq,$\
maxid, $minid, $mincov, $file)=(@_);\n    my (%p, \
$a, $string, $n);\n    \n\n\n    if ($BLAST_TYPE e\
q \"EBI\" || &file_contains ($file,\"EBIApplicatio\
nResult\",100)){%p=ebi_blast_xml2profile(@_);}\n  \
  elsif ($BLAST_TYPE eq \"NCBI\" || &file_contains\
 ($file,\"NCBI_BlastOutput\",100)){%p=ncbi_blast_x\
ml2profile(@_);}\n    else \n      {\n	print \"***\
********* ERROR: Blast Returned an unknown XML For\
mat **********************\";\n	die;\n      }\n   \
 for ($a=0; $a<$p{n}; $a++)\n      {\n	my $name=$p\
{$a}{name};\n	$p{$name}{seq}=$p{$a}{seq};\n      }\
\n    return %p;\n  }\nsub ncbi_blast_xml2profile \
\n  {\n    my ($name,$seq,$maxid, $minid, $mincov,\
 $string)=(@_);\n    my ($L,$l, $a,$b,$c,$d,$nhits\
,@identifyerL);\n    \n    \n    $seq=~s/[^a-zA-Z]\
//g;\n    $L=length ($seq);\n    \n    %hit=&xml2t\
ag_list ($string, \"Hit\");\n    \n    \n    for (\
$nhits=0,$a=0; $a<$hit{n}; $a++)\n      {\n	my ($l\
db,$id, $identity, $expectation, $start, $end, $co\
verage, $r);\n	my (%ID,%DE,%HSP);\n	\n	$ldb=\"\";\\
n\n	%ID=&xml2tag_list ($hit{$a}{body}, \"Hit_id\")\
;\n	$identifyer=$ID{0}{body};\n	\n	%DE=&xml2tag_li\
st ($hit{$a}{body}, \"Hit_def\");\n	$definition=$D\
E{0}{body};\n	\n	%HSP=&xml2tag_list ($hit{$a}{body\
}, \"Hsp\");\n	for ($b=0; $b<$HSP{n}; $b++)\n	  {\\
n	    my (%START,%END,%E,%I,%Q,%M);\n\n	 \n	    %S\
TART=&xml2tag_list ($HSP{$b}{body}, \"Hsp_query-fr\
om\");\n	    %HSTART=&xml2tag_list ($HSP{$b}{body}\
, \"Hsp_hit-from\");\n	    \n	    %LEN=  &xml2tag_\
list ($HSP{$b}{body}, \"Hsp_align-len\");\n	    %E\
ND=  &xml2tag_list ($HSP{$b}{body}, \"Hsp_query-to\
\");\n	    %HEND=  &xml2tag_list ($HSP{$b}{body}, \
\"Hsp_hit-to\");\n	    %E=&xml2tag_list     ($HSP{\
$b}{body}, \"Hsp_evalue\");\n	    %I=&xml2tag_list\
     ($HSP{$b}{body}, \"Hsp_identity\");\n	    %Q=\
&xml2tag_list     ($HSP{$b}{body}, \"Hsp_qseq\");\\
n	    %M=&xml2tag_list     ($HSP{$b}{body}, \"Hsp_\
hseq\");\n	    \n	    for ($e=0; $e<$Q{n}; $e++)\n\
\n	      {\n		$qs=$Q{$e}{body};\n		$ms=$M{$e}{body\
};\n		if ($seq eq\"\"){$seq=$qs;$L=length($seq);}\\
n		\n		$expectation=$E{$e}{body};\n		$identity=($L\
EN{$e}{body}==0)?0:$I{$e}{body}/$LEN{$e}{body}*100\
;\n		$start=$START{$e}{body};\n		$end=$END{$e}{bod\
y};\n		$Hstart=$HSTART{$e}{body};\n		$Hend=$HEND{$\
e}{body};\n	\n		$coverage=(($end-$start)*100)/$L;\\
n\n	\n		if ($identity>$maxid || $identity<$minid |\
| $coverage<$mincov){next;}\n		@lr1=(split (//,$qs\
));\n		@lr2=(split (//,$ms));\n		$l=$#lr1+1;\n		fo\
r ($c=0;$c<$L;$c++){$p[$nhits][$c]=\"-\";}\n		for \
($d=0,$c=0; $c<$l; $c++)\n		  {\n		    $r=$lr1[$c]\
;\n		    if ( $r=~/[A-Za-z]/)\n		      {\n			\n			\
$p[$nhits][$d + $start-1]=$lr2[$c];\n			$d++;\n		 \
     }\n		  }\n		$Qseq[$nhits]=$qs;\n		$Hseq[$nhit\
s]=$ms;\n		$QstartL[$nhits]=$start;\n		$HstartL[$n\
hits]=$Hstart;\n		$identityL[$nhits]=$identity;\n	\
	$endL[$nhits]=$end;\n		$definitionL[$nhits]=$defi\
nition;\n		$identifyerL[$nhits]=$identifyer;\n		$c\
omment[$nhits]=\"$ldb|$identifyer [Eval=$expectati\
on][id=$identity%][start=$Hstart end=$Hend]\";\n		\
$nhits++;\n	      }\n	  }\n      }\n    \n    $pro\
file{n}=0;\n    $profile{$profile{n}}{name}=$name;\
\n    $profile{$profile{n}}{seq}=$seq;\n    $profi\
le {n}++;\n    \n    for ($a=0; $a<$nhits; $a++)\n\
      {\n	$n=$a+1;\n	\n	$profile{$n}{name}=\"$name\
\\_$a\";\n	$profile{$n}{seq}=\"\";\n	$profile{$n}{\
Qseq}=$Qseq[$a];\n	$profile{$n}{Hseq}=$Hseq[$a];\n\
	$profile{$n}{Qstart}=$QstartL[$a];\n	$profile{$n}\
{Hstart}=$HstartL[$a];\n	$profile{$n}{identity}=$i\
dentityL[$a];\n	$profile{$n}{definition}=$definiti\
onL[$a];\n	$profile{$n}{identifyer}=$identifyerL[$\
a];\n	$profile{$n}{comment}=$comment[$a];\n	for ($\
b=0; $b<$L; $b++)\n	  {\n	    if ($p[$a][$b])\n	  \
    {\n		$profile{$n}{seq}.=$p[$a][$b];\n	      }\\
n	    else\n	      {\n		$profile{$n}{seq}.=\"-\";\\
n	      }\n	  }\n      }\n    \n    $profile{n}=$n\
hits+1;\n    return %profile;\n  }\nsub ebi_blast_\
xml2profile \n  {\n    my ($name,$seq,$maxid, $min\
id, $mincov, $string)=(@_);\n    my ($L,$l, $a,$b,\
$c,$d,$nhits,@identifyerL,$identifyer);\n    \n\n \
   \n    $seq=~s/[^a-zA-Z]//g;\n    $L=length ($se\
q);\n    %hit=&xml2tag_list ($string, \"hit\");\n \
   \n    for ($nhits=0,$a=0; $a<$hit{n}; $a++)\n  \
    {\n	my ($ldb,$id, $identity, $expectation, $st\
art, $end, $coverage, $r);\n	my (%Q,%M,%E,%I);\n	\\
n	$ldb=&tag2value ($hit{$a}{open}, \"database\");\\
n	$identifyer=&tag2value ($hit{$a}{open}, \"id\");\
\n\n	$description=&tag2value ($hit{$a}{open}, \"de\
scription\");\n	\n	%Q=&xml2tag_list ($hit{$a}{body\
}, \"querySeq\");\n	%M=&xml2tag_list ($hit{$a}{bod\
y}, \"matchSeq\");\n	%E=&xml2tag_list ($hit{$a}{bo\
dy}, \"expectation\");\n	%I=&xml2tag_list ($hit{$a\
}{body}, \"identity\");\n	\n\n	for ($b=0; $b<$Q{n}\
; $b++)\n	  {\n	    \n	    \n	    $qs=$Q{$b}{body}\
;\n	    $ms=$M{$b}{body};\n	    if ($seq eq\"\"){$\
seq=$qs;$L=length($seq);}\n\n	    $expectation=$E{\
$b}{body};\n	    $identity=$I{$b}{body};\n	    \n	\
    	    \n	    $start=&tag2value ($Q{$b}{open}, \\
"start\");\n	    $end=&tag2value ($Q{$b}{open}, \"\
end\");\n	    $startM=&tag2value ($M{$b}{open}, \"\
start\");\n	    $endM=&tag2value ($M{$b}{open}, \"\
end\");\n	    $coverage=(($end-$start)*100)/$L;\n	\
    \n	   # print \"$id: ID: $identity COV: $cover\
age [$start $end]\\n\";\n	    \n	    \n	    if ($i\
dentity>$maxid || $identity<$minid || $coverage<$m\
incov){next;}\n	    # print \"KEEP\\n\";\n\n	    \\
n	    @lr1=(split (//,$qs));\n	    @lr2=(split (//\
,$ms));\n	    $l=$#lr1+1;\n	    for ($c=0;$c<$L;$c\
++){$p[$nhits][$c]=\"-\";}\n	    for ($d=0,$c=0; $\
c<$l; $c++)\n	      {\n		$r=$lr1[$c];\n		if ( $r=~\
/[A-Za-z]/)\n		  {\n		    \n		    $p[$nhits][$d + \
$start-1]=$lr2[$c];\n		    $d++;\n		  }\n	      }\\
n	  \n	    \n	    $identifyerL[$nhits]=$identifyer\
;\n	    $comment[$nhits]=\"$ldb|$identifyer [Eval=\
$expectation][id=$identity%][start=$startM end=$en\
dM]\";\n	    $nhits++;\n	  }\n      }\n    \n    $\
profile{n}=0;\n    $profile{$profile{n}}{name}=$na\
me;\n    $profile{$profile{n}}{seq}=$seq;\n    $pr\
ofile {n}++;\n    \n    for ($a=0; $a<$nhits; $a++\
)\n      {\n	$n=$a+1;\n	$profile{$n}{name}=\"$name\
\\_$a\";\n	$profile{$n}{seq}=\"\";\n	$profile{$n}{\
identifyer}=$identifyerL[$a];\n	\n	$profile{$n}{co\
mment}=$comment[$a];\n	for ($b=0; $b<$L; $b++)\n	 \
 {\n	    if ($p[$a][$b])\n	      {\n		$profile{$n}\
{seq}.=$p[$a][$b];\n	      }\n	    else\n	      {\\
n		$profile{$n}{seq}.=\"-\";\n	      }\n	  }\n    \
  }\n    $profile{n}=$nhits+1;\n    \n    return %\
profile;\n  }\n\nsub blast_xml2hit_list\n  {\n    \
my $string=(@_[0]);\n    return &xml2tag_list ($st\
ring, \"hit\");\n  }\nsub xml2tag_list  \n  {\n   \
 my ($string_in,$tag)=@_;\n    my $tag_in, $tag_ou\
t;\n    my %tag;\n    \n    if (-e $string_in)\n  \
    {\n	$string=&file2string ($string_in);\n      \
}\n    else\n      {\n	$string=$string_in;\n      \
}\n    $tag_in1=\"<$tag \";\n    $tag_in2=\"<$tag>\
\";\n    $tag_out=\"/$tag>\";\n    $string=~s/>/>#\
#1/g;\n    $string=~s/</##2</g;\n    $string=~s/##\
1/<#/g;\n    $string=~s/##2/#>/g;\n    @l=($string\
=~/(\\<[^>]+\\>)/g);\n    $tag{n}=0;\n    $in=0;$n\
=-1;\n  \n \n\n    foreach $t (@l)\n      {\n\n	$t\
=~s/<#//;\n	$t=~s/#>//;\n	\n	if ( $t=~/$tag_in1/ |\
| $t=~/$tag_in2/)\n	  {\n	 \n	    $in=1;\n	    $ta\
g{$tag{n}}{open}=$t;\n	    $n++;\n	    \n	  }\n	el\
sif ($t=~/$tag_out/)\n	  {\n	    \n\n	    $tag{$ta\
g{n}}{close}=$t;\n	    $tag{n}++;\n	    $in=0;\n	 \
 }\n	elsif ($in)\n	  {\n	   \n	    $tag{$tag{n}}{b\
ody}.=$t;\n	  }\n      }\n  \n    return %tag;\n  \
}\n\n\n\n\n","use Env qw(HOST);\nuse Env qw(HOME);\
\nuse Env qw(USER);\nwhile (<>)\n  {\n    if ( /^>\
(\\S+)/)\n      {\n	if ($list{$1})\n	  {\n	    pri\
nt \">$1_$list{$1}\\n\";\n	    $list{$1}++;\n	  }\\
n	else\n	  {\n	    print $_;\n	    $list{$1}=1;\n	\
  }\n      }\n    else\n      {\n	print $_;\n     \
 }\n  }\n      \n","\n\n\nuse Env qw(HOST);\nuse E\
nv qw(HOME);\nuse Env qw(USER);\n\n\nopen (F,$ARGV\
[0]);\nwhile ( <>)\n  {\n    @x=/([^:,;\\)\\(\\s]+\
):[^:,;\\)\\(]*/g;\n    @list=(@list,@x);\n  }\n$n\
=$#list+1;\nforeach $n(@list){print \">$n\\nsequen\
ce\\n\";}\n\n\nclose (F);\n","\nopen (F, $ARGV[0])\
;\n\nwhile ( <F>)\n  {\n    @l=($_=~/(\\S+)/g);\n \
   \n    $name=shift @l;\n    \n    print STDOUT \\
"\\n>$name\\n\";\n    foreach $e (@l){$e=($e eq \"\
0\")?\"O\":\"I\";print \"$e\";}\n  }\nclose (F);\n\
\n		       \n    \n","use strict;\nuse FileHandle;\
\nuse Env qw(HOST);\nuse Env qw(HOME);\nuse Env qw\
(USER);\nmy %name;\nmy $nseq;\nmy $F= new FileHand\
le;\nopen ($F, $ARGV[0]);\nwhile(<$F>)\n  {\n    \\
n    my $l=$_;\n    if ($l=~/^#/){;}\n    elsif ((\
$l=~/\\d+\\s+\\d+\\s+(\\S+)\\s+(\\S+)/))\n      {\\
n	my $name=$1;\n	my $seq=$2;\n	print \">$name\\n$s\
eq\\n\";\n      }\n  }\nclose ($F);\nexit (0);\n\n\
\n","use Env qw(HOST);\nuse Env qw(HOME);\nuse Env\
 qw(USER);\n\n$tmp=\"$ARGV[0].$$\";\nopen (IN, $AR\
GV[0]);\nopen (OUT, \">$tmp\");\n\nwhile ( <IN>)\n\
  {\n    $file=$_;\n    $file=~s/\\r\\n/\\n/g;\n  \
  $file=~s/\\n\\r/\\n/g;\n    $file=~s/\\r\\r/\\n/\
g;\n    $file=~s/\\r/\\n/g;\n    print OUT \"$file\
\";\n  }\nclose (IN);\nclose (OUT);\n\nopen (OUT, \
\">$ARGV[0]\");\nopen (IN, \"$tmp\");\n\nwhile ( <\
IN>)\n{\n  print OUT \"$_\";\n}\nclose (IN);\nclos\
e (OUT);\nunlink ($tmp);\n\n"};
