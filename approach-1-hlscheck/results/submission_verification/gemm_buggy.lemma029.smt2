; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_11 () (_ BitVec 32))
(declare-fun arg1_13 () (_ BitVec 32))
(assert
 (let ((?x183 (bvmul arg0_11 arg1_7)))
(let ((?x11832 (bvmul (_ bv4294967295 32) ?x183)))
(let ((?x165 (bvmul arg0_11 arg1_13)))
(let ((?x8646 (bvadd ?x165 ?x11832)))
(and (distinct ?x8646 (_ bv0 32)) true))))))
(check-sat)
