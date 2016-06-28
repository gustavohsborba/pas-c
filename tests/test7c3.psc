var
    s, p is int;
    pudim is int;

begin
    s := 0;

    do
        out({Valor a ser somado: });
        in(p);
        s := s+p;
    while p<>0;

    out({Total a pagar: R$});
    out(s);
end