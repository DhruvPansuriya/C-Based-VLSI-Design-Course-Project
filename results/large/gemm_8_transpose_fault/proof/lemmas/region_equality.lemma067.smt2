; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_13 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg1_41 () (_ BitVec 32))
(assert
 (let ((?x39432 (bvmul arg0_13 arg1_13)))
(let ((?x62835 (bvmul (_ bv4294967295 32) ?x39432)))
(let ((?x63780 (bvmul arg0_13 arg1_41)))
(let ((?x53479 (bvadd ?x63780 ?x62835)))
(and (distinct ?x53479 (_ bv0 32)) true))))))
(check-sat)
