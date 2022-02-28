cat /etc/passwd | sed '/^#/d' | sed -n 2~2p | cut -d ":" -f1 | rev | sort -d -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' '|' | sed 's/|/, /g' | sed 's/, $/./'
