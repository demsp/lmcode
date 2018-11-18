var 
x,d:integer;
begin 
d:=0;
read (x);
while (x<>0) do begin
 if (x<>1) then d:=d-1
           else d:=d+1;
read (x);
end;
if (d=0) then writeln('count of 1 = count of 2')
else writeln ('count of 1 not= count of 2');
end.
