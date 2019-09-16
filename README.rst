=======
storage
=======

.. image:: https://travis-ci.org/steinwurf/storage.svg?branch=master
    :target: https://travis-ci.org/steinwurf/storage

storage is a C++ header-only library providing an abstraction for storage /
buffers.
This implementation is inspired by ``boost::asio``'s ``buffer.hpp``
`header <https://github.com/steinwurf/boost/blob/master/boost/asio/buffer.hpp>`_.


Use as Dependency in CMake
==========================

To depend on this project when using the CMake build system, add the following
in your CMake build script::

   add_subdirectory("/path/to/storage" storage)
   target_link_libraries(<my_target> steinwurf::storage)

Where ``<my_target>`` is replaced by your target.

License
=======

storage is available under the BSD license.
