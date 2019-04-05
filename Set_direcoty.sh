#!/bin/bash

dir=$(pwd)

# Run me as ROOT if permission is needed
a=$(grep -n '# Added by BioProg_Linux' ~/.bashrc | cut -d ':' -f 1)
b=$(grep -n '######END######' ~/.bashrc | cut -d ':' -f 1)
if [[ -n "${a}" ]] && [[ -n "${b}" ]]; then
    sed -i "${a},${b}d" ~/.bashrc
fi

echo -e "\n# Added by BioProg_Linux" >>~/.bashrc
echo "export PATH=\"${dir}/beast/bin:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/bcftools:\$PATH\"" >>~/.bashrc
echo "export BCFTOOLS_PLUGINS=\"${dir}/bcftools/plugins\"" >>~/.bashrc
echo "alias bamview='java -mx4000m -jar ${dir}/bamview/BamView.jar \"\$@\"'" >>~/.bashrc
echo "export PATH=\"${dir}/bwa:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/consel:\$PATH\"" >>~/.bashrc

echo "alias figtree='java -Xms64m -Xmx4000m -jar ${dir}/figtree/figtree.jar \"\$@\"'" >>~/.bashrc

echo "export PATH=\"${dir}/gblocks:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/iqtree:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/igv:\$PATH\"" >>~/.bashrc

echo "alias mesquite='java -Djava.library.path=lib -Xss4m -Xmx4000m -cp \"${dir}/Mesquite_Folder/\" mesquite.Mesquite $*'" >>~/.bashrc
echo "export PATH=\"${dir}/minimap2:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/mrbayes:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/paup:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/paml:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/Phred_Phrap:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/prank:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/raxml:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/samtools:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/tablet:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/t_coffee/bin:\$PATH\"" >>~/.bashrc
echo '######END######' >>~/.bashrc
