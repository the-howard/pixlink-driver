savedcmd_/home/iamroot/pixlink-driver/pixlink.mod := printf '%s\n'   pixlink.o | awk '!x[$$0]++ { print("/home/iamroot/pixlink-driver/"$$0) }' > /home/iamroot/pixlink-driver/pixlink.mod
