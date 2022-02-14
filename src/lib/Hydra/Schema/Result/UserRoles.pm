use utf8;

package Hydra::Schema::Result::UserRoles;

# Created by DBIx::Class::Schema::Loader
# DO NOT MODIFY THE FIRST PART OF THIS FILE

=head1 NAME

Hydra::Schema::Result::UserRoles

=cut

use strict;
use warnings;

use base 'DBIx::Class::Core';

=head1 COMPONENTS LOADED

=over 4

=item * L<Hydra::Component::ToJSON>

=back

=cut

__PACKAGE__->load_components("+Hydra::Component::ToJSON");

=head1 TABLE: C<userroles>

=cut

__PACKAGE__->table("userroles");

=head1 ACCESSORS

=head2 username

  data_type: 'text'
  is_foreign_key: 1
  is_nullable: 0

=head2 role

  data_type: 'text'
  is_nullable: 0

=cut

__PACKAGE__->add_columns(
    "username", { data_type => "text", is_foreign_key => 1, is_nullable => 0 },
    "role", { data_type => "text", is_nullable => 0 },
);

=head1 PRIMARY KEY

=over 4

=item * L</username>

=item * L</role>

=back

=cut

__PACKAGE__->set_primary_key("username", "role");

=head1 RELATIONS

=head2 username

Type: belongs_to

Related object: L<Hydra::Schema::Result::Users>

=cut

__PACKAGE__->belongs_to(
    "username",
    "Hydra::Schema::Result::Users",
    { username      => "username" },
    { is_deferrable => 0, on_delete => "CASCADE", on_update => "CASCADE" },
);

# Created by DBIx::Class::Schema::Loader v0.07049 @ 2021-08-26 12:02:36
# DO NOT MODIFY THIS OR ANYTHING ABOVE! md5sum:MZCKml/f7xn3GmsqocCuuQ

1;
