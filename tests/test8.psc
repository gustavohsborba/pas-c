var
    n, c, r is int;

begin
    out({Digite um número: });
    in(n);

    c:=1;
    do
        out(n);
        out({ x });
        out(c);
        out({ = });
        out(n*c);
        out({\n});
    while c !=10;

end.