var
    s, p is int;
    var is int;

begin
    s := 0;

    do
        out({Preço? });
        in(p);
        s := s+p;
    while p!=0;

    out({Total writeln a pagar: R$});
    out(s);
end.