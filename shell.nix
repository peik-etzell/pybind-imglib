{
  pkgs ? import <nixpkgs> { },
}:
let
  python = pkgs.python311;
  pythonEnv = python.withPackages (
    ps: with ps; [
      pybind11
      pillow
    ]
  );
in
pkgs.mkShell {
  packages = [ pythonEnv ];
  buildInputs = with pkgs; [
    cmake
    ninja
  ];
  CMAKE_GENERATOR = "Ninja";
  CMAKE_EXPORT_COMPILE_COMMANDS = "ON";
}
