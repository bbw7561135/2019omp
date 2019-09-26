program pi_serial
    implicit none
    integer(kind=4), parameter :: num_steps = 1000000000
    integer(kind=4) :: i

    real(kind=8) :: x,pi,sum,step
    real(kind=8) :: start_time, end_time, used_time

    call cpu_time(start_time)

    step = 1.0/dble(num_steps) !dble is a fun to translate into double precision
    sum = 0.0

    do i=0,num_steps-1
        x = (dble(i)+0.5)*step
        sum=sum+4.0/(1.0+x*x)
    end do

    pi = step * sum

    call cpu_time(end_time)
    used_time = end_time - start_time

    write(*,*) 'used tims is',used_time
    write(*,*) 'calculated pi is', pi
    write(*,*) 'pi correct is 3.141592653589793'

end program
