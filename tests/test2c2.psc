var
 a is int;
 b is int;
 nome is string;
begin
 in (a);
 in (nome);
 b := a * a;
 b := b + a/2 * (3 + 5);
 out (nome);
 out(b);
end