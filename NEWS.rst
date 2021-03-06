News for storage
================

This file lists the major changes between versions. For a more detailed list of
every change, see the Git log.

Latest
------
* tbd

5.3.0
-----
* Minor: Minor changes to CMakeLists.txt.

5.2.0
-----
* Minor: Added install step to CMake.

5.1.0
-----
* Minor: Lower CMake version requirement.

5.0.0
-----
* Major: Use `uint64_t` for size rather than `uint32_t`.

4.2.0
-----
* Minor: Improve cmake build file.

4.1.0
-----
* Minor: Added cmake.

4.0.1
-----
* Patch: `is_equal` and `is_same` now allows parameter types that differs so that
  `const_storages` and `mutable_storages` can be compared.

4.0.0
-----
* Major: Removed `operator+=` and `operator+`, use `storage::offset` instead.
* Major: Added `storage::offset`.
* Major: Added `storage::shrink`.
* Major: Added `storage::slice`.
* Major: `storage.m_data` and `storage.m_size` no private. They can be accessed
  with `data()` and `size()`.
* Major: storage object may no longer have data pointers to null and a size of
  0. This also means the default constructor is gone. Use third-party
  construct like `boost::optional` instead.

3.1.0
-----
* Minor: Added helper for creating storage objects from ``std::array``\ s

3.0.0
-----
* Major: Upgrade to waf-tools 4
* Minor: Upgrade to gtest 4

2.1.0
-----
* Minor: Adding operator==(...) to allow using algorithms that compare stuff
  that way.

2.0.0
-----
* Major: Renamed
  ``storage_size`` to ``size``,
  ``storage_cast`` to ``cast``,
  ``storage_copy`` to ``copy``,
  ``zero_storage`` to ``fill_zero``,
  ``split_storage`` to ``split``.
* Major: Changed the structure of the repository to be one file per definition.
* Major: Changed the ``storage`` use flag to ``storage_includes``.

1.0.0
-----
* Major: Initial release.
