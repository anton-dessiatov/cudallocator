let nixpkgs = import ./nixpkgs.nix;
    pkgs = import nixpkgs {
      overlays = [
        (self: super: {
          cudallocator = (super.callPackage ./derivation.nix {}).overrideAttrs (old: {
            hardeningDisable = [ "all" ];
            nativeBuildInputs = old.nativeBuildInputs ++ [
              super.gdb super.clang-tools
            ];
          });
        })
      ];
    };
in  pkgs.cudallocator
