; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_20 () (_ BitVec 32))
(declare-fun arg0_12 () (_ BitVec 32))
(declare-fun arg1_34 () (_ BitVec 32))
(assert
 (let ((?x63531 (bvmul arg0_12 arg1_20)))
(let ((?x66979 (bvmul (_ bv4294967295 32) ?x63531)))
(let ((?x45113 (bvmul arg0_12 arg1_34)))
(let ((?x60468 (bvadd ?x45113 ?x66979)))
(and (distinct ?x60468 (_ bv0 32)) true))))))
(check-sat)
