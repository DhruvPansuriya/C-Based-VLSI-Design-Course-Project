; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x6348 ((_ extract 1 0) arg0_3)))
(let (($x479974 (= ?x6348 (_ bv3 2))))
(let ((?x82476 (ite $x479974 (_ bv1 32) (_ bv0 32))))
(let (($x438048 (= ?x6348 (_ bv2 2))))
(let ((?x73743 (ite $x438048 (_ bv1 32) (_ bv0 32))))
(let ((?x476058 (bvmul (_ bv4294967295 32) ?x73743)))
(let ((?x119090 (bvadd ?x476058 ?x82476)))
(and (distinct ?x119090 (_ bv0 32)) true)))))))))
(check-sat)
