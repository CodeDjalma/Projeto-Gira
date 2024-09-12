program GIRA;

uses
  Vcl.Forms,
  Unit1 in 'M:\PROGRAMACAO\ARDUINO\ARDUINO\Unit1.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
