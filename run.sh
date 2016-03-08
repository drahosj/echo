#! /bin/sh

socat TCP-LISTEN:6666,fork EXEC:./echo,nofork,stderr
