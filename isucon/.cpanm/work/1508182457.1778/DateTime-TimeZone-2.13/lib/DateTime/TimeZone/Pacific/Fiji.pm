# This file is auto-generated by the Perl DateTime Suite time zone
# code generator (0.08) This code generator comes with the
# DateTime::TimeZone module distribution in the tools/ directory

#
# Generated from /tmp/Lmk3a2MG67/australasia.  Olson data version 2017b
#
# Do not edit this file directly.
#
package DateTime::TimeZone::Pacific::Fiji;

use strict;
use warnings;
use namespace::autoclean;

our $VERSION = '2.13';

use Class::Singleton 1.03;
use DateTime::TimeZone;
use DateTime::TimeZone::OlsonDB;

@DateTime::TimeZone::Pacific::Fiji::ISA = ( 'Class::Singleton', 'DateTime::TimeZone' );

my $spans =
[
    [
DateTime::TimeZone::NEG_INFINITY, #    utc_start
60425697856, #      utc_end 1915-10-25 12:04:16 (Mon)
DateTime::TimeZone::NEG_INFINITY, #  local_start
60425740800, #    local_end 1915-10-26 00:00:00 (Tue)
42944,
0,
'LMT',
    ],
    [
60425697856, #    utc_start 1915-10-25 12:04:16 (Mon)
63045525600, #      utc_end 1998-10-31 14:00:00 (Sat)
60425741056, #  local_start 1915-10-26 00:04:16 (Tue)
63045568800, #    local_end 1998-11-01 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63045525600, #    utc_start 1998-10-31 14:00:00 (Sat)
63055807200, #      utc_end 1999-02-27 14:00:00 (Sat)
63045572400, #  local_start 1998-11-01 03:00:00 (Sun)
63055854000, #    local_end 1999-02-28 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63055807200, #    utc_start 1999-02-27 14:00:00 (Sat)
63077580000, #      utc_end 1999-11-06 14:00:00 (Sat)
63055850400, #  local_start 1999-02-28 02:00:00 (Sun)
63077623200, #    local_end 1999-11-07 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63077580000, #    utc_start 1999-11-06 14:00:00 (Sat)
63087256800, #      utc_end 2000-02-26 14:00:00 (Sat)
63077626800, #  local_start 1999-11-07 03:00:00 (Sun)
63087303600, #    local_end 2000-02-27 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63087256800, #    utc_start 2000-02-26 14:00:00 (Sat)
63395100000, #      utc_end 2009-11-28 14:00:00 (Sat)
63087300000, #  local_start 2000-02-27 02:00:00 (Sun)
63395143200, #    local_end 2009-11-29 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63395100000, #    utc_start 2009-11-28 14:00:00 (Sat)
63405381600, #      utc_end 2010-03-27 14:00:00 (Sat)
63395146800, #  local_start 2009-11-29 03:00:00 (Sun)
63405428400, #    local_end 2010-03-28 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63405381600, #    utc_start 2010-03-27 14:00:00 (Sat)
63423525600, #      utc_end 2010-10-23 14:00:00 (Sat)
63405424800, #  local_start 2010-03-28 02:00:00 (Sun)
63423568800, #    local_end 2010-10-24 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63423525600, #    utc_start 2010-10-23 14:00:00 (Sat)
63435016800, #      utc_end 2011-03-05 14:00:00 (Sat)
63423572400, #  local_start 2010-10-24 03:00:00 (Sun)
63435063600, #    local_end 2011-03-06 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63435016800, #    utc_start 2011-03-05 14:00:00 (Sat)
63454975200, #      utc_end 2011-10-22 14:00:00 (Sat)
63435060000, #  local_start 2011-03-06 02:00:00 (Sun)
63455018400, #    local_end 2011-10-23 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63454975200, #    utc_start 2011-10-22 14:00:00 (Sat)
63462837600, #      utc_end 2012-01-21 14:00:00 (Sat)
63455022000, #  local_start 2011-10-23 03:00:00 (Sun)
63462884400, #    local_end 2012-01-22 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63462837600, #    utc_start 2012-01-21 14:00:00 (Sat)
63486424800, #      utc_end 2012-10-20 14:00:00 (Sat)
63462880800, #  local_start 2012-01-22 02:00:00 (Sun)
63486468000, #    local_end 2012-10-21 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63486424800, #    utc_start 2012-10-20 14:00:00 (Sat)
63494287200, #      utc_end 2013-01-19 14:00:00 (Sat)
63486471600, #  local_start 2012-10-21 03:00:00 (Sun)
63494334000, #    local_end 2013-01-20 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63494287200, #    utc_start 2013-01-19 14:00:00 (Sat)
63518479200, #      utc_end 2013-10-26 14:00:00 (Sat)
63494330400, #  local_start 2013-01-20 02:00:00 (Sun)
63518522400, #    local_end 2013-10-27 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63518479200, #    utc_start 2013-10-26 14:00:00 (Sat)
63525733200, #      utc_end 2014-01-18 13:00:00 (Sat)
63518526000, #  local_start 2013-10-27 03:00:00 (Sun)
63525780000, #    local_end 2014-01-19 02:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63525733200, #    utc_start 2014-01-18 13:00:00 (Sat)
63550533600, #      utc_end 2014-11-01 14:00:00 (Sat)
63525776400, #  local_start 2014-01-19 01:00:00 (Sun)
63550576800, #    local_end 2014-11-02 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63550533600, #    utc_start 2014-11-01 14:00:00 (Sat)
63557186400, #      utc_end 2015-01-17 14:00:00 (Sat)
63550580400, #  local_start 2014-11-02 03:00:00 (Sun)
63557233200, #    local_end 2015-01-18 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63557186400, #    utc_start 2015-01-17 14:00:00 (Sat)
63581983200, #      utc_end 2015-10-31 14:00:00 (Sat)
63557229600, #  local_start 2015-01-18 02:00:00 (Sun)
63582026400, #    local_end 2015-11-01 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63581983200, #    utc_start 2015-10-31 14:00:00 (Sat)
63588636000, #      utc_end 2016-01-16 14:00:00 (Sat)
63582030000, #  local_start 2015-11-01 03:00:00 (Sun)
63588682800, #    local_end 2016-01-17 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63588636000, #    utc_start 2016-01-16 14:00:00 (Sat)
63614037600, #      utc_end 2016-11-05 14:00:00 (Sat)
63588679200, #  local_start 2016-01-17 02:00:00 (Sun)
63614080800, #    local_end 2016-11-06 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63614037600, #    utc_start 2016-11-05 14:00:00 (Sat)
63620085600, #      utc_end 2017-01-14 14:00:00 (Sat)
63614084400, #  local_start 2016-11-06 03:00:00 (Sun)
63620132400, #    local_end 2017-01-15 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63620085600, #    utc_start 2017-01-14 14:00:00 (Sat)
63645487200, #      utc_end 2017-11-04 14:00:00 (Sat)
63620128800, #  local_start 2017-01-15 02:00:00 (Sun)
63645530400, #    local_end 2017-11-05 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63645487200, #    utc_start 2017-11-04 14:00:00 (Sat)
63652140000, #      utc_end 2018-01-20 14:00:00 (Sat)
63645534000, #  local_start 2017-11-05 03:00:00 (Sun)
63652186800, #    local_end 2018-01-21 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63652140000, #    utc_start 2018-01-20 14:00:00 (Sat)
63676936800, #      utc_end 2018-11-03 14:00:00 (Sat)
63652183200, #  local_start 2018-01-21 02:00:00 (Sun)
63676980000, #    local_end 2018-11-04 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63676936800, #    utc_start 2018-11-03 14:00:00 (Sat)
63683589600, #      utc_end 2019-01-19 14:00:00 (Sat)
63676983600, #  local_start 2018-11-04 03:00:00 (Sun)
63683636400, #    local_end 2019-01-20 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63683589600, #    utc_start 2019-01-19 14:00:00 (Sat)
63708386400, #      utc_end 2019-11-02 14:00:00 (Sat)
63683632800, #  local_start 2019-01-20 02:00:00 (Sun)
63708429600, #    local_end 2019-11-03 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63708386400, #    utc_start 2019-11-02 14:00:00 (Sat)
63715039200, #      utc_end 2020-01-18 14:00:00 (Sat)
63708433200, #  local_start 2019-11-03 03:00:00 (Sun)
63715086000, #    local_end 2020-01-19 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63715039200, #    utc_start 2020-01-18 14:00:00 (Sat)
63739836000, #      utc_end 2020-10-31 14:00:00 (Sat)
63715082400, #  local_start 2020-01-19 02:00:00 (Sun)
63739879200, #    local_end 2020-11-01 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63739836000, #    utc_start 2020-10-31 14:00:00 (Sat)
63746488800, #      utc_end 2021-01-16 14:00:00 (Sat)
63739882800, #  local_start 2020-11-01 03:00:00 (Sun)
63746535600, #    local_end 2021-01-17 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63746488800, #    utc_start 2021-01-16 14:00:00 (Sat)
63771890400, #      utc_end 2021-11-06 14:00:00 (Sat)
63746532000, #  local_start 2021-01-17 02:00:00 (Sun)
63771933600, #    local_end 2021-11-07 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63771890400, #    utc_start 2021-11-06 14:00:00 (Sat)
63777938400, #      utc_end 2022-01-15 14:00:00 (Sat)
63771937200, #  local_start 2021-11-07 03:00:00 (Sun)
63777985200, #    local_end 2022-01-16 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63777938400, #    utc_start 2022-01-15 14:00:00 (Sat)
63803340000, #      utc_end 2022-11-05 14:00:00 (Sat)
63777981600, #  local_start 2022-01-16 02:00:00 (Sun)
63803383200, #    local_end 2022-11-06 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63803340000, #    utc_start 2022-11-05 14:00:00 (Sat)
63809388000, #      utc_end 2023-01-14 14:00:00 (Sat)
63803386800, #  local_start 2022-11-06 03:00:00 (Sun)
63809434800, #    local_end 2023-01-15 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63809388000, #    utc_start 2023-01-14 14:00:00 (Sat)
63834789600, #      utc_end 2023-11-04 14:00:00 (Sat)
63809431200, #  local_start 2023-01-15 02:00:00 (Sun)
63834832800, #    local_end 2023-11-05 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63834789600, #    utc_start 2023-11-04 14:00:00 (Sat)
63841442400, #      utc_end 2024-01-20 14:00:00 (Sat)
63834836400, #  local_start 2023-11-05 03:00:00 (Sun)
63841489200, #    local_end 2024-01-21 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63841442400, #    utc_start 2024-01-20 14:00:00 (Sat)
63866239200, #      utc_end 2024-11-02 14:00:00 (Sat)
63841485600, #  local_start 2024-01-21 02:00:00 (Sun)
63866282400, #    local_end 2024-11-03 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63866239200, #    utc_start 2024-11-02 14:00:00 (Sat)
63872892000, #      utc_end 2025-01-18 14:00:00 (Sat)
63866286000, #  local_start 2024-11-03 03:00:00 (Sun)
63872938800, #    local_end 2025-01-19 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63872892000, #    utc_start 2025-01-18 14:00:00 (Sat)
63897688800, #      utc_end 2025-11-01 14:00:00 (Sat)
63872935200, #  local_start 2025-01-19 02:00:00 (Sun)
63897732000, #    local_end 2025-11-02 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63897688800, #    utc_start 2025-11-01 14:00:00 (Sat)
63904341600, #      utc_end 2026-01-17 14:00:00 (Sat)
63897735600, #  local_start 2025-11-02 03:00:00 (Sun)
63904388400, #    local_end 2026-01-18 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63904341600, #    utc_start 2026-01-17 14:00:00 (Sat)
63929138400, #      utc_end 2026-10-31 14:00:00 (Sat)
63904384800, #  local_start 2026-01-18 02:00:00 (Sun)
63929181600, #    local_end 2026-11-01 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63929138400, #    utc_start 2026-10-31 14:00:00 (Sat)
63935791200, #      utc_end 2027-01-16 14:00:00 (Sat)
63929185200, #  local_start 2026-11-01 03:00:00 (Sun)
63935838000, #    local_end 2027-01-17 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63935791200, #    utc_start 2027-01-16 14:00:00 (Sat)
63961192800, #      utc_end 2027-11-06 14:00:00 (Sat)
63935834400, #  local_start 2027-01-17 02:00:00 (Sun)
63961236000, #    local_end 2027-11-07 02:00:00 (Sun)
43200,
0,
'+12',
    ],
    [
63961192800, #    utc_start 2027-11-06 14:00:00 (Sat)
63967240800, #      utc_end 2028-01-15 14:00:00 (Sat)
63961239600, #  local_start 2027-11-07 03:00:00 (Sun)
63967287600, #    local_end 2028-01-16 03:00:00 (Sun)
46800,
1,
'+13',
    ],
    [
63967240800, #    utc_start 2028-01-15 14:00:00 (Sat)
63992642400, #      utc_end 2028-11-04 14:00:00 (Sat)
63967284000, #  local_start 2028-01-16 02:00:00 (Sun)
63992685600, #    local_end 2028-11-05 02:00:00 (Sun)
43200,
0,
'+12',
    ],
];

sub olson_version {'2017b'}

sub has_dst_changes {22}

sub _max_year {2027}

sub _new_instance {
    return shift->_init( @_, spans => $spans );
}

sub _last_offset { 43200 }

my $last_observance = bless( {
  'format' => '+12/+13',
  'gmtoff' => '12:00',
  'local_start_datetime' => bless( {
    'formatter' => undef,
    'local_rd_days' => 699372,
    'local_rd_secs' => 256,
    'offset_modifier' => 0,
    'rd_nanosecs' => 0,
    'tz' => bless( {
      'name' => 'floating',
      'offset' => 0
    }, 'DateTime::TimeZone::Floating' ),
    'utc_rd_days' => 699372,
    'utc_rd_secs' => 256,
    'utc_year' => 1916
  }, 'DateTime' ),
  'offset_from_std' => 0,
  'offset_from_utc' => 43200,
  'until' => [],
  'utc_start_datetime' => bless( {
    'formatter' => undef,
    'local_rd_days' => 699371,
    'local_rd_secs' => 43456,
    'offset_modifier' => 0,
    'rd_nanosecs' => 0,
    'tz' => bless( {
      'name' => 'floating',
      'offset' => 0
    }, 'DateTime::TimeZone::Floating' ),
    'utc_rd_days' => 699371,
    'utc_rd_secs' => 43456,
    'utc_year' => 1916
  }, 'DateTime' )
}, 'DateTime::TimeZone::OlsonDB::Observance' )
;
sub _last_observance { $last_observance }

my $rules = [
  bless( {
    'at' => '3:00',
    'from' => '2015',
    'in' => 'Jan',
    'letter' => '',
    'name' => 'Fiji',
    'offset_from_std' => 0,
    'on' => 'Sun>=15',
    'save' => '0',
    'to' => 'max'
  }, 'DateTime::TimeZone::OlsonDB::Rule' ),
  bless( {
    'at' => '2:00',
    'from' => '2014',
    'in' => 'Nov',
    'letter' => 'S',
    'name' => 'Fiji',
    'offset_from_std' => 3600,
    'on' => 'Sun>=1',
    'save' => '1:00',
    'to' => 'max'
  }, 'DateTime::TimeZone::OlsonDB::Rule' )
]
;
sub _rules { $rules }


1;

