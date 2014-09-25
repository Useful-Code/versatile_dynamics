versatile_dynamics
==================

an IIR filter implementation to be used as a system dynamics simulator

 The filter coeffs can be generated from a continous transfer function within matlab

====Generate B and A filter coeffs====

  * create a continuous transfer function to encode your behaviour
    * <code matlab>system = tf([],[]); </code>
  * turn it into a discrete transfer function:
    * <code matlab>digisystem = c2d(system, sample_period) </code>
  * get the coeffs out of there, in vector format:
    * <code matlab>tfdata(digisystem, 'v'); </code>
  * Use the format shown with ''help filter'' to write your own dynamics function

