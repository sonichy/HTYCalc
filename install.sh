s="[Desktop Entry]\nName=海天鹰计算器\nComment=HTY Calculate\nExec=`pwd`/HTYCalc\nIcon=`pwd`/icon.png\nPath=`pwd`\nTerminal=false\nType=Application\nCategories=System;"
echo -e $s > HTYCalc.desktop
cp `pwd`/HTYCalc.desktop ~/.local/share/applications/HTYCalc.desktop