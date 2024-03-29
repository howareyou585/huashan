//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.12
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------


class SwigCplusplusPINVOKE {

  protected class SWIGExceptionHelper {

    public delegate void ExceptionDelegate(string message);
    public delegate void ExceptionArgumentDelegate(string message, string paramName);

    static ExceptionDelegate applicationDelegate = new ExceptionDelegate(SetPendingApplicationException);
    static ExceptionDelegate arithmeticDelegate = new ExceptionDelegate(SetPendingArithmeticException);
    static ExceptionDelegate divideByZeroDelegate = new ExceptionDelegate(SetPendingDivideByZeroException);
    static ExceptionDelegate indexOutOfRangeDelegate = new ExceptionDelegate(SetPendingIndexOutOfRangeException);
    static ExceptionDelegate invalidCastDelegate = new ExceptionDelegate(SetPendingInvalidCastException);
    static ExceptionDelegate invalidOperationDelegate = new ExceptionDelegate(SetPendingInvalidOperationException);
    static ExceptionDelegate ioDelegate = new ExceptionDelegate(SetPendingIOException);
    static ExceptionDelegate nullReferenceDelegate = new ExceptionDelegate(SetPendingNullReferenceException);
    static ExceptionDelegate outOfMemoryDelegate = new ExceptionDelegate(SetPendingOutOfMemoryException);
    static ExceptionDelegate overflowDelegate = new ExceptionDelegate(SetPendingOverflowException);
    static ExceptionDelegate systemDelegate = new ExceptionDelegate(SetPendingSystemException);

    static ExceptionArgumentDelegate argumentDelegate = new ExceptionArgumentDelegate(SetPendingArgumentException);
    static ExceptionArgumentDelegate argumentNullDelegate = new ExceptionArgumentDelegate(SetPendingArgumentNullException);
    static ExceptionArgumentDelegate argumentOutOfRangeDelegate = new ExceptionArgumentDelegate(SetPendingArgumentOutOfRangeException);

    [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="SWIGRegisterExceptionCallbacks_SwigCplusplus")]
    public static extern void SWIGRegisterExceptionCallbacks_SwigCplusplus(
                                ExceptionDelegate applicationDelegate,
                                ExceptionDelegate arithmeticDelegate,
                                ExceptionDelegate divideByZeroDelegate, 
                                ExceptionDelegate indexOutOfRangeDelegate, 
                                ExceptionDelegate invalidCastDelegate,
                                ExceptionDelegate invalidOperationDelegate,
                                ExceptionDelegate ioDelegate,
                                ExceptionDelegate nullReferenceDelegate,
                                ExceptionDelegate outOfMemoryDelegate, 
                                ExceptionDelegate overflowDelegate, 
                                ExceptionDelegate systemExceptionDelegate);

    [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="SWIGRegisterExceptionArgumentCallbacks_SwigCplusplus")]
    public static extern void SWIGRegisterExceptionCallbacksArgument_SwigCplusplus(
                                ExceptionArgumentDelegate argumentDelegate,
                                ExceptionArgumentDelegate argumentNullDelegate,
                                ExceptionArgumentDelegate argumentOutOfRangeDelegate);

    static void SetPendingApplicationException(string message) {
      SWIGPendingException.Set(new global::System.ApplicationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArithmeticException(string message) {
      SWIGPendingException.Set(new global::System.ArithmeticException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingDivideByZeroException(string message) {
      SWIGPendingException.Set(new global::System.DivideByZeroException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIndexOutOfRangeException(string message) {
      SWIGPendingException.Set(new global::System.IndexOutOfRangeException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidCastException(string message) {
      SWIGPendingException.Set(new global::System.InvalidCastException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingInvalidOperationException(string message) {
      SWIGPendingException.Set(new global::System.InvalidOperationException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingIOException(string message) {
      SWIGPendingException.Set(new global::System.IO.IOException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingNullReferenceException(string message) {
      SWIGPendingException.Set(new global::System.NullReferenceException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOutOfMemoryException(string message) {
      SWIGPendingException.Set(new global::System.OutOfMemoryException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingOverflowException(string message) {
      SWIGPendingException.Set(new global::System.OverflowException(message, SWIGPendingException.Retrieve()));
    }
    static void SetPendingSystemException(string message) {
      SWIGPendingException.Set(new global::System.SystemException(message, SWIGPendingException.Retrieve()));
    }

    static void SetPendingArgumentException(string message, string paramName) {
      SWIGPendingException.Set(new global::System.ArgumentException(message, paramName, SWIGPendingException.Retrieve()));
    }
    static void SetPendingArgumentNullException(string message, string paramName) {
      global::System.Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new global::System.ArgumentNullException(paramName, message));
    }
    static void SetPendingArgumentOutOfRangeException(string message, string paramName) {
      global::System.Exception e = SWIGPendingException.Retrieve();
      if (e != null) message = message + " Inner Exception: " + e.Message;
      SWIGPendingException.Set(new global::System.ArgumentOutOfRangeException(paramName, message));
    }

    static SWIGExceptionHelper() {
      SWIGRegisterExceptionCallbacks_SwigCplusplus(
                                applicationDelegate,
                                arithmeticDelegate,
                                divideByZeroDelegate,
                                indexOutOfRangeDelegate,
                                invalidCastDelegate,
                                invalidOperationDelegate,
                                ioDelegate,
                                nullReferenceDelegate,
                                outOfMemoryDelegate,
                                overflowDelegate,
                                systemDelegate);

      SWIGRegisterExceptionCallbacksArgument_SwigCplusplus(
                                argumentDelegate,
                                argumentNullDelegate,
                                argumentOutOfRangeDelegate);
    }
  }

  protected static SWIGExceptionHelper swigExceptionHelper = new SWIGExceptionHelper();

  public class SWIGPendingException {
    [global::System.ThreadStatic]
    private static global::System.Exception pendingException = null;
    private static int numExceptionsPending = 0;

    public static bool Pending {
      get {
        bool pending = false;
        if (numExceptionsPending > 0)
          if (pendingException != null)
            pending = true;
        return pending;
      } 
    }

    public static void Set(global::System.Exception e) {
      if (pendingException != null)
        throw new global::System.ApplicationException("FATAL: An earlier pending exception from unmanaged code was missed and thus not thrown (" + pendingException.ToString() + ")", e);
      pendingException = e;
      lock(typeof(SwigCplusplusPINVOKE)) {
        numExceptionsPending++;
      }
    }

    public static global::System.Exception Retrieve() {
      global::System.Exception e = null;
      if (numExceptionsPending > 0) {
        if (pendingException != null) {
          e = pendingException;
          pendingException = null;
          lock(typeof(SwigCplusplusPINVOKE)) {
            numExceptionsPending--;
          }
        }
      }
      return e;
    }
  }


  protected class SWIGStringHelper {

    public delegate string SWIGStringDelegate(string message);
    static SWIGStringDelegate stringDelegate = new SWIGStringDelegate(CreateString);

    [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="SWIGRegisterStringCallback_SwigCplusplus")]
    public static extern void SWIGRegisterStringCallback_SwigCplusplus(SWIGStringDelegate stringDelegate);

    static string CreateString(string cString) {
      return cString;
    }

    static SWIGStringHelper() {
      SWIGRegisterStringCallback_SwigCplusplus(stringDelegate);
    }
  }

  static protected SWIGStringHelper swigStringHelper = new SWIGStringHelper();


  static SwigCplusplusPINVOKE() {
  }


  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_funcA")]
  public static extern void funcA();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_PI_get")]
  public static extern double PI_get();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_CPlusPlusClass_Add")]
  public static extern int CPlusPlusClass_Add(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_CPlusPlusClass")]
  public static extern global::System.IntPtr new_CPlusPlusClass();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_delete_CPlusPlusClass")]
  public static extern void delete_CPlusPlusClass(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_Foo_add")]
  public static extern void Foo_add(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2, global::System.Runtime.InteropServices.HandleRef jarg3, global::System.Runtime.InteropServices.HandleRef jarg4);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_Foo_spam1")]
  public static extern void Foo_spam1(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_Foo_spam2")]
  public static extern void Foo_spam2(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_Foo_spam3")]
  public static extern void Foo_spam3(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_Foo_spam4")]
  public static extern void Foo_spam4(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_Foo")]
  public static extern global::System.IntPtr new_Foo();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_delete_Foo")]
  public static extern void delete_Foo(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_point3d__SWIG_0")]
  public static extern global::System.IntPtr new_point3d__SWIG_0();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_point3d__SWIG_1")]
  public static extern global::System.IntPtr new_point3d__SWIG_1(double jarg1, double jarg2, double jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_point3d_add_point")]
  public static extern global::System.IntPtr point3d_add_point(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_point3d_x_set")]
  public static extern void point3d_x_set(global::System.Runtime.InteropServices.HandleRef jarg1, double jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_point3d_x_get")]
  public static extern double point3d_x_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_point3d_y_set")]
  public static extern void point3d_y_set(global::System.Runtime.InteropServices.HandleRef jarg1, double jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_point3d_y_get")]
  public static extern double point3d_y_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_point3d_z_set")]
  public static extern void point3d_z_set(global::System.Runtime.InteropServices.HandleRef jarg1, double jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_point3d_z_get")]
  public static extern double point3d_z_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_delete_point3d")]
  public static extern void delete_point3d(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_triangle_a_set")]
  public static extern void triangle_a_set(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_triangle_a_get")]
  public static extern int triangle_a_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_triangle_b_set")]
  public static extern void triangle_b_set(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_triangle_b_get")]
  public static extern int triangle_b_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_triangle_c_set")]
  public static extern void triangle_c_set(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_triangle_c_get")]
  public static extern int triangle_c_get(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_triangle")]
  public static extern global::System.IntPtr new_triangle();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_delete_triangle")]
  public static extern void delete_triangle(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_Clear")]
  public static extern void vec3ds_Clear(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_Add")]
  public static extern void vec3ds_Add(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_size")]
  public static extern uint vec3ds_size(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_capacity")]
  public static extern uint vec3ds_capacity(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_reserve")]
  public static extern void vec3ds_reserve(global::System.Runtime.InteropServices.HandleRef jarg1, uint jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_vec3ds__SWIG_0")]
  public static extern global::System.IntPtr new_vec3ds__SWIG_0();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_vec3ds__SWIG_1")]
  public static extern global::System.IntPtr new_vec3ds__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_vec3ds__SWIG_2")]
  public static extern global::System.IntPtr new_vec3ds__SWIG_2(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_getitemcopy")]
  public static extern global::System.IntPtr vec3ds_getitemcopy(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_getitem")]
  public static extern global::System.IntPtr vec3ds_getitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_setitem")]
  public static extern void vec3ds_setitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_AddRange")]
  public static extern void vec3ds_AddRange(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_GetRange")]
  public static extern global::System.IntPtr vec3ds_GetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_Insert")]
  public static extern void vec3ds_Insert(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_InsertRange")]
  public static extern void vec3ds_InsertRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_RemoveAt")]
  public static extern void vec3ds_RemoveAt(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_RemoveRange")]
  public static extern void vec3ds_RemoveRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_Repeat")]
  public static extern global::System.IntPtr vec3ds_Repeat(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_Reverse__SWIG_0")]
  public static extern void vec3ds_Reverse__SWIG_0(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_Reverse__SWIG_1")]
  public static extern void vec3ds_Reverse__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vec3ds_SetRange")]
  public static extern void vec3ds_SetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_delete_vec3ds")]
  public static extern void delete_vec3ds(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_Clear")]
  public static extern void vecTris_Clear(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_Add")]
  public static extern void vecTris_Add(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_size")]
  public static extern uint vecTris_size(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_capacity")]
  public static extern uint vecTris_capacity(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_reserve")]
  public static extern void vecTris_reserve(global::System.Runtime.InteropServices.HandleRef jarg1, uint jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_vecTris__SWIG_0")]
  public static extern global::System.IntPtr new_vecTris__SWIG_0();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_vecTris__SWIG_1")]
  public static extern global::System.IntPtr new_vecTris__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_vecTris__SWIG_2")]
  public static extern global::System.IntPtr new_vecTris__SWIG_2(int jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_getitemcopy")]
  public static extern global::System.IntPtr vecTris_getitemcopy(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_getitem")]
  public static extern global::System.IntPtr vecTris_getitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_setitem")]
  public static extern void vecTris_setitem(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_AddRange")]
  public static extern void vecTris_AddRange(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_GetRange")]
  public static extern global::System.IntPtr vecTris_GetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_Insert")]
  public static extern void vecTris_Insert(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_InsertRange")]
  public static extern void vecTris_InsertRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_RemoveAt")]
  public static extern void vecTris_RemoveAt(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_RemoveRange")]
  public static extern void vecTris_RemoveRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_Repeat")]
  public static extern global::System.IntPtr vecTris_Repeat(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_Reverse__SWIG_0")]
  public static extern void vecTris_Reverse__SWIG_0(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_Reverse__SWIG_1")]
  public static extern void vecTris_Reverse__SWIG_1(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, int jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_vecTris_SetRange")]
  public static extern void vecTris_SetRange(global::System.Runtime.InteropServices.HandleRef jarg1, int jarg2, global::System.Runtime.InteropServices.HandleRef jarg3);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_delete_vecTris")]
  public static extern void delete_vecTris(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_new_gmeParseObj")]
  public static extern global::System.IntPtr new_gmeParseObj();

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_delete_gmeParseObj")]
  public static extern void delete_gmeParseObj(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_gmeParseObj_fillPoints")]
  public static extern void gmeParseObj_fillPoints(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_gmeParseObj_fillTriangles")]
  public static extern void gmeParseObj_fillTriangles(global::System.Runtime.InteropServices.HandleRef jarg1, global::System.Runtime.InteropServices.HandleRef jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_gmeParseObj_setObjName")]
  public static extern void gmeParseObj_setObjName(global::System.Runtime.InteropServices.HandleRef jarg1, string jarg2);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_gmeParseObj_getPointsNum")]
  public static extern int gmeParseObj_getPointsNum(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_gmeParseObj_getTrianglesNum")]
  public static extern int gmeParseObj_getTrianglesNum(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_gmeParseObj_getName")]
  public static extern string gmeParseObj_getName(global::System.Runtime.InteropServices.HandleRef jarg1);

  [global::System.Runtime.InteropServices.DllImport("SwigCplusplus", EntryPoint="CSharp_gmeParseObj_getBatchId")]
  public static extern global::System.IntPtr gmeParseObj_getBatchId(global::System.Runtime.InteropServices.HandleRef jarg1);
}
