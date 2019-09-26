program pi_parallel
    use omp_lib
    implicit none


    integer(kind=4), parameter :: num_steps = 1000000000
    integer(kind=4), parameter :: nthreads = 4
    integer(kind=4) :: i,tid

    real(kind=8) :: x,pi,step
    real(kind=8) :: start_time, end_time, used_time
    real(kind=8), dimension(0:nthreads-1) :: sum1

    start_time = omp_get_wtime()

    call omp_set_num_threads(nthreads)


    step = 1.0/dble(num_steps) !dble is a fun to translate into double precision
    pi = 0.0

    !$omp parallel private(x,i,tid) default(shared)
    tid = omp_get_thread_num()
    sum1(tid) = 0.0
    write(*,*) 'my id is',tid
    !$omp do
    do i=tid,num_steps-1
        x=(dble(i)+0.5)*step
        sum1(tid)=sum1(tid)+4.0/(1.0+x*x) //比串行慢的原因 数组
    end do
    !$omp end do
    !$omp end parallel

    do i=0,nthreads-1
        pi=pi+step*sum1(i)
    end do

    end_time = omp_get_wtime()
    used_time = end_time -start_time
    
    write(*,*) 'used tims is',used_time
    write(*,*) 'calculated pi is', pi
    write(*,*) 'pi correct is 3.141592653589793'

end program pi_parallel
