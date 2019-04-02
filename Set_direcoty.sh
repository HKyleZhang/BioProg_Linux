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
echo "export PATH=\"${dir}/bwa:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/consel:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/figtree/bin:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/gblocks:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/iqtree:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/igv:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/minimap2:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/mrbayes:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/paup:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/paml:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/Phred_Phrap:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/prank:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/raxml:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/samtools:\$PATH\"" >>~/.bashrc
echo '######END######' >>~/.bashrc
