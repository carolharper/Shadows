#PROG
vnum 9902
code if name $n Eldoran
  smile eldoran
  hug eldoran
  say Welcome home, Eldoran.
else
  if isimmort $n
    mob echoat $n Stephanie smiles warmly at you.
    say Welcome Immortal $n, how may I be of assistance?
  else
    mob echoat $n Stephanie smiles at you in greeting.
    say Welcome to Eldoran's room, $n.  Make yourself at home.
  endif
endif
~
#END

