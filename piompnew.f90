program pi_parallel
    use omp_lib
    implicit none


    integer(kind=4), parameter :: num_steps = 1000000000
    integer(kind=4), parameter :: nthreads = 4
    integer(kind=4) :: i,tid

    real(kind=8) :: x,pi,step,tempsum
    real(kind=8) :: start_time, end_time, used_time
    real(kind=8), dimension(0:nthreads-1) :: sum1

    start_time = omp_get_wtime()

    call omp_set_num_threads(nthreads)


    step = 1.0/dble(num_steps) !dble is a fun to translate into double precision
    pi = 0.0

    !$omp parallel private(x,i,tid,tempsum) default(shared)
    tid = omp_get_thread_num()
    tempsum = 0.0
    sum1(tid) = 0.0
    write(*,*) 'my id is',tid
    !$omp do
    do i=0,num_steps-1
        x=(dble(i)+0.5)*step
        tempsum=tempsum+4.0/(1.0+x*x)
    end do
    !$omp end do
    sum1(tid) = tempsum
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
