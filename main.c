#include <ruby.h>

static VALUE work_in_c(VALUE ns) {
	printf("Look, I'm working in C!\n");
	return Qnil;
}

int main(int argc, char **argv) {
	ruby_sysinit(&argc, &argv);
	RUBY_INIT_STACK;
	ruby_init();

	// create a module
	VALUE my_module = rb_define_module("MyModule");
	rb_define_module_function(my_module, "work_in_c", work_in_c, 0);

	// executing ruby code
	rb_require("./init.rb");

	// calling a ruby method using c
	rb_funcall(my_module, rb_intern("work_in_ruby"), 0, NULL);


	//
	// calling a ruby module using ruby
	//
	int state_1;
	VALUE v_1 = rb_eval_string_protect( // safe evaluation
		"MyModule::Inner.return_true",
		&state_1
	);

	if (state_1){
		printf("Call to MyModule::Inner.return_true failed.\n");
	} else {
		printf("Call to MyModule::Inner.return_true was a success.\n");
	}

	if (v_1 == Qtrue) {
		printf("MyModule::Inner.return_true returned true.\n");
	} else {
		printf("MyModule::Inner.return_true returned false.\n");
	}

	// not gonna work
	int state_2;
	rb_eval_string_protect( "MyModule::Inner.does_not_exist", &state_2);

	if (state_2){
		printf("Call to MyModule::Inner.does_not_exist failed.\n");
	} else {
		printf("Call to MyModule::Inner.does_not_exist was a success.\n");
	}

	return 0;
}
