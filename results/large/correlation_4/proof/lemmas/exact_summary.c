void kernel(unsigned int a[4], unsigned int k, unsigned int out[4]) {
unsigned int __summary_input_0[4];
__summary_input_0[0]=a[0];
__summary_input_0[1]=a[1];
__summary_input_0[2]=a[2];
__summary_input_0[3]=a[3];
unsigned int __summary_input_2[4];
__summary_input_2[0]=out[0];
__summary_input_2[1]=out[1];
__summary_input_2[2]=out[2];
__summary_input_2[3]=out[3];
a[0]=__summary_input_0[0];
a[1]=__summary_input_0[1];
a[2]=__summary_input_0[2];
a[3]=__summary_input_0[3];
out[0]=(13u * __summary_input_0[0]);
out[1]=(13u * __summary_input_0[1]);
out[2]=(13u * __summary_input_0[2]);
out[3]=(13u * __summary_input_0[3]);
}
