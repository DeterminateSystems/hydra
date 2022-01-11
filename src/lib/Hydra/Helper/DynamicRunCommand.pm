package Hydra::Helper::DynamicRunCommand;

use utf8;
use strict;
use warnings;
use base 'Hydra::Base::Controller::ListBuilds';
use Hydra::Helper::Nix;
use Hydra::Helper::CatalystUtils;

our @ISA = qw(Exporter);
our @EXPORT = qw(
    allowDynamicRunCommand
);

sub allowDynamicRunCommand {
    my ($want_enabled, $enabled_on_project) = @_;
    my $enabled_on_server = getHydraConfig()->{dynamicruncommand}->{enable};

    if (defined $enabled_on_project) {
        if ($want_enabled && !($enabled_on_server && $enabled_on_project)) {
            return 0;
        }
    } else {
        if ($want_enabled && !$enabled_on_server) {
            return 0;
        }
    }

    return 1;
};


1;
