#!/bin/bash

dir=$(pwd)

# Run me as ROOT if permission is needed

echo -e "\n# Added by BioProg_Linux" >>~/.bashrc
echo "export PATH=\"${dir}/beast/bin:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/consel:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/figtree/bin:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/gblocks:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/iqtree:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/igv:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/Mesquite_Folder:\$PATH\"" >>~/.bashrc

echo "export PATH=\"${dir}/paup:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/paml:\$PATH\"" >>~/.bashrc
echo "export PATH=\"${dir}/prank:\$PATH\"" >>~/.bashrc
echo '######' >>~/.bashrc
