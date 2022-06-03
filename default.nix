let nixpkgs = import ./nixpkgs.nix;
    pkgs = import nixpkgs {
      overlays = [
        (self: super: {
          cudallocator = super.callPackage ./derivation.nix {};
        })
      ];
    };
in  pkgs.cudallocator
